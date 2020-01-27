#include <stdio.h>  
#include <stdlib.h>

extern char **environ; /* environment array (not in any header */

int main(void)
{
    int i;
    printf("size -> %d\n", sizeof **environ);
//    for (i = 0; environ[i] != NULL; i++)
//        fprintf(stdout, "%s\n", environ[i]);
    exit(EXIT_SUCCESS);
}
