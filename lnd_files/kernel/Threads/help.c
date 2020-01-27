#include "header.h"

#define LEN 100

/* Thread for even numbers */
void *thread1(void *arg)
{
    mqd_t mqd;
    struct mq_attr attr;
    struct mq_attr *attrp;
    attrp = NULL;
    int num;
    char *file = (char *) arg;

    if ((mqd - 1) == (mqd = mq_open(file, O_CREAT | O_RDWR,
                    S_IRUSR | S_IWUSR, attrp))) {
        printf("mq_open failed in thread1\n");
        exit(EXIT_FAILURE);
    }

    char *str = (char *) malloc(LEN);
    if (NULL == str) {
        printf("malloc failed in thread1\n");
        exit(EXIT_FAILURE);
    }
    
    while (1) {
    
        if (-1 == mq_getattr(mqd, &attr)) {
            printf("mq_getattr failed in thread1\n");
            exit(EXIT_FAILURE);
        }

        if (-1 == (mq_receive(mqd, str, attr.mq_msgsize, 0))) {
            printf("mq_send failed in thread1\n");
            exit(EXIT_FAILURE);
        }

        num = atoi(str);

        if (0 == (num % 2)) {
            printf("IN even -----> %d\n", num);
        } else {

            if (-1 == (mq_send(mqd, str, strlen(str), 0))) {
                printf("mq_send failed in thread1\n");
                exit(EXIT_FAILURE);
            }

        } 

    }
    mq_close(mqd);
}

void strrev(char *str) {
    char temp = NULL;
    int start = 0;
    int len = 0;
    for (; str[len]; len++);
    for (len = len - 1; len > start; start++, --len) {
        temp = str[start]; 
        str[start] = str[len];
        str[len] = temp;
    } 
}

char str1[LEN];
void *itoa(int num) {
    int var = num;
    int len = 0;

    while (var) {
        str1[len++] = ((var % 10) + '0');
        var = var / 10;
    }

    strrev(str1);
    return str1;
}

int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <mq_file> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    mqd_t mqd;
    struct mq_attr *attrp;
    struct mq_attr attr;
    attrp = NULL;
    pthread_t th_id1;
    void *res;
    int loop;
    char *str;

    if (0 != pthread_create(&th_id1, NULL, thread1, argv[1])) {
        printf("pthread_create is failed\n");
        exit(EXIT_FAILURE);
    }

    if ((mqd - 1) == (mqd = mq_open(argv[1], O_CREAT | O_RDWR, 
                    S_IRUSR | S_IWUSR, attrp))) {
        printf("mq_open failed in thread1\n");
        exit(EXIT_FAILURE);
    }
    
    if (-1 == mq_getattr(mqd, &attr)) {
        printf("mq_getattr failed in thread1\n");
        exit(EXIT_FAILURE);
    }

    //    for (loop = 0; loop < 10; loop++) {
    while (1) {
        str = itoa(rand() % 10);

        if (-1 == mq_send(mqd, str, strlen(str), 0)) {
            printf("mq_send failed\n");
            exit(EXIT_FAILURE);
        }

        sleep(1);
        //    }
        /*    if (0 != pthread_join(th_id1, &res)) {
              printf("pthread_join failed\n");
              exit(EXIT_FAILURE);
              }
         */
        if (-1 == (mq_receive(mqd, str, attr.mq_msgsize, 0))) {
            printf("mq_send failed in thread1\n");
            exit(EXIT_FAILURE);
        }

        printf("IN odd -> %d\n", atoi(str));
//        wait(1);
        sleep(1);
    }

    mq_close(mqd);
    pthread_exit(NULL); 
}
