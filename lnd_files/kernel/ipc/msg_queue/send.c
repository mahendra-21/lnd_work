#include "../../header.h"

int main(int argc, char *argv[])
{
    if (4 != argc) {
        printf("Usage: %s <name> <string> <prior>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    mqd_t mqdfd;
    struct mq_attr *attrp = NULL;

    if ((mqdfd - 1) == (mqdfd = mq_open(argv[1], O_CREAT | O_WRONLY, 0600,
                    attrp))) {
        printf("mq_open failed\n");
        exit(EXIT_FAILURE);
    }
    
    if (-1 == (mq_send(mqdfd, argv[2], strlen(argv[2]), atoi(argv[3])))) {
        printf("mq_send failed\n");
        exit(EXIT_FAILURE);
    }

    if (-1 == (mq_close(mqdfd))) {
        printf("mq_close failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
