#include <stdio.h>
#include <sys/types.h>

int main(void)
{
    pid = fork();// fork a new child process

if (pid < 0) // A check to see if fork() succeeded?
{
    printf("fork failed!\n");
    exit(1);
}

if (pid > 0)// its the parent process
{
    printf("pid of child process %d \n", pid);
    exit(0); //terminate the parent process succesfully
}

}
