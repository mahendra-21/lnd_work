#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define LEN 127

int main(int argc, char *argv[])
{
    int fd;
    int pipefd[2];
    pid_t cpid;
    char buf;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDWR); 

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {
        close(pipefd[1]); /* Close unused write end */
        
        while (read(pipefd[0], &buf, 1) > 0)
            write(fd, &buf, 1);

        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } else {    /* parent writes argv[2] to pipe */
        close(pipefd[0]); /* Close unused read end */

        char *str = NULL;

        if (NULL == (str = (char *)malloc(LEN)));

        printf("Enter the string: ");
        fgets(str, LEN, stdin);

        write(pipefd[1], str, strlen(str)); 
        close(pipefd[1]); /* Reader will see EOF */
        wait(NULL);     /* Wait for child */
        exit(EXIT_FAILURE);
    }
}

