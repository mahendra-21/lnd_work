#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1();
void *thread2();

int count = 1;

void *thread2() {
    pthread_t th_id;
    
    if (0 != pthread_create(&th_id, NULL, thread1, NULL)) {
        printf("pthread_create failed in thread2\n");
        exit(EXIT_FAILURE);
    }
    
    printf("In thread -> 2 -> %d\n", count++);
}

void *thread1() {
    pthread_t th_id;
    
    if (0 != pthread_create(&th_id, NULL, thread2, NULL)) {
        printf("pthread_create failed in thread1\n");
        exit(EXIT_FAILURE);
    }
    
    pthread_join(th_id, NULL);
    printf("In thread -> 1 -> %d\n", count++);
}

int main(void)
{
    pthread_t th_id;
    
    if (0 != pthread_create(&th_id, NULL, thread1, NULL)) {
        printf("pthread_create failed in main\n");
        exit(EXIT_FAILURE);
    }

    if (0 != pthread_create(&th_id, NULL, thread2, NULL)) {
        printf("pthread_create failed in main\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(th_id, NULL);
    printf("In main -> %d\n", count++);
    pthread_exit(NULL);
}
