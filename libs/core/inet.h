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




#endif // INET_H



