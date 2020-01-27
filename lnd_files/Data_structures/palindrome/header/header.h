#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define SIZE    128
#define SUCCESS 1
#define FAILURE 0

typedef struct sll {
    int data;
    struct sll *link;
} SL;

int get_number (void);
int validation (const char *str, char *buff);
int my_atoi (const char *str);

SL *create_node(void);
int display_list (SL *hptr);
int node_count (SL **hptr);
int insert_begin(SL **hptr, int data);
int palin_check(SL *hptr, int count);
void reverse_list(SL *hptr);
