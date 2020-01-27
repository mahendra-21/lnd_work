#include <stdio.h>

int fun (int, int);

int main()
{
    int num1 = 10;
    int num2 = 20;
    int num3 = fun(num1, num2);
    printf("num = %d", num3);
    return 0;
}

int fun (int num1, int num2) {
    return num1 + num2;
}
