#include "header.h"

static int glob = 0;
static pthread_mutex_t mtx1 = PTHREAD_MUTEX_INITIALIZER;
static int avail = 0;

void *Thread_1( ) {
    
    if (0 != pthread_mutex_lock(&mtx1)) {
        printf("pthread_mutex_lock is failed\n");
        exit(EXIT_FAILURE);
    }
    if (0 == (glob % 2)) {
        printf("even ---> %d\n", glob);
    }
    avail++;
    
    if (0 != pthread_mutex_unlock(&mtx1)) {
        printf("pthread_mutex_lock is failed\n");
        exit(EXIT_FAILURE);
    }
    
}

void *Thread_2( ) {
    
    pthread_mutex_lock(&mtx1);    
    if (1 == (glob % 2)) {
        printf("odd -> %d\n", glob);
    }
    avail++;
    pthread_mutex_unlock(&mtx1);
    
}

int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <# of loops> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t th_id1;
    pthread_t th_id2;

    if (0 != pthread_create(&th_id1, NULL, Thread_1, NULL)) {
            printf("pthread_create is failed\n");
            exit(EXIT_FAILURE);
    }

    if (0 != pthread_create(&th_id2, NULL, Thread_2, NULL)) {
        printf("pthread_create is failed\n");
        exit(EXIT_FAILURE);
    }

    int loop = atoi(argv[1]);
    
    while (--loop) {
        pthread_mutex_lock(&mtx1);
        while (0 < avail) {
        glob++;
        avail--;
        }
        pthread_mutex_unlock(&mtx1);
   }

    pthread_exit(NULL);
}
