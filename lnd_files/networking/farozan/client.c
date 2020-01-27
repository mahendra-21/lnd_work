#include "header.h"

int main (void)
{
    // Declaration and definition
    int fd;
    int n;
    int bytesToRecv;
    char sendBuffer [256];
    char recvBuffer [256];
    char* movePtr;
    struct sockaddr_in serverAddr;
    // Socket descriptor
    // Number of bytes received
    // Number of bytes to receive
    // Send buffer
    // Receive buffer
    // A pointer the received buffer
    // Server address
    // Create socket
    fd = socket (PF_INET, SOCK_STREAM, 0);
    // Create server socket address
    memset (&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
/*    inet_pton (AF_INET, "172.16.5.127", &serverAddr.sin_addr);
    serverAddr.sin_port = htons (7); // We assume port 7
  */  // Connect
    connect (fd, (struct sockaddr*) &serverAddr, sizeof(serverAddr));
    // Send and receive data
    printf("Enter data: ");
    fgets (sendBuffer, 256, stdin);
    send (fd, sendBuffer, strlen (sendBuffer), 0);
    bytesToRecv = strlen (sendBuffer);

    movePtr = recvBuffer;
    while ((n = recv (fd, movePtr, bytesToRecv, 0)) > 0)
    {
        movePtr = movePtr + n;
        bytesToRecv = bytesToRecv - n;
    } // End of while loop

    recvBuffer[bytesToRecv] = 0;
    printf ("Received from server:");
    fputs (recvBuffer, stdout);

    // Close and exit
    close (fd);
    exit (0);
 } // End of echo client program
