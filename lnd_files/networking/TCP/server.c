#include "header.h"

int main(void)
{
    char arr[127]; 
    int sock_fd; // session descriptor for server
    int sock_accept; // session descriptor for client 
    socklen_t clientAddrlen;

    struct sockaddr_in  ipOfserver; // For server IP_Addr.
    struct sockaddr_in  ipOfclient; // For client IP_Addr.

    /* Creating a socket/session */
    /* AF_INET -> IPV4(Domain name)
     * SOCK_STREAM -> Type which specifies communication semantics
     */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sock_fd) {
        handle_error("socket");
    }

    memset(&ipOfserver, 0, sizeof(ipOfserver));

    /* Assigning a name to a socket */
    ipOfserver.sin_family = AF_INET;
    ipOfserver.sin_port = htons(3000);
    ipOfserver.sin_addr.s_addr = INADDR_ANY; 
                                /* Addr to accept any incoming msg's */

    /* Bind a name to a socket */
    if (-1 == bind(sock_fd, (struct sockaddr *) &ipOfserver, 
                sizeof(ipOfserver)))
        handle_error("bind");

    /* Listen for connections on a socket */
    if (-1 == listen(sock_fd, 2))
        handle_error("listen");

    clientAddrlen = sizeof(ipOfclient);

    /* Accept a connection on a socket */
    sock_accept = accept(sock_fd, (struct sockaddr *) &ipOfclient, 
            &clientAddrlen);
    if (-1 == sock_accept)
        handle_error("accept");

    while (1) {
        printf("Waiting for client.....!\n");
       /* Reading data from the client */  
        if (-1 == read(sock_accept, arr, sizeof(arr)))
            handle_error("read");

        printf("\t\t\t\tIn server -> %s\n", arr);

        printf("Enter data: ");
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

        /* writing data to client */
        if (-1 == write(sock_accept, arr, sizeof(arr)))
            handle_error("write");
    }
    
    close(sock_fd);
    return 0;
}
