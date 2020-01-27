/* Header file */

#include <stdio.h>

#define  EMPTY    -1
#define  SIZE     10

#define  PUSH     1
#define  POP      2
#define  DISPLAY  3
#define  PEAK     4
#define  ISFULL   5
#define  ISEMPTY  6
#define  EXIT     7 


int get_number(void);
int validation(const char *str, char *buff);
int my_atoi(const char *str);

int push(int *stack, int number);
int pop(int *stack);
void display(int *stack);
void peak(void);
void isfull(void);
void isempty(void);
