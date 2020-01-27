#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    
    int row = 3;
    int col = 4;
    int loop = 0;

    int **ptr = (int **) malloc(row * sizeof(int *));
  
    for (loop = 0; loop < row; loop++)
        ptr[loop] = (int *) malloc(col * sizeof(int));

    printf("size of ptr = %d\n", sizeof(ptr));
    printf("size of *ptr = %d\n", sizeof(*ptr));
    printf("size of **ptr = %d\n", sizeof(**ptr));

    return 0;
}
