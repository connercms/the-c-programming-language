#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include "./network.h"

/**
 * AF_INET = Address Family: Internet
 */

int main()
{
    // 1. Create the socket
    /**
     * Returns a file descriptor for the new socket,
     * or -1 for errors.
     */
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;
    int server_fd;

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (server_fd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Bind the socket to an IP address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    /**
     * htons: host to network short
     * converts the port number to be stored big endian.
     * that is, the MSB first
     *  */
    server_addr.sin_port = htons(serverport);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("[+] Listening on port %d...\n", serverport);

    // 5. Receive the client's message and send it back
    int LOOP = 1;
    while (LOOP)
    {
        memset(&buffer, 0, 1024);
        socklen_t addr_size = sizeof(client_addr);
        memset(&client_addr, 0, sizeof(addr_size));

        int n = recvfrom(server_fd,
                         buffer,
                         1024,
                         0,
                         (struct sockaddr *)&client_addr,
                         &addr_size);

        if (n < 0)
        {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        printf("[+] Data received: %s\n", buffer);

        memset(&buffer, 0, 1024);
        strcpy(buffer, "Pong");

        sendto(server_fd,
               buffer,
               1024,
               0,
               (struct sockaddr *)&client_addr,
               sizeof(client_addr));

        printf("[+] Data sent: %s\n", buffer);
    }

    close(server_fd);

    return EXIT_SUCCESS;
}