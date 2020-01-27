/* getting a number from the user */
#include <header.h>

int get_number (void) {

    char raw_data[SIZE] = {0}; //character array for storing the raw data

    char buff[SIZE] = {0};     /* character array for storing data to send 
                                  atoi() function */

    unsigned char ret = 0;     /* character variable for asigning the
                                  validation() function return value's */
    int count = 0;

L1: __fpurge(stdin); //to clear the info in the stdin buff
    /* calling fgets() function for getting raw data 
       from standard input device */
    fgets(raw_data, SIZE, stdin);

    fflush(stdin); // fflush() function for clear the data in stdin
    
    /* validating the fgets() funtion if fgets() failed to read 
       the data from the user or if user not entered the data it return the
       NULL in the string */
    if (('\0' == *raw_data) || ('\n' == *raw_data)) {
        count++;
        puts("<--- fgets() is failed to read data --->");
        puts("      <--- enter data again --->        ");
        
        if (5 == count) {
            system("clear");
            printf("-----> Sorry, I given many chances to you..!\n");
            printf("-----> Give proper Inputs nexttime\n");
            exit(0);
        }

        goto L1;
    }

    ret = validation(raw_data, buff);   // calling the validation funtion
  
    /* validating the raw data if data is not in required format
       printing a message like Invalid & asking user to re-enter
       the data again */
    if (1 == ret) {
        puts("<---** INVALID DATA **--->");
        puts("<--- enter data again --->");
        goto L1;
    }

    /* validating the raw data if in 0'th position, '-ve' sign 
       is occured printing a message & asking user to re-enter 
       the data again */
    if ('-' == buff[0]) {
        puts("<--- negative numbers are not allowed --->");
        puts("<--- enter data again --->");
        goto L1;
    }

    /* getting a unsigned integer number by sending validated 
       raw data to my_atoi() */
    return  my_atoi(buff);

}
