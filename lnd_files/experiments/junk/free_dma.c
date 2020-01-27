#include <stdio.h>
#include <stdlib.h>

void func(char **ptr) {
    free(*ptr);
    *ptr = NULL;
}

int main(void)
{
     char *ptr = (char *) malloc(10);
     *ptr = 25;
     printf("val -> %d\n", *ptr);
     func(&ptr);
     printf("val -> %d\n", *ptr);
     return 0;
}
