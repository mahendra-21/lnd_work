#include <stdio.h>
#include <stdlib.h>

#define LINE 80

int main(int argc, char **argv)
{
    FILE *sfp; // sfp, dfp - is a handler's to work on a stream
    FILE *dfp;

    char *str = (char *) malloc(LINE * sizeof(char));

    if (3 != argc) {
        puts("USAGE: ./a.out src_file dest_file");
        return 0;
    }

    sfp = fopen(argv[1], "r");

    if (NULL == sfp) {
        puts("FILE is Not Present");
        return 0;
    }

    dfp = fopen(argv[2], "w");

    if (NULL == dfp) {
        puts("FILE is Not Created");
        return 0;
    }

    while (fgets(str, LINE, sfp) != NULL) {
        fputs(str, dfp);
    }

    return 0;
}
