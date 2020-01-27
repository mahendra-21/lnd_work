/* header.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/scoket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#undef max
#define max(x,y) ((x) > (y) ? (x) : (y))

#define handle_err(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

#define BUF_SIZE 1024
