/* program for deleting the repeated consecutive characters */

#include <header.h>

int main(void)
{
    char *string = NULL; // declaring character pointer
    int ret = 0;
    
    /* allocating memory space to the pointer by using malloc */
    string = (char *) malloc(SIZE * sizeof (char)); 
    
    /* checking the pointer weather size is allocated or not */ 
    if (NULL == string) {
        puts("malloc failed to allocate size");
        return 0;
    }
    
    /* reading raw data from user by using stdin */
    puts("enter a string:");
    fgets(string, SIZE, stdin);
    fflush(stdin);
    
    /* checking the string weather fgets read the data or not */
    if ('\0' == *string) { 
        puts("fgets failed to read the string fron user");
        return 0;
    }

    ret = del_char(string); // calling the function del_char

    if (0 == ret) {
        puts("del_char function failed");
        return 0;
    }

    puts(string);

    return 0;
}
