#include "header.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;

int help = 0;

FILE *fptr;
FILE *iptr;
FILE *optr;

int main(int argc, char *argv[])
{
    if (4 != argc) {
        printf("Usage: %s <i/p_fname> <idx_fname> <o/p_fname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t th_id1;
    pthread_t th_id2;

    int status;
    int n1 = 0;
    int n2 = 0;

    if (NULL == (fptr = fopen(argv[1], "r")))
        handle_err("fopen");

    if (NULL == (iptr = fopen(argv[2], "a+")))
        handle_err("fopen");

    if (NULL == (optr = fopen(argv[3], "a+")))
        handle_err("fopen");

    fprintf(optr, "---------------------------------------------------\n");
    fprintf(optr, " RECORD ID | Seq. Access Time | Random Access Time\n");
    fprintf(optr, "---------------------------------------------------\n");

    status = pthread_create(&th_id1, NULL, thread_fun, &n1);
    if (0 != status)
        handle_err("pthread_create");

    status = pthread_create(&th_id2, NULL, thread_fun, &n2);
    if (0 != status)
        handle_err("pthread_create");

    pthread_exit(NULL);
    return 0;
}

void *thread_fun(void *sync) {
    
    int syn = *(int *)sync;
    long stdid;
    long temp;
    time_t time;
    double time_taken;
    char *str;

    if (NULL == (str = (char *) malloc(sizeof(char) * SIZE)))
        handle_err("malloc");
    
    pthread_mutex_lock(&lock);

    if (help != syn) {
        if (syn == 0)
            pthread_cond_wait(&cond1, &lock);
        else
            pthread_cond_wait(&cond2, &lock);
    }

    while (EOF != fscanf(iptr, "%ld", &temp)) {
        time = clock();

        if (0 == syn) {

            while (EOF != fscanf(fptr, "%s", str)) {
                stdid = atoi(str);

                if (stdid == temp) {
                    time = clock() - time;
                    time_taken = ((double) time) / CLOCKS_PER_SEC;
                    fprintf(optr, "  %ld     |  %lf sec     ", stdid, time_taken);
                    rewind(fptr);
                    break;
                }
            }

        } else if (1 == syn) {
            fseek(fptr, temp, SEEK_SET);
            time = clock() - time;
            time_taken = ((double) time) / CLOCKS_PER_SEC;
            fprintf(optr, " %lf sec \n", time_taken);
            rewind(fptr);
        }

        if (help == 0) {
            help = 1;
            pthread_cond_signal(&cond2);
        } else if (help == 1) {
            help = 0;
            pthread_cond_signal(&cond1);
        }
        pthread_mutex_unlock(&lock);

    }

/*
   if (help == 0) {
        help = 1;
        pthread_cond_signal(&cond2);
    } else if (help == 1) {
        help = 0;
        pthread_cond_signal(&cond1);
    }
    pthread_mutex_unlock(&lock);
*/
    fprintf(optr, "---------------------------------------------------\n");
    fclose(optr);
    fclose(iptr);
    fclose(fptr);
    return NULL;
}
