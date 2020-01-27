#include <stdio.h>
#include <stdarg.h>

int fun(int var, ...);

int main(int argc, char **argv)
{
    int (*fp)(int, ...) = fun;

    printf("mul = %d\n", fp(1, 2, 3, 0));

    return 0;
}

int fun(int var, ...)
{
    int mul = 1;
    int help;

    va_list va;
    va_start(va, var);

    while (0 != (help = va_arg(va, int)))
        mul *= help;

    return mul;
}
