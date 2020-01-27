#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define SIZE    128 // Macro for SIZE of an array
#define FAILURE 0   // Macro for return 0 upon any failure cases
#define SUCCESS 1   // Macro for return 1 upon success

/* Declaring enumeration constant's to use in switch case */
typedef enum {
    exit, 
    linear, 
    binary
}; 

int get_number(void); // For get a number from stdin

int validation(const char *str, char *buff); //validadting the stdin data

int my_atoi(const char *str); // Converting string into a number

int array_inputs(int arr[], int num_ele); // Function for taking inputs

int switch_case(int arr[], int num_ele);
    // Function for switch-case to select and perform a task

int print_array(int arr[], int num_ele);
