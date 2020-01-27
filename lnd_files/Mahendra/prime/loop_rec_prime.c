#include <stdio.h>

int rec_prime(int num) {
    static int help = 2;

    if (help < num) {
        if (0 == (num % help))
            return 0;
    } else {
        int temp = help;
        help = 2;
        return temp;
    }

    help++;
    rec_prime(num);
}


int main(void)
{
    int ret;
    int num;
    int var;

    printf("Enter a number:");
    scanf("%d", &num);

    /*    for (var = 2; var < num; var++)
          if (0 == (num % var))
          break;
     */
    if (num < 2) {
        printf("less than 2 not a prime numbers\n");
        return 0;
    }

    printf("prime numbers:");

    for (var = 2; var <= num; var++) {
        ret = rec_prime(var);

        if (var == ret)
            printf(" %d", var);
    }
    
    printf("\n");
    return 0;
}
