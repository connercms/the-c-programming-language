#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "./network.h"

int main()
{
    struct sockaddr_in addr;
    char buffer[1024];
    int socket_fd;

    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (socket_fd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(serverport);
    addr.sin_addr.s_addr = INADDR_ANY;

    memset(&buffer, 0, 1024);
    strcpy(buffer, "Ping");

    int sent = sendto(socket_fd,
                      buffer,
                      1024,
                      0,
                      (struct sockaddr *)&addr,
                      sizeof(addr));

    printf("[+] Data sent: %s\n", buffer);

    memset(&buffer, 0, 1024);
    socklen_t addr_size = sizeof(addr);

    recvfrom(socket_fd,
             buffer,
             sizeof(buffer),
             0,
             (struct sockaddr *)&addr,
             &addr_size);

    printf("[+] Data received: %s\n", buffer);

    return 0;
}