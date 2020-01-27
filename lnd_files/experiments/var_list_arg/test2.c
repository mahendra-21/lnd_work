#include <stdio.h>
#include <stdarg.h>

typedef int (*fp)(char *, ...);

int add(char *num, ...) {
    int sum = 0;
    char *help = NULL;
    int temp = 0;

    va_list var;
    va_start(var, num);
    
    while (1) {
        help = va_arg(var, char *);
        temp = atoi(help);
        if (!temp) return sum;
        else sum += temp;
    }

    return sum;
}

fp fadd = add;

int main(int argc, char **argv)
{
    int ret = 0;
    
    if (argc <=1) {
        printf("Usage: ./a.out data ...\n");
        return 0;
    }

    ret = (*fadd)(*argv);

    printf("ret = %d\n", ret);

    return 0;
}
