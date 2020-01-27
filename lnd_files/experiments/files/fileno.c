#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fptr;
    int inc = 0;

    while (1021 != inc++) {
        fptr = fopen("test.txt", "w+"); 
        if (NULL == fptr) {
            printf("fopen error : %s\n", (char *) strerror((int) fptr));
            break;
        }
    }

    while (0 != fptr -> _fileno) {
        printf("file # -> %d\n", fptr -> _fileno);
        fptr = fptr -> _chain;
    }
    printf("file # -> %d\n", fptr -> _fileno);

    return 0;
}
