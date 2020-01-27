#include <stdio.h>

int main(void)
{
    enum e1{c11, c12} en1;
    enum e2{c21, c22} en2;

    en1 = c11;
    en2 = c22;

    if(en1 <  en2) 
        printf("SUCCESS\n");
    else
        printf("FAILURE\n");

        return 0;
}
