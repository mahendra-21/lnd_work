#include <header.h>

int insert_begin(SL **hptr, int number) {

    SL *temp = create_node();

    if (NULL == temp)   return FAILURE;
   
    temp -> data = number;

    temp -> link = *hptr;
    *hptr = temp;

    return SUCCESS;
}

