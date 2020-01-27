#if MAC == 2
#include <stdio.h>

void fun(auto int var);
/*  error: storage class specified for parameter ‘var’ */

int main(void)
{
    auto int var = 10;
    fun(var);
    return 0;
}
  
void fun(auto int var) {
    printf("var -> %d\n", var);
}
/* auto storage class specifier is not allowed as function parametrs */

#elif MAC == 1
#include <stdio.h>

auto int va = 10;
/*  error: file-scope declaration of ‘va’ specifies ‘auto’ */

int main(void)
{
    int var = 10;
    printf("var -> %d\n", var);
    return 0;
}
/* For auto storage class specifier storage is allocated during run-time,
   but in this program auto is written at globally. During compile time
   compiler can't allocate storage space for automatic variables. so,
   this program throws an error */
#endif
