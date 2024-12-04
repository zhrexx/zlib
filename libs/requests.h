// ========================================================================================>
// ZHRXXgroup Project 🚀 - ZLib
// File: requests.h
// Author(s): ZHRXXgroup
// Version: 1
// ========================================================================================>
// IMPORTANT This File is Experimental and May Contain Bugs
// ========================================================================================>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *status_line;
    char *headers;
    char *body;
} HttpResponse;

char* trim_body(const char* body) {
    const char *start = body;
    while (*start == '\n' || *start == ' ') start++;

    const char *end = start + strlen(start) - 1;
    while (end > start && (*end == '\n' || *end == ' ')) end--;

    size_t body_len = end - start + 1;

    char *trimmed = malloc(body_len + 1);
    if (trimmed) {
        strncpy(trimmed, start, body_len);
        trimmed[body_len] = '\0';
    } else {
        return NULL;
    }

    char *first_line_end = strchr(trimmed, '\n');
    if (first_line_end) {
        char *second_line_start = first_line_end + 1;
        char *last_line_start = strrchr(trimmed, '\n');

        if (last_line_start) {
            size_t result_len = last_line_start - second_line_start;
            if (result_len > 0) {
                char *result = malloc(result_len + 1);
                if (result) {
                    strncpy(result, second_line_start, result_len);
                    result[result_len] = '\0';
                }
                free(trimmed);
                return result;
            }
        }
    }

    free(trimmed);
    return NULL;
}

HttpResponse *http_get(const char *host, const char *path) {
    struct addrinfo hints, *res;
    int sockfd;
    char buffer[BUFFER_SIZE];
    char request[1024];
    HttpResponse *response = malloc(sizeof(HttpResponse));
    if (!response) return NULL;

    response->status_line = NULL;
    response->headers = NULL;
    response->body = NULL;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, "80", &hints, &res) != 0) {
        perror("getaddrinfo");
        free(response);
        return NULL;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(res);
        free(response);
        return NULL;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        close(sockfd);
        freeaddrinfo(res);
        free(response);
        return NULL;
    }

    freeaddrinfo(res);

    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        close(sockfd);
        free(response);
        return NULL;
    }

    char *response_data = NULL;
    size_t response_size = 0;
    ssize_t bytes_received;

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        response_data = realloc(response_data, response_size + bytes_received + 1);
        if (!response_data) {
            perror("realloc");
            close(sockfd);
            free(response);
            return NULL;
        }
        memcpy(response_data + response_size, buffer, bytes_received + 1);
        response_size += bytes_received;
    }

    if (bytes_received == -1) {
        perror("recv");
        close(sockfd);
        free(response);
        free(response_data);
        return NULL;
    }

    close(sockfd);

    char *headers_end = strstr(response_data, "\r\n\r\n");
    if (headers_end) {
        *headers_end = '\0';
        response->headers = strdup(response_data);
        response->body = strdup(headers_end + 4);
    } else {
        response->body = strdup(response_data);
    }

    free(response_data);

    if (response->body) {
        char *clean_body = trim_body(response->body);
        free(response->body);
        response->body = clean_body;
    }

    return response;
}

void free_http_response(HttpResponse *response) {
    if (response) {
        free(response->status_line);
        free(response->headers);
        free(response->body);
        free(response);
    }
}