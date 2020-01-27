#include <stdio.h>

int main(void)
{
    int var = 10;
    int *ptr = &var;
    ptr = ptr >> 12;
    return  0;
}
