#include <stdio.h>

int main(void)
{
    int ONE = 3;
    int TWO = 5;

    #define ONE TWO
    #define TWO ONE

    printf("%d  %d\n", ONE, TWO);
    return 0;
}
