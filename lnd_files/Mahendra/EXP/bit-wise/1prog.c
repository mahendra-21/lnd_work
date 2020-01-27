#include <stdio.h>

float main(void)
{
    int var = 11;

//    var = (~var) ^ ~1; /* for even ++, for odd -- */
//    var = ((~var) << 1) ^ ~1; /* for any num * 2 */

    var = var << 3;

    printf("var -> %d\n", var);
    return 1;
}
