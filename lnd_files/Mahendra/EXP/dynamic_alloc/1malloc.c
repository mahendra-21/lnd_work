#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Malloc will take unsigned values but in this program we are giving 
       signed value. So, in malloc internally 2's complementing the given 
       value. Then the converted value is bigger what malloc can't allocate
       that much space to the programmer, that's malloc gets failed and 
       return NULL back to the program*/
    char *ptr = NULL;
    if (NULL == (ptr = (char *) malloc(-2))) { 
        printf("malloc failed\n");
        return 0;
    }

    printf("head data -> %d\n", *(ptr - 4));
    return 0;
}
