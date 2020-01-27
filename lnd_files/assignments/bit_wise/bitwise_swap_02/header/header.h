#include <stdio.h>
#define SIZE 100
#define LIMIT 4294967295
 
int validation(const char *str, char *buff);

int my_atoi(const char *str);

void binary_print(unsigned int num);

void bit_swap(unsigned int *num1, unsigned int *num2,
                    unsigned int src_pos, int dest_pos);
