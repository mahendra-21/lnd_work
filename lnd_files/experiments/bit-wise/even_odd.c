#include <stdio.h>

#define even_odd(num) (num & 1) ? "odd": "even"
int main(void)
{
    unsigned int num;
    printf("enter a number: ");
    scanf("%d", &num);

    printf("%d is %s\n", num, even_odd(num));
    return 0;
}
