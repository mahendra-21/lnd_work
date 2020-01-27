#include "../../header.h"

void sigpipe() {
    printf("In sigpipe function\n");
    exit(EXIT_SUCCESS);
}

int main(void)
{
    int pidfd[2];

    signal(SIGPIPE, sigpipe);

    if (-1 == pipe(pidfd)) {
        printf("pipe failed\n");
        exit(EXIT_FAILURE);
    }

    char *str = (char *)malloc(LEN);
    if (NULL == str) {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }

    int i = 1;

//    while (1) {
        close(pidfd[0]);
        printf("enter the data: ");
        fgets(str, LEN, stdin);
        __fpurge(stdin);

         write(pidfd[1], str, strlen(str)); 
        
            printf("cur -> %d\n", i++);
  //  }
         close(pidfd[1]);
         char *tmp;
         read (pidfd[1], tmp, LEN);
         printf("str -> %s\n", tmp);

    return 0;
}
