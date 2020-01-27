#include <stdio.h>

#include <stdlib.h>

#define SIZE 100

#define LIMIT 4294967295
 
int validation (const char *str, char *buff);

int my_atoi (const char *str);

void binary_print (unsigned int num);

void switch_fun (unsigned int num);

unsigned int cnt_leading_set_bits (unsigned int num);

unsigned int cnt_leading_cleared_bits (unsigned int num);

unsigned int cnt_trailing_set_bits (unsigned int num);

unsigned int cnt_trailing_cleared_bits (unsigned int num);
