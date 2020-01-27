#include <header.h>

int sll_insert_at_given_pos(SL **hptr, int pos) {
    SL *node = sll_create_node();

    if (NULL == node)    return FAILURE;

    SL *ptr = *hptr;
    int loop = 1;
    int count = sll_node_count(&ptr);

    if (pos > (count + 1)) {
        printf("Given position is invalid. It should be like"
                "(pos(%d) <= nodes(%d + 1)\n",
                pos, count);
        exit(0);
    }
    /* If positoon is one or head pointer is null insert the node at 
       begining. Other-wise entering into the else part and traversing 
       the list upto (pos - 1) */
    if ((1 == pos) || (NULL == *hptr)) {
        sll_insert_begin(hptr);
    } else if (count < pos) {
        sll_insert_end(hptr);
    } else {
        ptr = *hptr;
        
        while (loop < (pos - 1)) {
            ptr = ptr -> link;
            loop++;
        }

        printf("Enter the data: ");
        node -> data = get_number();

        node -> link = ptr -> link;
        ptr -> link = node;
    }

    return SUCCESS;
}

int dll_insert_at_given_pos(DL **hptr, int pos) {
    DL *node = dll_create_node();

    if (NULL == node)    return FAILURE;

    DL *ptr = *hptr;
    int loop = 1;
    int count = dll_node_count(&ptr);

    if (pos > (count + 1)) {
        printf("Given position is invalid. It should be like"
                "(pos(%d) <= nodes(%d + 1)\n",
                pos, count);
        exit(0);
    }
    /* If positoon is one or head pointer is null insert the node at 
       begining. Other-wise entering into the else part and traversing 
       the list upto (pos - 1) */
    if ((1 == pos) || (NULL == *hptr)) {
        dll_insert_begin(hptr);
    } else if (count < pos) {
        dll_insert_end(hptr);
    } else {
        ptr = *hptr;
        
        while (loop < (pos - 1)) {
            ptr = ptr -> next;
            loop++;
        }
        printf("Enter the data: ");
        node -> data = get_number();

        node -> prev = ptr;
        node -> next = ptr -> next;
        ptr -> next = node;
        ptr -> next -> prev = node;
    }

    return SUCCESS;
}
