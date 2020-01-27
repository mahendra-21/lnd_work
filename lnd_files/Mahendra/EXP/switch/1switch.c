#include <stdio.h>

int main(void)
{
    int a = 2;
    int b = 3;

    switch (a) {
        case 1:
            printf("In case -> 1\n");
            break;
            if (b == 3) {
                case 2:
                    printf("In case -> 2\n");
                    break;
                case 4:
                    printf("In case -> 4\n");
                    break;
            } else {
                printf("Case -> 2 does not execute\n");
                break;
            }
        case 3:
            printf("In case -> 3\n");
            break;
    }

    return 0;
}
