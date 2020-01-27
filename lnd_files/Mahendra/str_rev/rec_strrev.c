#include <stdio.h>
#include <stdlib.h>

void rec_strrev(char *str, int len) {
    
    static int help = 0;
//    char temp;

    if (len < help) return;

    *(str + help) = *(str + help) + *(str + len)
                        - (*(str + len) = *(str + help));
/*    temp = *(str + help);
    *(str + help) = *(str + len);
    *(str + len) = temp;  */
    help++;    

    rec_strrev(str, --len);
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
    int len;
    for (len = 0; *temp; temp++, len++)
        if ('\n' == *temp) {
            *temp = *(temp + 1);
            len -= 1;
        }

    rec_strrev(str, len - 1);
    printf("str -> %s\n", str);
    return 0;
}
