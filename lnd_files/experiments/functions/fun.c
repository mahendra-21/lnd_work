#include <stdio.h>

//void fun(char var);
int main(void)
{
    char cvar = 'A';
    fun(cvar);
    return 0;
}

void fun(char var)
{
    printf("char = %d\n", var);
}
