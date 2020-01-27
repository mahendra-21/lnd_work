#include <stdio.h>
#include <stdlib.h>

#define SIZE 128

int validating_fgets(char *rawdata);
char *my_strtok(char *str, const char *deli);

int main(void)
{
    char *str = (char *) malloc(SIZE * sizeof(char));
    char *deli = (char *) malloc(SIZE * sizeof(char));
    char *str_ret = NULL;
   
    puts("enter a string which is having delimeters:");
    fgets(str, SIZE, stdin);
    __fpurge(stdin);

    puts("enter a delimeters:");
    fgets(deli, SIZE, stdin);
    __fpurge(stdin);
    
    if ((0 == validating_fgets(str)) || (0 == validating_fgets(deli))) {
        puts("fgets() failed to read data from the user") ;
        return 0;
    }
    
    puts("<-----------------   string tokens   ---------------->");

    str_ret = (char *) my_strtok(str, deli);

    while (NULL != str_ret) {

        puts(str_ret);

        str_ret = (char *)my_strtok(NULL, deli);

    }

//  getchar();
            
    return 0;
}

