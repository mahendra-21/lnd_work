
void str_valid (const char *str, char *buff) {

    while (('\n' != *str) && ('\0' != *str))  *buff++ = *str++;

    *buff = '\0';
} 
