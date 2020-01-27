#include "header.h"


int var = 10;

void *thread_fun()
{
    pid_t tid;
    tid = syscall(SYS_gettid);
    printf("In thread function\n");
    printf("Thread PID -> %d\n", tid);
   
    tid = syscall(SYS_tgkill, getpid(), tid, SIGHUP);
    printf("Thread PID -> %d\n", tid);
    var += 10;
}

int main(void)
{
    /* Provides a handle for further operations on threades */
    pthread_t th_id;
    int status;

    status = pthread_create(&th_id, NULL, thread_fun, NULL);
    printf("status -> %d\n", status);
    if (0 != status) {
        printf("Thread is not created\n");
        exit(EXIT_FAILURE);
    }
    
    printf("PID -> %d\n", getpid());
    getchar();
    printf("var -> %d\n", var);
    pthread_exit(NULL);
}
