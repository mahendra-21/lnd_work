#include <stdio.h>  

int main(void)
{
    unsigned int var;
    int loop;

    printf("Before : ");
    for (loop = 31; loop >= 0; --loop) {
        printf("%u", var >> loop & 1);
        if (loop % 8 == 0)
            printf(" ");
    }
    printf("\n");

    var |= 1 << 10;
    for (loop = 31; loop >= 0; --loop) {
        printf("%u", var >> loop & 1);
        if (loop % 8 == 0)
            printf(" ");
    }
    printf("\n");

    return 0;
}
