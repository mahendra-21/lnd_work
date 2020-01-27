#include <stdio.h>
int main()
{
    printf("size of NULL = %d\n", sizeof(NULL));
    printf("size of 0 = %d\n", sizeof(0));
    printf("size of '\0' = %d\n", sizeof('\0'));
    printf("size of void = %d\n", sizeof(void));
    printf("size of void * = %d\n", sizeof(void *));
    return 0;
}
