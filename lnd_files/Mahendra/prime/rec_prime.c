#include <stdio.h>

int rec_prime(int num) {
    static int help = 2;

    if (help < num) {
        if (0 == (num % help))
            return 0;
    } else {
        return help;
    }

    help++;
    rec_prime(num);
}


int main(void)
{
    int ret;
    int num;
    
    printf("Enter a number:");
    scanf("%d", &num);

/*    for (var = 2; var < num; var++)
        if (0 == (num % var))
            break;
 */
    ret = rec_prime(num);

    if (num == ret)
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);

    return 0;
}
