#include <stdio.h>

void fun()
{
  extern  int_var;
}

void fun1(void);
void fun2(void);
void fun3(void);

int main()
{
    fun1();
    fun2();
    fun3();
    return 0;
}

void fun1(void)
{
    fun();
    int_var = 7;
    printf("fun1 = %d\n", int_var);
}

void fun2(void)
{

    printf("fun2 = %d\n", int_var);
}

void fun3(void)
{

    printf("fun3 = %d\n", int_var);
}


