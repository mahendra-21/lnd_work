#include "alloc.h"

int main(void)
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;

    ptr1 = (char *) my_alloc(sizeof(char) * 10);
    if (NULL == ptr1) {
        printf("my_alloc failed\n");
        return 0;
    }
    printf("ptr -> %p\n", ptr1);
    binary();
    
    ptr2 = (char *) my_alloc(sizeof(char) * 4);
    if (NULL == ptr2) {
        printf("my_alloc failed\n");
        return 0;
    }
    printf("ptr -> %p\n", ptr2);
    binary();

    my_free(ptr1);
    printf("after free: ptr1\n");
    binary();
    
    ptr1 = (char *) my_alloc(sizeof(char) * 13);
    if (NULL == ptr1) {
        printf("my_alloc failed\n");
        return 0;
    }
    printf("ptr -> %p\n", ptr1);
    binary();
    return 0;
}
