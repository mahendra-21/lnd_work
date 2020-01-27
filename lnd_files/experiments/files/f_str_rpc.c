#include <stdio.h>

#define SIZE 80

int my_strcmp(const char *ptr, const char *qtr) {
    
    while (*ptr)
        if (*ptr++ != *qtr++)
            break;
    
    if (*ptr == *qtr)   return 0;
    else    return 1;
}

int main(int argc, char *argv[]) 
{
    if (4 != argc) {
        printf("Usage: ./a.out fname sstr dstr\n");
        return 0;
    }

    FILE *fptr = NULL;
    
    fptr = fopen(argv[1], "r+");
    
    if (NULL == fptr) {
        printf("File is not present\n");
        return 0;
    }

    char arr[SIZE];
    int len = 0;

    while ((fscanf(fptr, "%s", arr)) != EOF) {

        if (!(my_strcmp(arr, argv[2]))) {
                    for (len = 0; arr[len]; len++);
                    fseek(fptr, -len, SEEK_CUR);
                    fputs(argv[3], fptr);
        }

    }

    return 0;
}
