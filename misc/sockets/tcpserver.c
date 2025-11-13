#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "./network.h"

int main()
{
    struct sockaddr_in server_addr, client_addr;
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    char buffer[1024];

    if (server_fd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(serverport);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // 3. Listen for connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // memset(&client_addr, 0, sizeof(client_addr));
    memset(&server_addr, 0, sizeof(server_addr));
    socklen_t addr_size = sizeof(server_addr);
    int socketfd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
    memset(&buffer, 0, 1024);
    recv(socketfd, buffer, 1024, 0);
    // recvfrom(server_fd, buffer, 1024, 0, (struct sockaddr *)&server_addr, &addr_size);

    printf("[+] Received data: %s\n", buffer);

    char message[] = "Hello from server";
    memset(&buffer, 0, 1024);
    strcpy(buffer, message);
    printf("[>] Sending data: %s\n", message);
    sendto(socketfd, buffer, 1024, 0, (struct sockaddr *)&client_addr, addr_size);

    close(server_fd);

    return EXIT_SUCCESS;
}