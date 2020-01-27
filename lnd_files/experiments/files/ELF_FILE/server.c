#include "header.h"

int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd;
    size_t size;
    char str[BUFF_LEN];
    int sock_fd;
    socklen_t clientAddelen;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sock_fd)
        handle_error("socket");

    memset(&serverAddr, 0, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1500);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (-1 == bind(sock_fd, (struct sockaddr *) &serverAddr,
                sizeof(serverAddr)))
        handle_error("bind");

    clientAddelen = sizeof(clientAddr);
    memset(str, 0, BUFF_LEN);

    fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, 0664);
    if (-1 == fd)
        handle_error("open");

    if (-1 == (size = recvfrom(sock_fd, str, BUFF_LEN, 0, 
                    (struct sockaddr *) &clientAddr, &clientAddelen)))
        handle_error("recvfrom");
    printf("size -> %d\n", (int) size);

    if (-1 == write(fd, str, size))
        handle_error("write");

    memset(str, 0, BUFF_LEN);

    if (-1 == close(fd))
        handle_error("close");

    close(sock_fd);
    return 0;
}