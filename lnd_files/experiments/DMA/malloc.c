#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ptr = NULL;

    ptr = (char *) malloc (17);
    printf("ptr ->  %p    *(--ptr) -> %d\n", ptr, *(ptr - 4));
    ptr++;
    printf("*(ptr + 4) -> %d\n", *(ptr + 35));
    return 0;
}
