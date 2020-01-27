/* Append first n characters of string str1 to string str2 */

void snappend(const char *str1, char *str2, int n) {

    while (*str2) str2++;

    while ((n--) && *str1) *str2++ = *str1++;

    *str2 = '\0';

}
