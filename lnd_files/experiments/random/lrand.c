#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long int num = 0;
    int loop = 0;

    for (loop = 0; loop < 100; loop++) {
        num = lrand48() % 100; 
        printf("num = %ld\n", num);
    }

    return 0;
}
