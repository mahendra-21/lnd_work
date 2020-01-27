#include <stdio.h>

#ifdef flag
int fib(int num) {
/*
    if (0 == num) {
        return 0;
    } else if (1 == num) {
        return 1;
    } else {
        return fib(num - 1) + fib(num - 2);
    }
 //   if (1 >= num)   return num;
 */
    return (0 == num) ? 0 : (1 == num) ? 1 : fib(num - 1) + fib(num - 2);
}

int main(void)
{
    int num = 0;

    printf("fib series: ");
    for (num = 0; num < 10; num++)
        printf("%d   ", fib(num));

    printf("\n");
    return 0;
}
#endif

#ifdef flag1
int main(void)
{
    int upto = 10;
    int va;
    int va1 = 0;
    int va2 = 1;
    
    printf("fib # -> ");
    printf("%d %d", va1, va2);

    while (upto--) {
        va = va1 + va2;
        va1 = va2;
        va2 = va;
        printf(" %d", va);
    }

    printf("\n");
    return 0;
}
#endif
