#include "header.h"

sem_t sem;
int var = 0;

void *thread1(void *);
void *thread2(void *);

int main(void)
{
    pthread_t th1;
    pthread_t th2;
    
    sem_init(&sem, 0, 1);

    pthread_create(&th1, NULL, &thread1, NULL);
    pthread_create(&th2, NULL, &thread2, NULL);

    pthread_exit(NULL);
}

void *thread1(void *ptr) {

    while (var < 200) {
        sem_wait(&sem);

        if (var % 2)
            printf("odd  - %d\n", var++);

        sem_post(&sem);
    }

    return NULL;
}

void *thread2(void *ptr) {

    while (var <= 200) {
        sem_wait(&sem);

        if (var % 2 == 0)
            printf("even - %d\n", var++);

        sem_post(&sem);
    }

    return NULL;
}
