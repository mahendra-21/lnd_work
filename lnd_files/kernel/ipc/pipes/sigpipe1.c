#include "../../header.h"

int main(void)
{
    int pidfd[2];

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
    printf("enter the data: ");
    fgets(str, LEN, stdin);
    __fpurge(stdin);
    char *temp;
    switch (fork()) {
        case   0: 
//            close(pidfd[0]);
//            while (1)
                write(pidfd[1], str, strlen(str));
            printf("child cur -> %d\n", i++);
            break;
        default :
//            close(pidfd[1]);
            wait(NULL);
            printf("parent cur -> %d\n", i++);
            read(pidfd[0], temp, LEN);
            printf("string in parent - > %s\n", temp);
            break; 
    }

    return 0;
}
