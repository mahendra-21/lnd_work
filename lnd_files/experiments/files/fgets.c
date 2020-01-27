#include <stdio.h>

int main(void)
{
    char pvar[4] = {0};
    char pvar1[4] = {0};
    
    puts("enter data");
    fgets(pvar, 4, stdin);
    puts("enter data");
    fgets(pvar1, 4, stdin);

    puts(pvar);
    puts(pvar1);
}
