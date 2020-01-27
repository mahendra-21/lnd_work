/* Insert a char ch in the given string str at a specified position pos */

char* insertchar (char *str, const char ch, int pos) {

    int len = 0;
    for (len = 0; str[len]; len++);
    
    char buff[len + 1];
    int count = 0;
    int help = 0;
    
    while (*str) {

        buff[help++] = *str++;

        if (count++ == pos) {
            
            buff[help++] = ch;

            while (*str)  buff[help++] = *str++;
           
            buff[help] = *str;
            
            break;
        }

    }

    return buff;
}
