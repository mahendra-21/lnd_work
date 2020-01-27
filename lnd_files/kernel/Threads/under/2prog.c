#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread(void *str) {
    printf("In thread -> %s\n", (char *) str);
    pthread_exit("byee");
}

int main(void)
{
    pthread_t th_id;
    void *str;

    if (0 != pthread_create(&th_id, NULL, thread, "hello")) {
        printf("pthread_create failed in main\n");
        exit(EXIT_FAILURE);
    }

    if (0 != pthread_join(th_id, &str)) {
        printf("pthread_join failed in main\n");
        exit(EXIT_FAILURE);
    }

    printf("In main -> %s\n", (char *) str);
    pthread_exit(NULL);
}
