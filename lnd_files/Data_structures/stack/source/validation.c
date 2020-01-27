/* validation function */

int validation(const char *str, char *buff) // validation function definition
{
    int start = 0;

    if (str[0] == '-' || str[0] == '+') { // condition to check in first pos
        *buff++ = *str++;            // -ision any sign char is there or not  
        
        start = 1;
    } else {    // if condition is true start = 1 otherwise start = 0
        start = 0;
    }
    /* Iterating loop for validating the user raw data */
    for (; *str; str++, start++) {  

        if (*str >= '0' && *str <= '9') {
            *buff++ = *str;
        } else if ((0 == start) && (' ' == str[start])) { 
    /* if start of the string spaces is occured...Ignoring the spaces */
            for (; *str == ' '; str++,start++); 
            
            if (('-' == *str || '+' == *str)
                    || ('0' <= *str && '9' >= *str)) {
                *buff++ = *str;
            }

        } else {
            
            if (*str == ' ') {
                for (; *str == ' '; str++);
                if (*str == '\n') {
                    return 0;                
                } 
            }
 
            if (*str == '\n') { // if end of the string is 
                                // new line character terminate the loop.
                break;
            }
            return 1;           
        }

    }

    return 0;
}
