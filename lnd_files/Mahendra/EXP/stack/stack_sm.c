#include <stdio.h>

int main(void)
{
    char str[4]  = "mahi";
    /* 
     *  *** stack smashing detected ***: ./stack_sm terminated
     *           Aborted (core dumped)
     */

    str[4] = 'C';

    return 0;
}
