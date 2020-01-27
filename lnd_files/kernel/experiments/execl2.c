#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    printf("pid -> %d\n", getpid());

    pid_t cpid = fork();
    
    execl(argv[0], argv[0], (char *)NULL);

    if (cpid == 0) {
        printf("In child -> %d  pid -> %d\n", getpid(), cpid);
        getchar();
    } else {
        printf("IN parent -> %d pid -> %d\n", getpid(), cpid);
    }

//    return 0;
}
