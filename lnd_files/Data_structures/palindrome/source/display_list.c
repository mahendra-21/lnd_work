#include <header.h>

int display_list(SL *hptr) {
    
    if (NULL == hptr)   return FAILURE;
   
    SL *ptr = hptr;
    int index = 1;

    while (ptr) {
        printf("    %d. data = %d   addr = %p\n", index,  ptr -> data, ptr);
        ptr = ptr -> link;
        index++;
    }

    return SUCCESS;
}
