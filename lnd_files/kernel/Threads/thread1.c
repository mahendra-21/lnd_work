#include "header.h"

void *func1(void *var)
{
    int loop;
    for (loop = 1; loop <= 10; loop++)
        printf("loop -> %d\n", loop);
    pthread_exit(NULL);
}

void *func2(void *var)
{
    int loop;
    for (loop = 11; loop <= 20; loop++)
        printf("loop -> %d\n", loop);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t th_id;
    int status;

    status = pthread_create(&th_id, NULL, func1, NULL);
    if (0 != status) {
        printf("pthread_create failed\n");
        exit(EXIT_FAILURE);
    }
    
    status = pthread_create(&th_id, NULL, func2, NULL);
    if (0 != status) {
        printf("pthread_create failed\n");
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
}
