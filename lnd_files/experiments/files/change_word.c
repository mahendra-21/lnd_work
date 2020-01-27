#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128
#define handle_err(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[])
{
    if (4 != argc) {
        printf("Usage: %s <f_name> <ext_str> <new_str>\n", argv[0]);
        return 0;
    }

    FILE *fp;
    char *str;

    if (NULL == (str = (char *) malloc(sizeof(char) * SIZE)))
        handle_err("malloc");

    fp = fopen(argv[1], "r+");
    if (NULL == fp)
        handle_err("fopen");

    while (EOF != fscanf(fp, "%s", str)) {
        
        fprintf(stdout, "%s\n", str);
        if (0 == strcmp(str, argv[2])) {
            fseek(fp, -strlen(str), SEEK_CUR);
//            fprintf(fp, "%s", argv[3]);
            fwrite(argv[3], strlen(argv[3]), 1, fp);
        }

    }
    handle_err("fscanf");

    fclose(fp);
    return 0;
}
