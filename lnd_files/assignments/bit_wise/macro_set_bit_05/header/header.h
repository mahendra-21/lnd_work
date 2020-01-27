#include <stdio.h>
#define SIZE 100
#define LIMIT 4294967295

#define bit_ts(num, pos)  ((num >> pos) & 1) ? num : (num | (1 << pos))
 
int validation(const char *str, char *buff);

int my_atoi(const char *str);

void binary_print(unsigned int num);
