#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    long int num = 0;
    long int num1 = 0;

    clock_t time;
    time = clock();

    int loop = 0;

    for (loop = 0; loop < 5; loop++) {
        num = (rand() % (1996 - 1995 + 1)) + 1995;
        num1 = rand();
        printf("num = %ld   num1 = %ld\n", num, num1);
    }

    time = clock() - time;

    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    printf("time taken by for loop = %lf\n", time_taken);

    return 0;
}
