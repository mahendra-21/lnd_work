#include "../../header.h"

int main(int argc, char *argv[])
{
    if (3 != argc) {
        printf("Usage: %s <name> <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

     mqd_t mqd;
     struct mq_attr *attrp = NULL;
     FILE *fptr;;
     char ch;
     int loop;
     int count = 0;

     char *str = (char *)malloc(LEN);
     if (NULL == str) {
         printf("malloc failed\n");
         exit(EXIT_FAILURE);
     }
     
     /* Creating or opening a message queue */
     if ((mqd - 1) == (mqd = mq_open(argv[1], O_CREAT | O_RDWR, S_IRUSR
                     | S_IWUSR, attrp))) {
         printf("mq_open failed\n");
         exit(EXIT_FAILURE);
     }
     
     if (NULL == (fptr = fopen(argv[2], "r"))) {
         printf("open failed\n");
         exit(EXIT_FAILURE);
     }
        
     while (NULL != (fgets(str, LEN, fptr))) {

         if (0 == (count % 3))
             printf("string -> %s\n", str);

             count++;
     }
     printf("# of lines -> %d\n",  count);

     fclose(fptr);
     return 0;
}
