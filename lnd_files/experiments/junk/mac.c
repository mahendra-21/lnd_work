#include<stdio.h>
#define TOTAL_ELE (sizeof (array) / sizeof(array[0]))
int array[] = {1, 2, 3, 4, 5, 6, 7};
int main(void)  
{                                       
    int d;                                                                 
    printf("%d\n",TOTAL_ELE);

    for (d = -1; d < (unsigned int)6/*TOTAL_ELE - 1*/; d++) {
        printf("%d\n", array[d + 1]);
    }

    return 0;
}
