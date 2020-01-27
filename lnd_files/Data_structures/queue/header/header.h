#include <stdio.h>

#define SIZE    10
#define EMPTY   -1

#define ENQUE   1
#define DEQUE   2
#define DISPLAY 3
#define EXIT    4

int get_number(void);
int validation(const char *str, char *buff);
int my_atoi(const char *str);

int enqueue(int *queue, int number);
int dequeue(int *queue);
void display(int *queue);
