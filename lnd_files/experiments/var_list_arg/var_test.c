#include <stdio.h>
#include <stdarg.h>

int sum(int inputs, ...);

int main(void)
{
    int ret = 0;

    ret = sum(3, 10, 20, 30);
    printf("sum = %d\n", ret);

    ret = sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0);
    printf("sum = %d\n", ret);

    return 0;
}

int sum(int inputs, ...) {
    int num = 0;
    int sum = 0;
//printf("in fun = %d\n", inputs); // in fun = 3, in fun = 10

    va_list var;

//    printf("var = %p\n", var); // var = (null)
//    printf("var = %s\n", var); // var = (nil)

    va_start(var, inputs);

    printf("var = %p\n", var); // var = address
    printf("inputs = %p\n", &inputs); //var = address

    while (inputs--) {
//    va_start(var, inputs); // sum = 30, sum = 10

        num = va_arg(var, int);
//        printf("in loop num = %d\n", num); // 4th time garbage
        sum += num;

    }

    return sum;
}
