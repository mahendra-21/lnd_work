#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid; 
    pid = fork();
    
    if (0 == pid) {
        sleep(2);
        printf("child pid = %d      pid = %d\n", getpid(), pid);        
        getchar();
    } else {
        printf("parent pid = %d     pid  =%d\n", getpid(), pid);        
        getchar();
        sleep(2);
    }

    return 0;
}
