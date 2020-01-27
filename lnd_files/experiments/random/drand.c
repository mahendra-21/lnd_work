#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    double dbl  = 0;
    int  loop  = 0;

    for (loop = 0; loop < 10; loop++) {
        dbl = drand48();
        printf("dbl = %lf\n", dbl);
    }

    return 0;
}
