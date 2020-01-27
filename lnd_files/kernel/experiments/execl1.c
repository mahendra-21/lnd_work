#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("PID -> %d\n", getpid());

    execl("./help", argv[0], (char *)NULL);

    return 0;
}
