#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Malloc will take unsigned values but in this program we are giving 
       string. So, malloc throws warnings like pointer ((char *) -> type) 
       is giving without a cast and malloc allocating 1-byte 
       memory to programmer */

    char *ptr = NULL;

    if (NULL == (ptr = (char *) malloc("mahendra"))) { 
        printf("malloc failed\n");
        return 0;
    }

    printf("head data -> %d\n", *(ptr - 4));
    free(ptr);
    return 0;
}
