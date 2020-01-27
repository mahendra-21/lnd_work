#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *temp;
    char *temp_len;
    int len;
    int len1;
    int tem_len;
    char ch = 'a';

    char *str = (char *) malloc(128 * sizeof (char));
    if (NULL == str) {
        printf("malloc failed\n");
        return 0;
    }

    printf("enter a string: ");
    fgets(str, 128, stdin);
    
    temp = str;
    while (*temp++)
        if (*(temp - 1) == '\n')
            *(temp - 1) = *temp;

    temp = str;
    for (len = 0; *temp; temp++, len++);

    str = (char *) realloc(str, len);
    if (NULL == str)
        printf("realloc size is same what malloc given previously\n");

    temp = str;
    for (tem_len = 0; *str; str++, tem_len++) {

        if (*str == ch) {
            
            temp_len = str;
            for (len1 = 0; *temp_len; temp_len++, len++);

            str = (char *) realloc(str, (len1 + tem_len + 1));
            if (NULL == str)
                printf("realloc size is same what malloc given previously\n");

            for (len1 = len1 + tem_len; *(str + len1); len1--) {
                if (len1 == tem_len)
                    *(str + tem_len + 1) = ch;
                else
                    *(str + len1 + 1) = *(str + len1);
            }
        }
    }
    
    return 0;
}
