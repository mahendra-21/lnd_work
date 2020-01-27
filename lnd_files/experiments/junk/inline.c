#include <stdio.h>

inline void fun(void) {
    printf("I'm in inline funtion\n");
}

int main(void)
{
    printf("In main\n");
    fun();
    return 0;
}
