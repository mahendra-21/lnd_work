#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Keep on allocating memory to the programmer using malloc at certain time 
       malloc can't able to get free space in memory. So, at that time 
       malloc failed and returns NULL to the programmer */
    int count = 0;
    char *ptr;
    while (1) {
        if (NULL == (ptr = (char *) malloc(1024 * 1024))) { 
            perror("malloc");
            printf("malloc failed\n");
            break;
        }
        count++;
    }

    printf("malloc allocates %d times memory -> %x\n", count, 
            (count * 1024 * 1024));
    free(ptr);
//    ptr = NULL;
    free(ptr);
    return 0;
}
