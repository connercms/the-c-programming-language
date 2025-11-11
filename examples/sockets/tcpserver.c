#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

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
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Bind the socket to an IP address and port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    /**
     * htons: host to network short
     * converts the port number to be stored big endian.
     * that is, the MSB first
     *  */
    address.sin_port = htons(12000);

    int addrlen = sizeof(address);

    if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0)
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

    // 4. Accept a client connection
    int new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);

    if (new_socket < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // 5. Receive the client's message and send it back
    char buffer[1024] = {0};
    int val = read(new_socket, buffer, 1024);
    printf("Client %s\n", buffer);
    send(new_socket, buffer, strlen(buffer), 0);

    // Close the socket connection
    close(new_socket);
    close(server_fd);

    return EXIT_SUCCESS;
}