#include <header.h>

int insert_after_given_number(SL **hptr,int num,  int number) {
    SL *node = create_node();

    if (NULL == node)    return FAILURE;

        
    /* If positoon is one or head pointer is null insert the node at 
       begining. Other-wise entering into the else part and traversing 
       the list upto (pos - 1)
     */
    SL *ptr = *hptr;
    if (NULL == *hptr)  display_list(ptr);

    while (num != ptr -> data) 
        ptr = ptr -> link;

    node -> data = number;
    node -> link = ptr -> link;
    ptr -> link = node;

    return SUCCESS;
}
