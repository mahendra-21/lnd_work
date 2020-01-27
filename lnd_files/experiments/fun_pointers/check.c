#include <stdio.h>
int (*fun_ptr)(int, int);
void *fun1(int, int);
char fun2(int, int);

int main(void)
{
    //fun_ptr ptr1;
   // fun_ptr ptr2;
    int ret = 0;
    //ptr1 = fun1;
//    ptr2 = (fun_ptr)ptr1(10, 20);
    fun_ptr = fun1(10, 20);
    ret = fun_ptr(1000, 20);
    printf("ret = %d\n", ret);
    return 0;
}

void *fun1(int var1, int var2) {
    printf("var1 = %d   var2 = %d\n", var1, var2);
    return fun2;
}

char fun2(int var1, int var2) {
    return var1 + var2;
}
