#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
   
void *thread1(void *);
void *thread2(void *);
void *thread3(void *);

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int condition = 2;
int glob = 0;

int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t th_id1;
    pthread_t th_id2;
    pthread_t th_id3;

    int status;
    int no_times = atoi(argv[1]);

    status = pthread_create(&th_id1, NULL, thread1, &no_times);
    if (0 != status) {
        printf("pthread_create -> %s\n", (char *)strerror(status));
        exit(EXIT_FAILURE);
    }

    status = pthread_create(&th_id2, NULL, thread2, &no_times);
    if (0 != status) {
        printf("pthread_create -> %s\n", (char *)strerror(status));
        exit(EXIT_FAILURE);
    }
    
    status = pthread_create(&th_id3, NULL, thread3, &no_times);
    if (0 != status) {
        printf("pthread_create -> %s\n", (char *)strerror(status));
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
}

void *thread1(void *ptr) {

    while ((int)*(int *)ptr != glob) {
        pthread_mutex_lock(&mtx);

        while (0 != condition) 
                pthread_cond_wait(&cond, &mtx);

        printf("even\t-> %d\n", glob);

        if ((int)*(int *)ptr == glob)
            break;
        else
            condition = 2;

        pthread_mutex_unlock(&mtx);
        pthread_cond_broadcast(&cond);
    }

    return NULL;
}

void *thread2(void *ptr) {

    while ((int)*(int *)ptr != glob) {
        pthread_mutex_lock(&mtx);

        while (1 != condition) 
            pthread_cond_wait(&cond, &mtx);

        printf("odd\t-> %d\n", glob);

        if ((int)*(int *)ptr == glob)
            break;
        else
        condition = 2;

        pthread_mutex_unlock(&mtx);
        pthread_cond_broadcast(&cond);
    }
    
    return NULL;
}

void *thread3(void *ptr) {

    while ((int)*(int *)ptr != glob) {
        pthread_mutex_lock(&mtx);

        while (2 != condition)
            pthread_cond_wait(&cond, &mtx);

        glob++;

        if (glob % 2)
            condition = 1;
        else
            condition = 0;

        pthread_mutex_unlock(&mtx);
        pthread_cond_broadcast(&cond);
    }

    return NULL;
}
