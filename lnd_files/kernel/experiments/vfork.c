#include <stdio.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid = vfork();

    printf("pid = %d\n", pid);
    printf("present pid = %d\n", getpid());
    getchar();
    return 0;
}
