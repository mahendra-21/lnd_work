#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define LIMIT 4294967295
 
int validation(const char *str, char *buff);

int my_atoi(const char *str);

void binary_print(unsigned int num);

void setbits(unsigned int *result, unsigned int num, 
                            unsigned int n_bits, unsigned int pos);
