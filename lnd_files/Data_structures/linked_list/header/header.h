#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define SIZE 128
#define FAILURE 0
#define SUCCESS 1

typedef struct sll {
    int data;
    struct sll *link;
} SL;

typedef struct dll {
    int data;
    struct dll *prev;
    struct dll *next;
} DL;

int get_number (void);
int validation (const char *str, char *buff);
int my_atoi (const char *str);

/********  SINGLE LINKED LIST INSERT  ********/
int sll_insert_switch (void);
SL *sll_create_node (void);
int sll_display_list (SL *hptr);
int sll_node_count (SL **hptr);
int sll_insert_begin (SL **hptr);
int sll_insert_end (SL **hptr);
int sll_insert_at_given_pos (SL **hptr, int pos);
int sll_insert_before_given_pos (SL **hptr);
int sll_insert_after_given_pos (SL **hptr);
int sll_insert_before_given_number (SL **hptr);
int sll_insert_after_given_number (SL **hptr);
void *rec_rev(SL *head);

/********  SINGLE LINKED LIST DELETE  ********/

/********  DOUBLE LINKED LIST INSERT  ********/
int dll_insert_switch (void);
DL *dll_create_node (void);
int dll_display_list (DL *hptr);
int dll_node_count (DL **hptr);
int dll_insert_begin (DL **hptr);
int dll_insert_end (DL **hptr);
int dll_insert_at_given_pos (DL **hptr, int pos);
int dll_insert_before_given_pos (DL **hptr);
int dll_insert_after_given_pos (DL **hptr);
