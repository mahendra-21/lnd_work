/* Function for binary printing of the Number */
#include <header.h>
void binary_print(unsigned int num) {
    
    int pos = 0;

    unsigned char bit = 0;

    pos = (sizeof(int) * 8) - 1;
    
    for (; pos >= 0; --pos) {

        bit = num >> pos & 1;
 
        printf("%d", bit);

        if (pos % 8 == 0) {
            printf(" ");
        }

    }

    printf("\n");
}
