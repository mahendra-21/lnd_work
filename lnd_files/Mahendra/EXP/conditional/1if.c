#include <stdio.h>

int main(void)
{
    int a = 1;

    while (1) {
        if (a--) {
            printf("In if statement\n");
        } else {
            printf("In else statement\n");
            break;
        }
    }

    return 0;
}
