#include "../../header.h"

int main(int argc, char *argv[])
{
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <name> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    mqd_t mqd;
    struct mq_attr attr;
    struct mq_attr nattr;
    struct mq_attr *attrp;

    attrp = NULL;
    attr.mq_maxmsg = 100;

    mqd = mq_open(argv[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, attrp);

    if ((mqd - 1) == mqd) {
        fprintf(stderr, " mq_open failed\n");
        exit(EXIT_FAILURE);
    }

    if (-1 == mq_getattr(mqd, &attr)) {
        fprintf(stderr, " mq_getattr failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Max # of msg's on queue      : %ld\n", attr.mq_maxmsg);
    printf("Max msg size                 : %ld\n", attr.mq_msgsize);
    printf("# of msg's currently on queue: %ld\n", attr.mq_curmsgs);

    nattr.mq_maxmsg = 20;
    nattr.mq_msgsize = 0x1000;

/*    if (-1 == (mq_setattr(mqd, &nattr, &attr))) {
        fprintf(stderr, " mq_setattr failed\n");
        exit(EXIT_FAILURE);
    }
   
    printf("Max # of msg's on queue      : %ld\n", nattr.mq_maxmsg);
    printf("Max msg size                 : %ld\n", nattr.mq_msgsize);
    printf("# of msg's currently on queue: %ld\n", nattr.mq_curmsgs);
*/        
    if (-1 == mq_close(mqd)) {
        fprintf(stderr, " mq_close failed\n");
        exit(EXIT_FAILURE);
    }
#if flag
    if (-1 == mq_unlink(argv[1])) {
        fprintf(stderr, " mq_unlink failed\n");
        exit(EXIT_FAILURE);
    }
#endif    
    exit(EXIT_SUCCESS);
}
