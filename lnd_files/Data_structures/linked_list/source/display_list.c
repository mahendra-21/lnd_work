#include <header.h>

int sll_display_list(SL *hptr) {
    
    if (NULL == hptr)   return FAILURE;
   
    SL *ptr = hptr;
    int index = 1;

    while (ptr) {
        printf("    %d. data = %d\n", index,  ptr -> data);
        ptr = ptr -> link;
        index++;
    }

    return SUCCESS;
}

int dll_display_list(DL *hptr) {
    
    if (NULL == hptr)   return FAILURE;
   
    DL *ptr = hptr;
    int index = 1;

    while (ptr) {
        printf("    %d. data = %d\n", index,  ptr -> data);
        ptr = ptr -> next;
        index++;
    }

    return SUCCESS;
}
