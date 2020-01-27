#include "header.h"

static unsigned long long int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *             /* Loop 'arg' times incrementing 'glob' */
threadFunc(void *arg)
{
    unsigned long long int loops = *((unsigned long long int *) arg);
    unsigned long long int loc, j;

    for (j = 0; j < loops; j++) {

        if (0 != pthread_mutex_lock(&mtx)) {
            printf("pthread_mutex_lock failed\n");
            exit(EXIT_FAILURE);
        }

        loc = glob;
        loc++;
        glob = loc;

        if (0 != pthread_mutex_unlock(&mtx)) {
            printf("pthread_mutex_unlock failed\n");
            exit(EXIT_FAILURE);
        }
    }

    return NULL;
}

int
main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <loop> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t t1, t2;
    unsigned long long int loops, s;
    loops = (unsigned long long) atoi(argv[1]);
    /* Craeting thread ->  1 */
    s = pthread_create(&t1, NULL, threadFunc, &loops);
    if (s != 0) {
        printf("Usage: %s <loop> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /* Craeting thread ->  2 */
    s = pthread_create(&t2, NULL, threadFunc, &loops);
    if (s != 0) {
        printf("Usage: %s <loop> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    s = pthread_join(t1, NULL);
    if (s != 0) {
        printf("Usage: %s <loop> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    s = pthread_join(t2, NULL);
    if (s != 0) {
        printf("Usage: %s <loop> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("glob = %llu\n", glob);
    exit(EXIT_SUCCESS);
}
