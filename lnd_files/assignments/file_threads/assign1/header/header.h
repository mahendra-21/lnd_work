/* header.h */

#include <stdio.h>
#include <stdlib.h>

#define STUDENT_ID  10  // Size of Student ID
#define NAME        128 // Size of Student Name
#define handle_err(msg) \
            do { perror(msg); exit(EXIT_FAILURE); } \
            while (0)

typedef struct std {
    int std_id;
    char *std_name;
    unsigned char date;
    unsigned char month;
    short year;
    unsigned char sub1;
    unsigned char sub2;
    unsigned char sub3;
    unsigned char sub4;
    unsigned char sub5;
} st_std;

/* FD - Function Declaration */
st_std *create(void); // FD for creating a student structure
char *itoa(int); // FD for changing integer to string
char *my_strrev(char *); // FD for string reverse
char *my_strcat(char *, const char *); // FD for string cancatination
void std_data(std_data *, int, FILE *); // FD for creating std_data_base
void create_id(int); // FD for creating index file
