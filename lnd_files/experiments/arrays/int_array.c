#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char var = 10;

int main(void)
{

    char str[] = "hello world";

    int *ptr = (int *) malloc (sizeof(int) * 10);

//    ptr = (int *)"mahendra";

    ptr = (int *) strcpy((void *)ptr, "Mahendra");
    *ptr = 'S';

    printf("ptr -> %s var -> %d\n", (char *)ptr, var);
    return 0;
}
