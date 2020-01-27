#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str;
    char ptr[] = "hello";

    str = (char *) memmove(ptr, ptr + 2, 2);
    printf("str -> %s\n", str);

    return 0;
}
