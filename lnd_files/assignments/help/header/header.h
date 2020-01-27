/* Creating own Header file for BANK Application */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 128
#define MAX 30
#define NMAX 10

struct bank {
    char account_holder_name[MAX];
    char account_type[MAX];
    char account_number[MAX];
    long int balance;
};

long int get_number (void);

int validation(const char *str, char *buff);

long int my_atoi(const char *str);

int validation (const char *str, char *buff);

int validation_acc_hld_name (char *rawdata);

int validation_account_type (char *rawdata);

int validation_account_number (char *rawdata);

int validation_balance (long int balance);

int print_acc_hldr_names (struct bank *data, int list); 
