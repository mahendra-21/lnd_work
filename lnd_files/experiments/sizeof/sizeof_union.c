#include <stdio.h>  

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Head;

int main(void)
{
    printf("size -> %d\n", sizeof(Head));
    return 0;
}
