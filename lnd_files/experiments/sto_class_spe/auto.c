#include <stdio.h>
int main()
{
    auto int x_var;
    auto fun(int );
    x_var = 10;
    fun(x_var);
    printf("num = %d\n", x_var);
    auto fun(int var)
    {
        printf("num = %d\n", var);
    }
    return 0;
}
