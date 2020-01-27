/* checking function pointer, declared in diff positions */
#include <stdio.h>

int fun1(int var1, int var2);
//int (*fun)(int var1, int var2) = fun1; //working fine and giving output

int main(void)
{
    int var1 = 10;
    int var2 = 30;

//    int (*fun1)(int var1, int var2) = fun1; //seg-fault
//    int ret = fun1(var1, var2);

    int (*fun)(int var1, int var2) = fun1; 
    int ret = fun(var1, var2);
    
    printf("ret = %d\n", ret);
    return 0;
}

int fun1(int var1, int var2) {
    return var1 + var2;
}
/*error: 'fun' redeclared as diff kind of symbol */
//int (*fun)(int var1, int var2) = fun1;  
