#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long int num = 0;
    int loop = 0;

    for (loop = 0; loop < 10; loop++) {
        num = mrand48() % 1000; 
        printf("num = %ld\n", num);
    }

    return 0;
}
