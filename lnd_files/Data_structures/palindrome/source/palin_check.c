#include <header.h>

int palin_check(SL *hptr, int count) {

    SL *temp1 = NULL;
    SL *temp2 = NULL;
    SL *temp3 = NULL;

    int temp_count = 0;
    int temp_count1 = 0;
    int loop1 = count;
    int loop2 = 0;

    temp1 = hptr;
    temp2 = temp1 -> link;
    temp3 = temp1;

    while (loop1--) {
        loop2 = loop1;

        while (loop2--) {

            if (temp1 -> data != temp2 -> data) {
                temp_count1++;

                if (NULL == temp2)  break;

                temp2 = temp2 -> link;
            } else {
                temp_count++;
                
                if (NULL == temp2)  break;
                
                temp2 = temp2 -> link;
            }

        }

        temp1 = temp3;
        temp2 = temp1 -> link;

        if (NULL == temp2) break;

        temp3 = temp1;
    }
    printf("count1 = %d\n", temp_count1); 
    if (temp_count1 == count) return FAILURE;

    if ((temp_count == (count - 2)) || (temp_count == count)
         || (temp_count == (count + 2)) || (temp_count == (count - 1))
         || (temp_count == (count - 4)) || (temp_count == (count - 3))) {
        return SUCCESS;
    } else {
        return FAILURE;
    }
}
