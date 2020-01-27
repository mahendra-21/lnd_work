#include "header.h"

int main (void)
{
    // Declaration and definition
    int listensd;    // Listen socket descriptor
    int connectsd;   // Connecting socket descriptor
    int n;           // Number of bytes in each reception
    int bytesToRecv; // Total bytes to receive
    int processID;   // ID of the child process
    char buffer [256];  // Data buffer
    char* movePtr;    // Pointer to the buffer
    struct sockaddr_in serverAddr;    // Server address
    struct sockaddr_in clientAddr;    // Client address
    int clAddrLen;    // Length of client address

    // Create listen socket
    listensd = socket (PF_INET, SOCK_STREAM, 0);

    // Bind listen socket to the local address and port
    memset (&serverAddr, 0, sizeof (serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl (INADDR_ANY);
    serverAddr.sin_port = htons (7); // We assume port 7

    bind (listensd, (struct sockaddr *) &serverAddr, sizeof (serverAddr));
    // Listen to connection requests
    listen (listensd, 5);   // Handle the connection

    for ( ; ; )  // Run forever
    {
        connectsd = accept (listensd, (struct sockaddr *) &clientAddr, &clAddrLen);
        processID = fork ();
        if (processID == 0)          // Child process
        {
            close (listensd);
            bytesToRecv = 256;
            movePtr = buffer;
            while ((n = recv (connectsd, movePtr, bytesToRecv, 0)) > 0)
            {
                movePtr = movePtr + n;
                bytesToRecv = (int)movePtr - n;
            } // End of while
            send (connectsd, buffer, 256, 0);
            exit (0);

        } // End of if

        close (connectsd);
   } // End of for loop

 } // End of echo server program
    //Back to parent process
