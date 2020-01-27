#include <stdio.h>

int main(void)
{
    printf("size  = %d\n", sizeof(void));
    printf("size  = %d\n", sizeof(main, main));
    printf("size  = %d\n", sizeof(printf, main));
    int ret = add(10, 20);
    printf("ret = %d\n", ret);
    return 0;
}

int add(int var1, int var2) {
    printf("add = %d\n", sizeof(add));
    return sizeof(add, add, add, add, add);
}
