#include <header.h>

int get_number(void) {
    
    char *str = (char *)malloc(SIZE * sizeof(char));
    
    if (NULL == str) {
        printf("malloc failed to allocate size\n");
        exit(0);
    }

    int limit = 1;

    do {
        __fpurge(stdin);
        fgets(str, SIZE, stdin);

        if (('\0' == *str) || ('\n' == *str)) {
            printf("fgets failed to read data from stdin:");
            printf(" chances to give correct data(%d)\n",
                    (LIMIT - limit++));
            continue;
        } else {
            break;
        }

        __fpurge(stdin);

    } while (LIMIT != limit);
    
    return validate_for_int(str);
}
