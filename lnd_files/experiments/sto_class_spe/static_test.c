#include <stdio.h>
int main()
{
    int num = 10;
    static int num_1;
    num_1 = num;
    printf("number = %d\n", num_1);
    return 0;
}
