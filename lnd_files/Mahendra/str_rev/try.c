#include <stdio.h>
#include <stdlib.h>

char *rec_strrev(char *str) {
    static char help = 0;
    static char temp[128];
    
    if (*str) {
        rec_strrev(str + 1);
        temp[help++] = *str;
    }
    return temp;
}

int main(void)
{
    char *str = (char *) malloc(127);
    if (NULL == str) {
        printf("malloc failed\n");
        return 0;
    }
   
    printf("enter the string: ");
    __fpurge(stdin);
    fgets(str, 127, stdin);

    char *temp = str;
    for (; '\n' != *temp; temp++);
    *temp = *(temp + 1);
    
    str = rec_strrev(str);
    printf("str -> %s\n", str);
    return 0;
}
