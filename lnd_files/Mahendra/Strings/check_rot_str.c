#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *validate_string(char *str);
int check_rotate(char *str, char *rstr);

int main(void)
{
    char *str1;
    char *str2;
    int ret;

    if (NULL == (str1 = (char *) malloc(sizeof(char) * 128))) {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    if (NULL == (str2 = (char *) malloc(sizeof(char) * 128))) {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the string1: ");
    if (NULL == fgets(str1, 128, stdin)) {
        printf("fgets failed\n");
        exit(EXIT_FAILURE);
    }

    fflush(stdin);
    
    printf("Enter the string2: ");
    if (NULL == fgets(str2, 128, stdin)) {
        printf("fgets failed\n");
        exit(EXIT_FAILURE);
    }
    fflush(stdin);

    str1 = validate_string(str1);
    str2 = validate_string(str2);

    ret = check_rotate(str1, str2);

    if (0 == ret)
        printf("Strings are same\n");
    else
        printf("Strings are not same\n");

    exit(EXIT_SUCCESS);
}

char *validate_string(char *str) {
    if (NULL == str)
        return NULL; // String is empty

    char *temp = str;
    
    while (*str++)
        if ('\n' == *(str - 1))
            *(str -1) = *str;

    return temp;
}

int check_rotate(char *str, char *rstr) {
    int oloop;
    int iloop;
    int len;
    int flag = 0;
    char ch;

    for (oloop = 0; *(str + oloop); oloop++);
    for (iloop = 0; *(rstr + iloop); iloop++);

    if (oloop != iloop)
        return 1; // If strings are not same

    len = oloop;
    
    for (oloop = 0; oloop < len; oloop++) {

        for (iloop = 0; *(str + iloop); iloop++) {
            if (iloop == 0)
                ch = *(str + iloop); // Storing first character in string

            if ('\0' ==  (*(str + iloop + 1)))
                *(str + iloop) = ch;
            else
                *(str + iloop) = *(str + iloop + 1);
        }

        if (0 == (strcmp(str, rstr)))
            flag++; // Increment flag if strings are same
    }
    
    if (1 == flag)
        return 0; // If strings are same
    else
        return 1; // If strings are not same

}
