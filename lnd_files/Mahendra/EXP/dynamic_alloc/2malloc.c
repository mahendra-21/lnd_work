#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Malloc will take unsigned values but in this program we are giving 
       character. So, malloc takes given character ascii value & allocating
       memory to programmer */

    char *ptr = NULL;

    if (NULL == (ptr = (char *) malloc(13))) { 
        printf("malloc failed\n");
        return 0;
    }

    printf("head data -> %d\n", *(ptr - 4));

    free(ptr);
    /* Error in `./2malloc': double free or corruption (top): 0x08187008
     * Aborted (core dumped)
     */
//    free(ptr);

    return 0;
}
