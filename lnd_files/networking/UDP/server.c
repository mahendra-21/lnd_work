#include "header.h"

int main(void)
{
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

    for(; ;) {
        printf("Waiting for client..!\n");

        if (-1 == recvfrom(sock_fd, str, BUFF_LEN, 0, 
                    (struct sockaddr *) &clientAddr, &clientAddelen))
            handle_error("recvfrom");
        printf("\t\t\t\tIn server -> %s\n", str);

        printf("Enter data: ");
        if (NULL == fgets(str, BUFF_LEN, stdin))
            handle_error("fgets");
        __fpurge(stdin);

        char *temp = str;
        while (*temp) {
            if ('\n' == *temp)
                *temp = *(temp + 1);
            temp++;
        }

        if (-1 == sendto(sock_fd, str, BUFF_LEN, 0,
                  (struct sockaddr *) &clientAddr, clientAddelen))
            handle_error("sendto");
        
        memset(str, 0, BUFF_LEN);
    }

    close(sock_fd);
    return 0;
}
