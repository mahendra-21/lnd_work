#include <stdio.h>

#if 0
/* struct.c:7:5: error: expected specifier-qualifier-list before ‘struct_mem’
        struct_mem = 100;
             ^
 */

struct tag_name {
    int struct_mem;
    struct_mem = 100;
};

int main(void)
{
    struct tag_name struct_var;

//    struct_var.struct_mem = 10;

    printf ("in struct = %d\n", struct_var.struct_mem);

    return 0;
}
#endif

#if 0
/* Initialization of structure members is not possible while declaration time

   struct.c:26:20: error: expected ‘:’, ‘,’, ‘;’, ‘}’ or ‘__attribute__’ 
                          before ‘=’ token
        int struct_mem = 100;
                            ^
   struct.c:35:43: error: ‘struct tag_name’ has no member named ‘struct_mem’
        printf ("in struct = %d\n", struct_var.struct_mem);

 */

struct tag_name {
    int struct_mem = 100; // Here, struct_mem is not declaring
};

int main(void)
{
    struct tag_name struct_var;

//    struct_var.struct_mem = 10;

    printf ("in struct = %d\n", struct_var.struct_mem);

    return 0;
}
#endif

#if 0 
/* if we declare same name structure variable name and local variables 
   when structures it throws an error like,

   struct.c:14:13: error: request for member ‘tag_name’ in something 
                          not a structure or union
      tag_name. tag_name = 20;
              ^
   struct.c:16:64: error: request for member ‘tag_name’ in something 
                          not a structure or union
      printf("in main = %d\tin struct = %d\n", tag_name, tag_name. tag_name)
 */

struct tag_name {
    int tag_name;
}tag_name;

int main (void) 
{
    int tag_name = 10;
    tag_name. tag_name = 20;
//    int tag_name = 10;

    printf("in main = %d\tin struct = %d\n", tag_name, tag_name. tag_name);

    return 0;
}
#endif

#if 1
/* if we declare same name of members in structures it throws an error like,
   error: duplicate member ‘tag_name’ */

struct tag_name {
    int tag_name1 : 8;
    int : 30;
}tag_var;

int main (void) 
{
    //int tag_name = 10;
   tag_var. tag_name1 = 20;

//    printf("in main = %d\n, Size = %d\n", tag_var.tag_name1, sizeof(tag_var));
    
    return 0;
}
#endif

#if 0 
/* if structure member name and tag name and in main same name as before
   it won't give's an any error */

struct tag_name {
    int tag_name;
}tag_var;

int main (void) 
{
    int tag_name = 10;
    tag_var. tag_name = 20;

    printf("in main = %d\tin struct = %d\n", tag_name, tag_var. tag_name);

    return 0;
}
#endif
