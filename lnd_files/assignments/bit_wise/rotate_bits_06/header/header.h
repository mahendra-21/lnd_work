#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define LIMIT 4294967295

#define BITS 31

#define r_left(num)     (num << 1) | (num >> BITS)

#define r_right(num)    (num >> 1) | (num << BITS)

#define r_nbits_left(num, n_bits) (num << n_bits) \
                                    | (num >> (BITS - n_bits))

#define r_nbits_right(num, n_bits)  (num >> n_bits) \
                                    | (num << (BITS - (n_bits - 1)))
         
int validation(const char *str, char *buff);

int my_atoi(const char *str);

void binary_print(unsigned int num);

void switch_fun(unsigned int num, unsigned int pos);
