#include <stdio.h>

#define temp(a,b) a = a + b - (b = a)

int main(void)
{
    int a = 10;
    int b = 20;

    temp(a,b);

    printf("%d  %d\n", a, b);

    return 0;

}
