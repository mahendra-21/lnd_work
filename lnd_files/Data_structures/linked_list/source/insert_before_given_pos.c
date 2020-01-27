#include <header.h>

int sll_insert_before_given_pos(SL **hptr) {

    printf("Enter the position: ");
    int pos = get_number();

    SL *ptr = *hptr; 
    int count = sll_node_count(&ptr);

    if (pos > count) {
        printf("Given position is invalid. It should be like"
                "(pos(%d) <= nodes(%d))\n",
                pos, count);
        exit(0);
    }

    if ((1 == pos) || (NULL == *hptr)) {
        return sll_insert_begin(hptr);
    } else {
        return sll_insert_at_given_pos(hptr, pos);
    }

    return SUCCESS;
}

int dll_insert_before_given_pos(DL **hptr) {

    printf("Enter the position: ");
    int pos = get_number();

    DL *ptr = *hptr;
    int count = dll_node_count(&ptr);

    if (pos > count) {
        printf("Given position is invalid. It should be like"
                "(pos(%d) <= nodes(%d))\n",
                pos, count);
        exit(0);
    }

    if ((1 == pos) || (NULL == *hptr)) {
        return dll_insert_begin(hptr);
    } else {
        return dll_insert_at_given_pos(hptr, pos);
    }

    return SUCCESS;
}
