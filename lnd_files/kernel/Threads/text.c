#include "header.h"

static void *
threadFunc(void *arg)
{
    char *s = (char *) arg;
    printf("%s", s);
    return (void *) strlen(s);
}

int
main(int argc, char *argv[])
{
    pthread_t t1;
    pthread_t t2;
    void *res;
    int s;
    /* Creating a thread */
    s = pthread_create(&t1, NULL, threadFunc, "Hello Global\n");
    if (s != 0) {
        printf("pthread_create failed\n");
        exit(EXIT_FAILURE);
    }
    
//    t2 = pthread_self();
//    printf("self -> %ld\n", (long) t2);

    s = pthread_detach(pthread_self());
    if (s != 0) {
        printf("pthread_detach failed\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Message from main()\n");
    
    s = pthread_join(t1, &res);
    if (s != 0) {
        printf("pthread_join failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Thread returned %ld\n", (long) res);
    exit(EXIT_SUCCESS);
}
