#include "header.h"

static int glob = 0;

static void *             /* Loop 'arg' times incrementing 'glob' */
threadFunc(void *arg)
{
    int loops = *((int *) arg);
    int loc, j;
    for (j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
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
    int loops, s;
    loops = atoi(argv[1]);
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

    printf("glob = %d\n", glob);
    exit(EXIT_SUCCESS);
}
