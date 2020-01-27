#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/*
   void *thread1(void *);
   void *thread2(void *);
 */
void *thread(void *);

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int condition = 0;
int glob = 0;

int main(void)
{
    pthread_t th_id1;
    pthread_t th_id2;

    int status;
    int n1 = 0;
    int n2 = 1;

    status = pthread_create(&th_id1, NULL, thread, &n1);
    if (0 != status) {
        printf("pthread_create -> %s\n", (char *)strerror(status));
        exit(EXIT_FAILURE);
    }

    status = pthread_create(&th_id2, NULL, thread, &n2);
    if (0 != status) {
        printf("pthread_create -> %s\n", (char *)strerror(status));
        exit(EXIT_FAILURE);
    }

    if (0 != (status = pthread_join(th_id1, NULL))) {
        printf("pthread_create -> %s\n", (char *)strerror(status));
        exit(EXIT_FAILURE);
    }
    
    if (0 != (status = pthread_join(th_id2, NULL))) {
        printf("pthread_create -> %s\n", (char *)strerror(status));
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
}

void *thread(void *ptr) {
 //   static int loop = 1;

    while (100 > glob) {

        pthread_mutex_lock(&mtx); // Aquiring lock

        if (condition != (int)*(int *)ptr) {
            if (0 == (int)*(int *)ptr)
                pthread_cond_wait(&cond, &mtx);
            else
                pthread_cond_wait(&cond, &mtx);
        }

        if (glob % 2)
            printf("odd -> %d\n", glob++);
        else
            printf("even --> %d\n", glob++);
        
        if (condition == 0) {
            condition = 1;
            pthread_cond_signal(&cond);
        } else {
            condition = 0;
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&mtx);
    }

    pthread_exit(NULL);
}

/*
void *thread1(void *ptr) {
    static int var1 = 0;

    while (11 != (var1++)) {
        pthread_mutex_lock(&mtx);

        if (1 != condition)
            pthread_cond_wait(&cond, &mtx);

        printf("even\t-> %d\n", glob++);
        var1++;
        condition--;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(NULL);
}

void *thread2(void *ptr) {
    static int var = 0;

    while (11 != (var++)) {
        pthread_mutex_lock(&mtx);

        if (0 != condition)
            pthread_cond_wait(&cond, &mtx);

        printf("odd\t-> %d\n", glob++);
        var++;
        condition--;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(NULL);
}
*/
