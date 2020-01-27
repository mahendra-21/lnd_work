#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p = NULL;
    printf("before dma = %p\n", p);

    p = (char *) malloc(10 * sizeof(char));
    printf("after dma = %p\n", p);

    *p = 'A';
    printf("data = %d\n", *p);

    free(p);
    printf("after free = %p\n", p);
    printf("*p = %d\n", *p);

    p = NULL;
    printf("after all = %p\n", p);
    printf("*p = %d\n", *p);

    return 0;
}
