#include <stdio.h>
static int var = 9;
int main()
{
    auto int x_var = 3;
    var = var + x_var;
    printf("number = %d\n", var);
    if (var <= 50)
       return 0; 
    main();
    return 0;
}
