#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int condition = 3;

void *thread1(void *);
void *thread2(void *);
void *thread3(void *);

int main(void)
{
    pthread_t th_id;

    int status1;
    int status2;
    int status3;

        status1 = pthread_create(&th_id, NULL, thread1, NULL);
        if (0 != status1) {
            printf("error -> %s\n", (char *) status1);
            exit(EXIT_FAILURE);
        }
        
        status2 = pthread_create(&th_id, NULL, thread2, NULL);
        if (0 != status2) {
            printf("error -> %s\n", (char *) status2);
            exit(EXIT_FAILURE);
        }

        status3 = pthread_create(&th_id, NULL, thread3, NULL);
        if (0 != status3) {
            printf("error -> %s\n", (char *) status3);
            exit(EXIT_FAILURE);
        }

        pthread_exit(NULL);
}

void *thread1(void *ptr) {
    pthread_mutex_lock(&mtx);

    if (1 != condition)
        pthread_cond_wait(&cond, &mtx);
    
    printf("In thread -> 1\n");
    condition++;
    
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mtx);
    pthread_exit(NULL);
}

void *thread2(void *ptr) {
    pthread_mutex_lock(&mtx);

    if (2 != condition)
        pthread_cond_wait(&cond, &mtx);
    
    printf("In thread -> 2\n");
    condition++;
    
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mtx);
    pthread_exit(NULL);
}

void *thread3(void *ptr) {
    pthread_mutex_lock(&mtx);

    if (3 != condition)
        pthread_cond_wait(&cond, &mtx);
    
    printf("In thread -> 3\n");
    condition++;
    
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mtx);
    pthread_exit(NULL);
}
