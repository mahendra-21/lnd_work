/* compare two strings str1 and str2 and returns the following
 * i)  0 if two strings are equal
 * ii) 1 str1 is greater than str2 
 * iii) -1 if str1 is less than str2 
 */

char my_strcmp(const char *str1, const char *str2) {

    while (*str1) if (*str1++ != *str2++) break;

    if (*str1 == *str2) return 0;

    else if (*str1 > *str2) return 1;

    else return -1;

}
