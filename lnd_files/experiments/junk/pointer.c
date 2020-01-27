#include <stdio.h>

const int a_var = 10;

int main()
{
//    int var = 20;

    int *p_var = &a_var;

    *p_var = 30;

    printf("number = %d\n", a_var);

    return  0;

}
