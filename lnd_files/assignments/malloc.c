#include <stdio.h>
#include <stdlib.h>

int main(vooid)
{
    int *p = NULL;

    int var = 1;

    while (var) {
        p = (int *) malloc(100000 * sizeof(int));
        printf("p = %p\n", p);
    }

    return 0;
}
