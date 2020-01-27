#include <stdio.h>

int main(void)
{
    int *ptr = main;

    printf("addr. main = %p\n", *ptr);
    printf("main.. = %p\n", main);

    return 0;
}
