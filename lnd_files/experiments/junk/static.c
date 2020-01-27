#include <stdio.h>

int main(void)
{
    static char *str = "hello world";
    static char **str1 = &str;

    printf("str -> %s\n", str);
    printf("str1-> %s\n", *str1);
    return 0;
}
