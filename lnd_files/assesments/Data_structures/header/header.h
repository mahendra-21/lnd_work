/* header.h */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define MAX_INT 4294967295U // defining macro for max unsigned int range
#define SIZE 128
#define FLAG (void *)-1
#define OKAY 1

typedef struct del {
    int data;
    struct del *prev;
    struct del *next;
}DEL;

int get_number(void);
int validation(char *str);
int my_atoi(const char *str);

DEL *create_node(void);
DEL *insert_node(void);
DEL *delete_root(DEL *root);
void print_bst(DEL *root);
