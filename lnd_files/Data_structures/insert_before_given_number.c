#include <header.h>

int insert_before_given_number(SL **hptr,int num,  int number) {
    SL *node = create_node();

    if (NULL == node)    return FAILURE;

    SL *ptr = *hptr;
    int count = node_count(hptr);

    printf("count = %d\n", count);

    if (0 == count) {
        printf("Insert before a given number is not possible."
                " It should have minimum one list\n");
        exit(0);
    }

    ptr = *hptr;
    node -> data = number;

    if (num == ptr -> data) {
        node -> link = *hptr;
        *hptr = node;
    } else {
        SL *temp = NULL;

        while ((num != ptr -> data)) {
            temp = ptr;
            ptr = ptr -> link;
        }

        node -> link = ptr;
        temp -> link = node;
    }

    return SUCCESS;
}
