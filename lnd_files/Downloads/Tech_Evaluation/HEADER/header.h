/* Header Files */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio_ext.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>
#include<limits.h>

/* Macros */
#define MAX_BUF 256
#define INT_SIZE 10

/* Enumeration constants used for switch cases */
enum main_cases { ASSIGNMENT = 1, ASSESSMENT, EXIT };
enum asse_cases { ASSE_FUN = 1, ASSE_MAIN, ASSE_COMPILE, ASSE_RUN, ASSE_VALIDATE, ASSE_BACK, ASSE_QUIT };
enum options{ STD_FUN = 1, MAIN_FUN, SUB_FUN, COMPILE, RUN, VALIDATE, BACK, QUIT };
enum sub_func{ LIST = 1, CREATE , DELETE, PREV_PAGE, ABORT };

/***********  FUNCTION PROTOTYPES ***********************/
/* assignment_page.c */
int assignment_page( void );

/* assessment_page and functions */
int assessment_page( void );
int asse_compile(int assessment_no);
int asse_execute(int assessment_no);
int asse_test_case_match(int assessment_no);

/* sub_function.c */
int sub_func_page( int assignment_no );
int list_sub_func( int assignment_no );
int create_sub_func( int assignment_no );
int delete_sub_func( int assignment_no );

/* main_function.c */
int main_function(int assignment_no, int question_no);

/* standard_funciton.c */
int standard_function(int assignment_no, int question_no);

/* compile.c */
int compile (int assignment_no, int question_no);

/* execute.c */
int execute (int assignment_no, int question_no);

/* test_case_match */
int test_case_match(int assignment_no, int question_no);

/* validation.c */
int intval(char *str);
int file_name_val(char *str);
int strval(char *str);
int rm_new_line(char *str);

/* Read Input functions */
int myatoi(char *s);
char *read_input(char *input);
int scan_int(char *input, int min_range, int max_range);

/*******************************************************************/
