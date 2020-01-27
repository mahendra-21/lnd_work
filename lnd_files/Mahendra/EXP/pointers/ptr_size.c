#include <stdio.h>

#if MAC == 3
int main(void)
{
//    int *arr[] = {(int *)1, (int *)2, (int *)3, (int *)4};
    char *arr[] = {"monday", "tue", "wed", "thu", "fri"};
    printf("size of *arr[4] -> %d\n", sizeof(arr));
    printf("size of arr[0] -> %d\n", sizeof(arr[0]));
    return 0;
}
#elif MAC == 2
int main(void)
{
    int *ptr = 10;
    printf("ptr -> 0x%08x\n", ptr);
    
    ptr++;
    printf("ptr++ -> 0x%08x\n", ptr);
    return 0;
}
#elif MAC == 1
int main(void)
{
    char *arr[4];

    printf("arr -> %d\narr[0] -> %d\n", sizeof(arr), sizeof(arr[0]));
    printf("&arr -> %p\n", arr);
    printf("&arr[0] -> %p\t&(arr + 0) -> %p\n", arr[0], (arr + 0));
    printf("&arr[1] -> %p\t&(arr + 1) -> %p\n", arr[1], (arr + 1));
    printf("&arr[2] -> %p\t&(arr + 2) -> %p\n", arr[2], (arr + 2));
    printf("&arr[3] -> %p\t&(arr + 3) -> %p\n", arr[3], (arr + 3));

    return 0;
}
#elif MAC == 0
int main(void)
{
    char *chr;
    int *ivar;
    float *fvar;
    double *dvar;

    printf("char * -> %d\n", sizeof(chr));
    printf("int * -> %d\n", sizeof(ivar));
    printf("float * -> %d\n", sizeof(fvar));
    printf("double * -> %d\n", sizeof(dvar));

    return 0;
}
#endif
