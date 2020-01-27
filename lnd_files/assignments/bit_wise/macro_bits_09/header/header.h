#include <stdio.h> // including the standard I/O header

#include <stdlib.h> // including the standar lib header

#define SIZE 100 // macro for providing size of an array

#define LIMIT 4294967295UL // macro for unsigned integer range

/* funtion prototype for get a nnumber from the user */
unsigned int get_number (void);

/* function prototype for validadting the user entered data */
int validation (const char *str, char *buff);

/* function prototype for converting the raw data 
   to an unsigned integer type */
int my_atoi (const char *str);

/* function prototype for printing integer number to a binary format */
void binary_print (unsigned int num);

/* function prototype for switch function */
void switch_fun ();

#define min_max(num1, num2) (((num1 - num2) >> 31) & 1) ? \
                                printf("min_num = %d\n", num2) : \
                                printf("max_num = %d\n",num1) // 9(a)

#define clear_right_most_setbit(num) num & (num - 1) // 9(b)

#define clear_left_most_setbit(num) (num ^ (num - 1)) & num // 9(c)

#define set_right_most_clearedbit(num) num & (num + 1) // 9(d)

#define set_left_most_clearedbit(num)  0

#define set_clear_bits(num, spos, dpos)  ((1 << (spos + 1 - dpos)) - 1) \
                                            | num // 9(f)

#define clear_set_bits(num, spos, dpos)  ~((1 << (spos + 1 - dpos)) - 1) \
                                            & num // 9(g)

#define toggle_bits(num, spos, dpos) (((1 << (spos + 1 - dpos)) - 1)\
