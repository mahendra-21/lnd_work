#include <alloc.h>

int main(void)
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;
    char *ptr3 = NULL;
    char *ptr4 = NULL;

    ptr1 = (char *)my_alloc(sizeof(char) * 7);
    if (NULL == ptr1) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr1);
    binary();

    ptr2 = (char *)my_alloc(sizeof(char) * 10);
    if (NULL == ptr2) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr2);
    binary();

    my_free(ptr2);
    printf("After ptr2 free :\n");
    binary();
    

    ptr3 = (char *)my_alloc(sizeof(char) * 9);
    if (NULL == ptr3) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr3);
    binary();
    
    my_free(ptr1);
    printf("After ptr1 free :\n");
    binary();

    ptr4 = (char *)my_alloc(sizeof(char) * 23);
    if (NULL == ptr4) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr4);
    binary();


    return 0;
}
