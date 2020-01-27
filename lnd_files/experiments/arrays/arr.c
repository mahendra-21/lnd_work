#include <stdio.h>

int main(void)
{
    int arr[4] = {1, 2, 3, 4};

    int *arr1 = arr;
    int *arr2 = (int *)&arr;

    printf ("%p %p\n", arr1, arr2);

    return 0;
}
