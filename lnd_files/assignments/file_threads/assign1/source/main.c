/*  main function */

#include "../header/header.h"

int main(int argc, char *argv[])
{
    if (3 != argc) {
        printf("Usage: %s <# of entries> <file.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    st_std *std = create();

    int loop;
    int no_records;
    FILE *fptr;

    if (NULL == (fptr = fopen(argv[1], "a")))
        handle_err("fopen");

    no_records = myatoi(argv[1]);
    if (0 == no_records) {
        printf("# of records is invalid\n");
        exit(EXIT_FAILURE);
    }

   fprintf(fptr, "----------------------------------------------------------");

