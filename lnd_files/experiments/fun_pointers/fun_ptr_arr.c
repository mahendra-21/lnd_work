#include <stdio.h>

int add(int var1, int var2) {
    return var1 + var2;
}

int sub(int var1, int var2) {
    return var1 - var2;
}

//int (*ptr[])(int, int);
int (*ptr[])(int, int) = {add, sub};
//typedef int (*ptr)(int, int);

int main(void)
{
//    ptr ptr1[] = {add, sub};
//    ptr[0] = add;
//    ptr[1] = sub;

    printf("add = %d\n", ptr[0](10, 20));
    printf("sub = %d\n", ptr[1](10, 20));

    return 0;
}
