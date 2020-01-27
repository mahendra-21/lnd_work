#include <stdio.h>

#if 1
/* if we give the bit-fiels width more tham it's type it throws an error
    error: width of ‘ivar’ exceeds its type
         unsigned int ivar : 33;
              ^
 */
struct fields {
    unsigned int ivar : 33;
}bit;

int main(void) 
{
    bit.ivar = 10;
    printf("value = %d\tsize = %d\n", bit.ivar, sizeof(bit));
    return 0;
}
#endif

#if 0
/* zero width of bit-field is throws an error

   error: zero width for bit-field ‘ivar’
        unsigned int ivar : 0;
             ^
 */
struct fields {
    unsigned int ivar : 0;
}bit;

int main(void) 
{
    bit.ivar = 10;
    printf("value = %d\tsize = %d\n", bit.ivar, sizeof(bit));
    return 0;
}
#endif

#if 0
/* if we dont't mention the unsigned (sign qualifier) it prints the output 
   as -ve values

   warning: overflow in implicit constant conversion [-Woverflow]
       bit.ivar = 16;
            ^
 */
struct fields {
    int ivar : 4;
};

int main(void)
{
    struct fields bit;
    bit.ivar = 13;
    printf(" size of ivar = %d\n", bit.ivar);
    return 0;
}
#endif

#if 0 
/* if bit range is exceed's it prints the output of the 4 bits in given 
   number.

   warning: large integer implicitly truncated to unsigned type [-Woverflow]
        bit.ivar = 16;
             ^
 */
struct fields {
    unsigned int ivar : 4;
};

int main(void)
{
    struct fields bit;
    bit.ivar = 98;
    printf(" size of ivar = %d\n", bit.ivar);
    return 0;
}
#endif

#if 0
/*  
    error: ‘sizeof’ applied to a bit-field
         printf(" size of ivar = %d\n", sizeof(bit.ivar));
                                                  ^
  */
struct fields {
    unsigned int ivar : 4;
    unsigned int isvar : 4;
};

int main(void)
{
    struct fields bit;
    printf(" size of ivar = %d\n", sizeof(bit.ivar));
    return 0;
}
#endif

#if 0 

struct tag{
    int sti_mem;
    char stc_mem;
    float stf_mem;
};

int main(void)
{
    printf("size of struct = %d\n", sizeof (struct tag));

    return 0;
}
#endif

#if 0

struct tag_name {
    int sti_mem;
    char stc_mem;
    float stf_mem;
};

int main(void)
{
    printf("size of struct = %d\n", sizeof (struct tag_name));

    return 0;
}
#endif            
