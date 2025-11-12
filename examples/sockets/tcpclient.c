#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "./network.h"

int main()
{
    char buffer[1024];
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = IN_LOOPBACKNET;
    server_addr.sin_port = htons(serverport);

    if (connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connect failed");
        exit(EXIT_FAILURE);
    }

    char message[] = "Hello from client";
    memset(&buffer, 0, 1024);
    strcpy(buffer, message);
    printf("[>] Sending data: %s\n", buffer);

    sendto(socketfd, buffer, 1024, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    socklen_t addr_size = sizeof(server_addr);
    memset(&buffer, 0, 1024);
    recvfrom(socketfd, buffer, 1024, 0, (struct sockaddr *)&server_addr, &addr_size);

    printf("[+] Data received: %s\n", buffer);

    close(socketfd);
}