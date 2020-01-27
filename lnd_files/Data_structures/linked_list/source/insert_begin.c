#include <header.h>

int sll_insert_begin(SL **hptr) {
    SL *temp = sll_create_node();

    if (NULL == temp)   return FAILURE;
   
    printf("Enter data: ");
    temp -> data = get_number();

    temp -> link = *hptr;
    *hptr = temp;

    return SUCCESS;
}

int dll_insert_begin(DL **hptr) {
    DL *temp = dll_create_node();

    if (NULL == temp)   return FAILURE;
     
    printf("Enter data: ");
    temp -> data = get_number();

    temp -> next = *hptr;
    temp -> prev = *hptr;
    *hptr = temp;

    return SUCCESS;
}
