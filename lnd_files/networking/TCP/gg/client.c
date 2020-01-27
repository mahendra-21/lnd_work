#include <stdio.h> 
#include <stdlib.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

int main(void) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 

    char buffer[1024] = {0}; 
    char *hello = (char *) malloc(1024 * sizeof(char));
    if (NULL == hello) {
        printf("malloc failed\n");
        return 0;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT);
//    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 


    while (1) {
        printf("Enter msg: ");
        fgets(hello, 1024, stdin);
        __fpurge(stdin);

        char *temp = hello;

        while (*temp) {
            if ('\n' == *temp)
                *temp = *(temp + 1);
            temp++;
        }

        send(sock , hello , strlen(hello) + 1, 0 ); 

        valread = read( sock , buffer, 1024); 
        printf("%s\n",buffer ); 
    }

    close(sock);
    return 0; 
}
