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
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <signal.h>

#include <ncurses.h>

/***********************
 * Macros
***********************/

#define PORT 1032
#define LINE 1500
#define err(msg) {perror(msg);exit(0);}
#define S_A struct sockaddr*

