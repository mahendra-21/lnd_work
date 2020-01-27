#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 128
 
char *my_strtok (char *str, const char *deli) {
    /* Taking static character pointer to store original string */
    static char *string = NULL; 
    /* Taking temprarory character pointer for rotating of 
       delimeter string */
    const char *temp = NULL;
    /* Taking static integer variable to traverse the string to 
       previous position of the string */
    static int pos = 0;
    /* Initialising the 'pos' to the start variable for returning 
       the string to called function */
    int start = pos;

    /* If original string is not null assigning to the static string */
    if (NULL != str)    string = str;
    /* Rotating the loop until '\0' */
    while ('\0' != *(string + pos)) {
        temp = deli; 
        /* Assigning the delimeter string to the temporary pointer to 
           avoid the segmentation fault, and withe help of temporary 
           pointer iterarting the while loop until '\0' */

        while('\0' != *temp) {
            /* Comparing the respected character in the string to the
               delimeter. If character in the string and delimeter are 
               equal assigning '\0' at the delimeter position in the 
               original string */
            if (*(string + pos) == *temp++) {
                *(string + pos) = '\0';
                /* Incrementing the position after assigning '\0' */
                pos = pos + 1;
                /* Returning the string if 'string + start' is not equal
                   to '\0' , otherwise assigning the 'pos' value to the
                   'start' variable and decrementing the 'pos' quiting 
                   from the while loop */
                if ('\0' != *(string + start)) {
                    return  (string + start);
                } else {
                    start = pos;
                    pos--;
                    break;
                }

            }

        }
        
        pos++; // Incrementing the 'pos' if delimeter string is not 
               // match with current character in the string
    }

    /* Assigning the '\0' to the 'string + pos' (end of the string 
       means at delimeter pos) */
//    *(string + pos) = '\0'; 

    /* Returning the NULL if 'string + start' pos is equal to 
       the '\0'(null) otherwise returning the string from 'string + start'
       position of the string */
    if ('\0' == *(string + start)) { 
        return NULL;
    } else {
        return (string + start);
    }

}
