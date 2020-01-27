#include <stdio.h>

int main(void)
{
    int var;
    int num;
    
    printf("Enter a number:");
    scanf("%d", &num);

    for (var = 2; var < num; var++)
        if (0 == (num % var))
            break;

    if (num == var)
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);

    return 0;
}
