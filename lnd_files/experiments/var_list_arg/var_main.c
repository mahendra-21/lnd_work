#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int main(int argc, ...)
{
    int num = 0;
    int loop = 0;
    char *ptr = NULL;

    va_list var;
    va_start(var, argc);

    printf("var = %p\n", var);
    printf("argc_addr. = %p    ", &argc);
    printf("argc = %d\n", argc);

    for (loop = 1; loop < argc; loop++) {    
        ptr = va_arg(var, char*);
        printf("ptr = %p\n", ptr);
        num = atoi(ptr);
        printf("var_num = %d\n", num);
    }

    va_end(var);
    return 0;
}
