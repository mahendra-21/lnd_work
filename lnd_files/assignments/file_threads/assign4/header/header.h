#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define SIZE 127
#define handle_err(msg)    \
    do { perror(msg);   exit(EXIT_FAILURE); } while(0)

void *thread_fun(void *sync);
