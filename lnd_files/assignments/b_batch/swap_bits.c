#include <stdio.h>

void binary_print (unsigned int num);

int main()
{
    int hex = 0;
    int mask = 0xf;
    int size = sizeof(int) * 8;
    int nibble = sizeof(int);

    printf("enter number:");
    scanf("%d", &hex);
    binary_print(hex);

    int help = hex;
    hex = 0;

    for(; nibble <= size; nibble += 4) {
        hex = hex | ((help & mask) << size - nibble);
        help = help >> 4;
    }
    

    printf("%x\n", hex);
    binary_print(hex);
   
    return 0;
}

void binary_print (unsigned int num) {

    int pos = 0;
    unsigned char bit = 0;
    pos = (sizeof(int) * 8) - 1;

    for (; pos >= 0; --pos) {

        bit = num >> pos & 1;
        printf("%d", bit);

        if (pos % 4 == 0) {
            printf(" ");
        }

    }

    printf("\n");
}
