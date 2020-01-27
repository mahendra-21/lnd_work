#include <stdio.h>

void fun(int, int);

int main(void)
{
    int var = 10;
    int ivar = 65;
    fun(var, ivar);
    printf("var = %d\n", var);
    printf("ivar = %d\n", ivar);
    return 0;
}

void fun(int var, int ivar)
{
    int help = 1;
    int *ptr = &help;
    
    while (10 != *ptr)
        ++ptr;

    *ptr = 20;

    printf("var -> %d\tivar -> %d\n", var, ivar);
}
