#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: ./a.out input file & idx file\n");
        return 0;
    }

    FILE *fptr = NULL;
    FILE *iptr = NULL;
    FILE *optr = NULL;

    if ( NULL == (fptr = fopen(argv[1], "a+"))) {
        printf("Input file is not present\n");
        return 0;
    }

    if (NULL == (iptr = fopen(argv[2], "a+"))) {
        printf("idx file is not present\n");
        return 0;
    }

    if (NULL == (optr = fopen("sdb.ts", "a"))) {
        printf("sdb.ts file is not created\n");
        return 0;
    }

    int stdid;
    char *str = (char *) malloc(20);
    int temp;
    char ch;
    short help = 0;
    int ret;

    clock_t time;

    fprintf(optr, "--------------------------------------------------------\n");
    fprintf(optr, "RECORD ID  |  Seq. Access time  |  Random Access Time\n");
    fprintf(optr, "--------------------------------------------------------\n"); 

    while ((fscanf(iptr, "%d", &temp)) != EOF) {
        time = clock();

        if (help == 0) {

            while ((fscanf(fptr, "%s", str)) != EOF) {            

                while (ch = fgetc(fptr)) 
                    if (ch == '\n')
                        break;

                stdid = atoi(str);
                if (temp == stdid) {
                    time = clock() - time;
                    double time_taken = ((double)time) / CLOCKS_PER_SEC;
                    fprintf(optr, " %d         |  %lf sec    ", stdid, time_taken);
                    rewind(fptr);
                    help++;
                    break;
                }
            }

        } else if (1 == help) {
            fseek(fptr, temp, SEEK_SET);
            time = clock() - time;
            double time_taken = ((double)time) / CLOCKS_PER_SEC;
            fprintf(optr, "| %lf        \n", time_taken);
            rewind(fptr);
            help = 0;
        }

    }
    
    fprintf(optr, "--------------------------------------------------------\n");
    printf("temp = %d stdid = %d\n", temp, stdid);

    return 0;
}
