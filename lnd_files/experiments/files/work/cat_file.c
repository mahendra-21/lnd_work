#include <stdio.h>
#include <stdlib.h>

#define LINE 80

int main(int argc, char **argv)
{
    FILE *sfp; // sfp, dfp - is a handler's to work on a stream
    FILE *dfp;

    char *str = (char *) malloc(LINE * sizeof(char));

    if (2 != argc) {
        puts("USAGE: ./a.out file_name");
        return 0;
    }

    sfp = fopen(argv[1], "r");

    if (NULL == sfp) {
        puts("FILE is Not Present");
        return 0;
    }

    while (fgets(str, LINE, sfp) != NULL) {
        fputs(str, stdout);
        fflush(stdout);
    }

    return 0;
}
