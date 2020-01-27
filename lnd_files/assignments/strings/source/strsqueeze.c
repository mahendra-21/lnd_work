/* squeeze the consecutive similar characters in a given string */

void str_squeeze(char *str) {

    char *temp = str;

    while (*str) {

        *temp = *str++;

        if (*temp != *str) temp++;

    }

    *temp = *str;

}
