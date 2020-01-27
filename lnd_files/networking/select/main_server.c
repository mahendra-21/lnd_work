#include "header.h"

int main(int argc, char *argv[])
{
    struct sockaddr_in sock;
    int tfd;
    int ufd;

    if (-1 == (tfd = socket(AF_INET, SOCK_STREAM, 0)))
        handle_err("socket");
    
    sock.sin_family = AF_INET;
    sock.sin_port = htons(51500);
    sock.sin_addr.s_addr = INADDR_ANY;

    bind
