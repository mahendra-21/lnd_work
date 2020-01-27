#include <header.h>

void reverse_list(SL *hptr) {

    SL *temp1 = hptr;
    SL *temp2 = hptr;

    temp1 -> link = NULL;

    while (NULL != hptr) {
        hptr = hptr -> link;
        temp2 -> link = temp1;
        temp1 = temp2;
        temp2 = hptr;
    }

    hptr = temp1;
}
