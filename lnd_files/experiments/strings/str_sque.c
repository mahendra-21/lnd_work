#include <stdio.h>

void str_sque(char *str);

int main()
{
    char  str[] = "maaaheenddraa";

    printf("before = %s\n", str);
   
    str_sque(str);

    printf("after = %s\n", str);
    return 0;
}

void str_sque(char *str) {
/*
    int help = 0;
    int len = 0;
    int start = 0;
    int temp = 0;

    for (len = 0; str[len]; len++);

    for (; (len - temp) > help; ) {
        
        if (str[help] == str[help + 1]) {

            for (start = help; (len - temp) > start; start++) {

                str[start] = str[start + 1];

            }
            
            temp++;
           
        } else {

            help++;

        }
        
    }

    */

    char *temp = str;

    while (*str) {
        *temp = *str++;
        if (*temp != *str)
            temp++;
    }
    *temp = *str;
}
