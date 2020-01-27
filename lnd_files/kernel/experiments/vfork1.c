#include <stdio.h>
#include <sys/types.h>

int var = 7;

int main(void)
{
    pid_t pid = vfork();

    if (pid == 0) {
        printf("IN CHAILD PROCESS\n");
        printf("var = %d\n", var);
        var = 14;
    } else {
        printf("IN PARENT PROCESS\n");
        printf("var = %d\n", var);
        var = 21;
        getchar();
    }

    return 0;
}
