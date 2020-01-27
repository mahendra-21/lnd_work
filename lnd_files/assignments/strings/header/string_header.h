/* Header file for the string operations */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 128 //defining a macro for size of character arrays

unsigned int get_numer (void); // function declaration for geting a number
                               // from user in stdin 

int validation (const char *str, char *buff); // validating the stdin string
                                              // as user requirements

int my_atoi (const char *str); // own atoi function for converting 
                               // string to Number

void switch_fun (int option); // switch fun to perform a string operation

char *get_string (void);

void str_valid (const char *str, char *buff);

void my_strncpy(char *dest, const char *src, int num);
