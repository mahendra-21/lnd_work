#include <stdio.h>

int main(void)
{
    int *ptr = (int *)0x28373D00;

    *ptr = 200;

    printf("ptr addr = %d\n",*ptr);

    return 0;
}
