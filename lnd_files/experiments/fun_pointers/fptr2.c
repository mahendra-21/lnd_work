/*  */
#include <stdio.h>

//void (*fptr)(void);
void (*fptr)(int var);
void fun(int var);

//int (*fptr)(int) = fun; 
/* warning : initialization fron incompatible pointer type.
    & executining fine (printing output correctly)
 */

int main(void)
{
    fptr = fun;

    fptr(1);

    return 0;
}

void fun(int var) {
    puts("In fun function");
    printf("var = %d\n", var);
}
