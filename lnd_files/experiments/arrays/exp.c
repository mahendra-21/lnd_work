#include <stdio.h>

int main ()
{
    char arr[2][3]= {{1, 2, 3}, {4, 5, 6}};

    printf(" %d\n", *(*(arr + 0) + 2));
    
    printf("%d\t%d\t%d\t%d\n", sizeof(&arr), sizeof(arr), sizeof(&arr[0]), sizeof(&arr[0][0]));
}
