#include "../header.h"

int main(void)
{
    int pipefd[2];
    int size = 0;
    char ch = 'A';

    if (pipe2(pipefd, O_NONBLOCK) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    while (write(pipefd[1], &ch, 1) != -1) {
        size++;
        printf("size = %d\n", size);
    }

    printf("Bye...!\n");
    return 0;
}
