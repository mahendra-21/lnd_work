#include "../../header.h"

int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <name> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    mqd_t mqdfd;
    struct mq_attr attr;
    struct mq_attr *attrp = NULL;
    unsigned int prior;
    ssize_t size;

    if ((mqdfd - 1) == (mqdfd = mq_open(argv[1], O_CREAT | O_RDONLY, 0600,
                    attrp))) {
        printf("mq_open failed\n");
        exit(EXIT_FAILURE);
    }

    char *str = (char *) malloc(LEN);
    if (NULL == str) {
        printf("malloc faile\n");
        exit(EXIT_FAILURE);
    }
    
    if (-1 == mq_getattr(mqdfd, &attr)) {
        printf("mq_getattr failed\n");
        exit(EXIT_FAILURE);
    }
while (1) {
    if (-1 == (size = mq_receive(mqdfd, str, attr.mq_msgsize, &prior))) {
        printf("mq_send failed\n");
        exit(EXIT_FAILURE);
    }

    if (-1 == write(STDOUT_FILENO, str, size)) {
        printf("write failed\n");
        exit(EXIT_FAILURE);
    }
    printf("\n");
}
    if (-1 == mq_close(mqdfd)) {
        printf("mq_close failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
