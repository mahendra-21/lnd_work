#include <header.h>

int sll_insert_end(SL **hptr) {

    SL *temp = sll_create_node();

    if (NULL == temp)   return FAILURE;

    printf("Enter data: ");
    temp -> data = get_number();

    if (NULL == *hptr) {
        temp -> link = *hptr;
        *hptr = temp;
    } else {
        SL *ptr = *hptr;

        while (NULL != ptr -> link)
            ptr = ptr -> link;

        temp -> link = ptr -> link;
        ptr -> link = temp;
    }
    
    return SUCCESS;
}


int dll_insert_end(DL **hptr) {
  
    DL *temp = dll_create_node();

    if (NULL == temp)   return FAILURE;

    int number = 0;
    printf("Enter data: ");
    number = get_number();
        
    temp -> data = number;

    if (NULL == *hptr) {
        temp -> next = *hptr;
        temp -> prev = *hptr;
        *hptr = temp;
    } else {
        DL *ptr = *hptr;

        while (NULL != ptr -> next)
            ptr = ptr -> next;
        
        temp -> prev = ptr;
        temp -> next = ptr -> next;
        ptr -> next = temp;
    }
    
    return SUCCESS;
}

