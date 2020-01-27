#include <stdio.h>

#if MAC == 2
int main(void)
{
    int arr[3][5] = { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    int **p = arr;
    printf("*++p = %d\n", *++p);
    printf("*p++ = %d\n", *p++);
    printf("*(p + 1) = %d\n", *(p + 1));
    printf("**arr = %d\n", **arr);
    printf("*(*arr + 1) = %d\n", *(*arr + 1));
    printf("**(arr + 1) = %d\n", **(arr + 1));
    printf("*(&arr + 1) = %d\n", *(&arr + 1));
    printf("*(*(arr + 1)) = %d\n", *(*(arr + 1)));
    printf("&p + 1 = %d\n", &p + 1);
    printf("*(*(arr + 2) + 3) = %d\n", *(*(arr + 2) + 3));
    return 0;
}
#elif MAC == 1
int main(void)
{
    static int a[] = {0, 1, 2, 3, 4};
    static int *p[] = {a, a + 1, a + 2, a + 3, a+ 4};
    int **ptr = p;
    printf("a = 0x%08x, *a = %d\n", a, *a);
    printf("p = 0x%08x, *p = 0x%08x, **p = %d\n", p, *p, **p);
    printf("ptr = 0x%08x, *ptr = 0x%08x, **ptr = %d\n", ptr, *ptr, **ptr);
    return 0;
}
#endif
