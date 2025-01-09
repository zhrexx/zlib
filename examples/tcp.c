#include <stdio.h>
#include <stdbool.h>

#include "libs/net/inet.h"

void handle(int client_socket) {
    char buffer[1024];
    strcpy(buffer, "Hello from server!\n");

    send(client_socket, buffer, strlen(buffer), 0);
    bool running = true;
    while (running) {
        char buffer[1024];
        read(client_socket, &buffer, sizeof(buffer));

        if (strcmp(buffer, "exit") == 0) {
            running = false;
        } else {
            // Handle Client
            // In this case echo back to client
            send(client_socket, buffer, strlen(buffer), 0);
        }
    }

    return;
}


int main(int argc, char **argv) {
    simple_tcp_server(8080, handle);

    return 0;
}

