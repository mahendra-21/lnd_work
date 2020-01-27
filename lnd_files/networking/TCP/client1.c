#include "header.h"

int main(void)
{
    char arr[127]; 
    int sock_fd; // session descriptor for socket
    unsigned int len;

    struct sockaddr_in  ipOfclient; // For client IP

    /* Creating a socket/session */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sock_fd) {
        handle_error("socket");
    }

    /* Assigning a name to a socket */
    ipOfclient.sin_family = AF_INET;
    ipOfclient.sin_port = htons(2500);

    // Convert IPv4 and IPv6 addresses from text to binary form 
    if (inet_pton(AF_INET, "172.16.5.134", &ipOfclient.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    len = sizeof(ipOfclient);
    /* initiating a connection on a socket */
    if (-1 == connect(sock_fd, (struct sockaddr *) &ipOfclient, len)) {
        handle_error("connect");
    }

    while (1) {
        printf("Enter the data: ");
        if (NULL == fgets(arr, 127, stdin)) {
            handle_error("fgets");
        }
        __fpurge(stdin);

        char *temp = arr;
        while (*temp) {
            if ('\n' == *temp)
                *temp = *(temp + 1);
            temp++;
        }

        /* Writing data to server */
        if (-1 == write(sock_fd, arr, strlen(arr) + 1)) {
            handle_error("write");
        }

        printf("Waiting for server....!\n");
        /* Reading data from the server */  
        if (-1 == read(sock_fd, arr, sizeof(arr))) {
            handle_error("read");
        }
        printf("\t\t\t\tIn client -> %s\n", arr);
    }
    close(sock_fd);
    return 0;
}
