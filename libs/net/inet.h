#ifndef INET_H
#define INET_H
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Custom htons implementation
uint16_t ihtons(uint16_t hostshort) {
    uint16_t test = 0x1;
    uint8_t *byte = (uint8_t *)&test;
    if (*byte == 0x1) {
        return (hostshort << 8) | (hostshort >> 8);
    }
    return hostshort;
}

uint16_t intons(uint16_t hostshort) {
    uint16_t test = 0x1;
    uint8_t *byte = (uint8_t *)&test;
    if (*byte == 0x1) {
        return (hostshort >> 8) | (hostshort << 8);
    }
    return hostshort;
}


// func(int client_socket)
int simple_tcp_server(int port, void (*func)(int)) {
    int server_fd, client_socket;
    struct sockaddr_in server_addr;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = ihtons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", port);

    while (1) {
        if ((client_socket = accept(server_fd, NULL, NULL)) < 0) {
            perror("accept");
            continue;
        }

        pid_t pid = fork();
        if (pid == 0) {
            close(server_fd);
            func(client_socket);
            exit(0);
        } else if (pid > 0) {
            close(client_socket);
        } else {
            perror("fork");
        }
    }

    close(server_fd);
    return 0;

}

ssize_t tcp_send(int sock, const void *buffer, size_t length) {
    ssize_t sent = send(sock, buffer, length, 0);
    if (sent == -1) {
        perror("send");
    }
    return sent;
}

ssize_t tcp_receive(int sock, void *buffer, size_t length) {
    ssize_t received = recv(sock, buffer, length, 0);
    if (received == -1) {
        perror("recv");
    }
    return received;
}


void close_socket(int sock) {
    if (close(sock) == -1) {
        perror("close");
    }
}

// Function to pass in simple_tcp_server
void simple_echo_handler(int client_socket) {
    char buffer[1024];
    ssize_t bytes_received;

    while ((bytes_received = tcp_receive(client_socket, buffer, sizeof(buffer))) > 0) {
        printf("Received: %s\n", buffer);
        tcp_send(client_socket, buffer, bytes_received);
    }

    if (bytes_received == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("Error receiving data");
    }

    close_socket(client_socket);
}




#endif // INET_H



