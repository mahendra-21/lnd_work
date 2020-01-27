#include <string_header.h>

char *get_string(void) {

    char r_buff[SIZE] = {0};
    char buff[SIZE] = {0};

    int help = 0;
   
    fgets(r_buff, SIZE, stdin);
    fflush(stdin);

    if ('\0' == *r_buff) {
        
        puts("fegts failed to read string");
        exit (0);

    }

     str_valid(r_buff, buff);

     return buff;
}
