#include <stdio.h>

typedef struct {
    unsigned int a;
    char str[10];
    float flt;
} st;

int main(int argc, char **argv)
{
    st S = {10000, "mahendra", 1234.67}, S1;

    FILE *fp;

    if (2 != argc) {
        puts("USAGE: ./a.out file_name");
        return 0;
    }

    fp = fopen(argv[1], "w+");

    if (NULL == fp) {
        puts("FILE is not created");
        return 0;
    }

    //fprintf(fp, "%u\n%s\n%f", S.a, S.str, S.flt);

    fwrite(&S, sizeof(S), 1, fp);

    rewind(fp);

    fread(&S1, sizeof(S1), 1, fp);

    printf("%u\n%s\n%f\n", S1.a, S1.str, S1.flt);

    return 0;
}
