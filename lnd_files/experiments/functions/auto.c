#include <stdio.h>

int main(void)
{
    auto void fun(int var);
    
    int var = 10;

    fun(var);

    void fun(int  var) {

        printf("var = %d\n", var);

    }

    return 0;
}
