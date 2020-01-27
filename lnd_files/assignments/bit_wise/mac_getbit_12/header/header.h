#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define LIMIT 4294967295
 

#define getbits(num, pos, n_bits)   num = ((((1 << n_bits) - 1) << \
                                                  pos) & num) >> pos

int validation(const char *str, char *buff);

int my_atoi(const char *str);

void binary_print(unsigned int num);
