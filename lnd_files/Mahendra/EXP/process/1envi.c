#include <stdio.h>  
#include <stdlib.h>

int main(void)
{
    char *s;

    s = getenv("PWD");

    if (s == NULL)
        printf("variable not found\n");
    else
        printf("value is \"%s\"\n", s);

    exit(EXIT_SUCCESS);
}
