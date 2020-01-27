#include <stdio.h>
int main()
{
    int *num;

    printf("addr 'p' = %p\n", num);
    printf("addr '&num'  = %p\n", &num);
    printf("addr 'u'  = %u\n", num);
    printf("addr '*num'  = %p\n", *num);
    printf("addr 'd' = %d\n", num);

    return 0;

}
