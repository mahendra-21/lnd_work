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

    struct sockaddr_in clientAddr;

    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sock_fd)
        handle_error("socket");

    memset(&clientAddr, 0, sizeof(clientAddr));

    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(1500);
    clientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    clientAddelen = sizeof(clientAddr);
    memset(str, 0, BUFF_LEN);

    fd = open(argv[1], O_RDONLY | O_APPEND);
    if (-1 == fd)
        handle_error("open");

    for(; ;) {
        size = read(fd, str, 127);
        printf("size -> %d\n", (int) size);
        if (-1 == size)
            handle_error("read");
        if (0 == size)  break;
        
        if (-1 == sendto(sock_fd, str, sizeof(str), 0,
                  (struct sockaddr *) &clientAddr, clientAddelen))
            handle_error("sendto");
        
        memset(str, 0, BUFF_LEN);
    }

    close(sock_fd);
    return 0;
}
