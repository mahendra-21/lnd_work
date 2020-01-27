#include <stdio.h>

#if 0
int main(void)
{
    char a[1] = "m";
    char b[2] = "m";
    printf("str -> %s   %s\n", a, b);
    return 0;
}
#endif

#if 1
int main(void)
{
//    printf("str -> %sB%s\n", 'A', 'C'); // Segfault
    printf("str -> A%sC\cD%s\n", "B", "E");
    return 0;
}
#endif
