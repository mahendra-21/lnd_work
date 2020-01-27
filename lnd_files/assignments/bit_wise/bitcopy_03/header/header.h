#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define LIMIT 4294967295
 
int validation(const char *str, char *buff);

int my_atoi(const char *str);

void binary_print(unsigned int num);

void bitcopy(unsigned int s_num, unsigned int *d_num, 
            unsigned int n_bits, unsigned int s_pos, unsigned int d_pos);
