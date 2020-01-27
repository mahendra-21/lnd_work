#include <stdio.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid = fork();

    if (pid > 0) {
 //       wait();
        printf("pid = %d    get_pid = %d\n", pid, getpid());
    } else {
        wait(NULL);
        printf("pid = %d    get_pid = %d\n", pid, getpid());
        getchar();
    }
    return 0;
}
