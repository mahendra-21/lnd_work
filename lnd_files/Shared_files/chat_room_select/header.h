/*********************
 * Headers
*********************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <mqueue.h>
#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <sys/select.h>

#include <ncurses.h>

/***********************
 * Macros
***********************/

#define PORT 1032
#define LINE 128
#define err(msg) {perror(msg);exit(0);}
#define S_A struct sockaddr*

