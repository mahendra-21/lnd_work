#include "header.h"

sem_t sem1;
sem_t sem2;
int var = 0;

void *thread1(void *);
void *thread2(void *);
int         help;

int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <#_up_to> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t   th1;
    pthread_t   th2;
    
    help = atoi(argv[1]);

    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);

    pthread_create(&th1, NULL, &thread1, &help);
    pthread_create(&th2, NULL, &thread2, &help);

    pthread_exit(NULL);
}

void *thread1(void *ptr) {

    int *h = ptr;

    while (var < *h) {
        sem_wait(&sem2);

        if (var % 2)
            printf("odd  - %d\n", var++);

        sem_post(&sem1);
    }

    return NULL;
}

void *thread2(void *ptr) {

    int *h = ptr;

    while (var < *h) {
        sem_wait(&sem1);

        if (var % 2 == 0)
            printf("even - %d\n", var++);

        sem_post(&sem2);
    }

    return NULL;
}
