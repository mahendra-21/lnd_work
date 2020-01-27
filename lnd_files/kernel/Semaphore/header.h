/* header.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFF_LEN 1024
#define handle_err(msg) \
    do { perror(msg);  \
    exit(EXIT_FAILURE); } while (0)
