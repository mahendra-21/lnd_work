#include <stdio.h>
#include <stdlib.h>

struct st {
    int var1;
    int var2;
} *ptr;

int main(void)
{
    ptr = (struct st *) malloc(sizeof(struct st));
    
    if (NULL == ptr) {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    ptr -> var1 = 10;
    ptr -> var2 = 20;

    printf("var1 -> %d  var2 -> %d\n", ptr -> var1, ptr -> var2);
    return 0;
}
