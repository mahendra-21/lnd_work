/* 
 * Creating a new file using fopen() library function,
 * Here, inputs are taking as the command line arguments.
 * And writing content into the created file.
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fptr;

    if (2 != argc) {
        puts("USAGE: ./a.out file_name");
        return 0;
    }

    fptr = fopen(argv[1], "a+");

    if (NULL != fptr) {
        printf("fptr = %p\n", fptr);
        puts("file is created");
    } else {
        puts("file is not created");
    }

    return 0;
}
