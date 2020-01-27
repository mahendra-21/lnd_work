#include "header.h"

char *str;
char *buff;

sem_t sem1; // semaphore variable
//sem_t sem2; // semaphore variable

int temp = 0;

void *write_msg(void *); /* Prototypes for read & write functions */
void *read_msg(void *);

int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <#_of_times>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t th1; /* Taking two thread handlers for two threads */
    pthread_t th2;

    int count = atoi(argv[1]);
    /* Allocating memory dynamically to str */
    if (NULL == (str = (char *) malloc(BUFF_LEN * sizeof(char))))
       handle_err("malloc");
    /* Initializing the semaphore */
    if (-1 == sem_init(&sem1, 0, 1))
        handle_err("sem_init");
//    if (-1 == sem_init(&sem2, 0, 1))
//        hande_err("sem_init");
    /* Creating two threads */
    if (0 != pthread_create(&th1, NULL, write_msg, &count))
        handle_err("pthread_create");
    
    if (0 != pthread_create(&th2, NULL, read_msg, &count))
        handle_err("pthread_create");

    pthread_exit(NULL); /* Wait until threads complete's thier job */
}

void *read_msg(void *loop) {

    while ((int)*(int *)loop > temp) {
//    while (1) {
        if (-1 == sem_wait(&sem1))
            handle_err("sem_wait");

        printf("Enter the data: ");
        fgets(str, BUFF_LEN, stdin);
//        __fpurge(stdin);
        temp++;

        if (-1 == sem_post(&sem1))
            handle_err("sem_post");
    }

    return NULL;
}

void *write_msg(void *loop) {

    while ((int)*(int *)loop > temp) {
//    while (1) {

        if (-1 == sem_wait(&sem1))
            handle_err("sem_wait");

        printf("msg -> %s\n", str);
        
        if (-1 == sem_post(&sem1))
            handle_err("sem_post");
    }

    return NULL;
}
