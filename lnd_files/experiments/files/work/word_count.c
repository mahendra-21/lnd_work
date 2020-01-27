#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp; // fp - is a handler to work on stream

    char *str = (char *) malloc(20 * sizeof(char));
    
    int count = 0;

    if (2 != argc) {
        puts("USAGE: ./a.out file_name");
        return 0;
    }

    fp = fopen(argv[1], "r");

    if (NULL == fp) {
        puts("FILE is Not Present");
        return 0;
    }

    while (fscanf(fp, "%s", str) != EOF) {
        count++;
        printf("%d) %s\n", count, str);
    }

    printf("---------> Total no of words in file = %d\n", count);

    return 0;
}
