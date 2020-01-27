#if 0
#include<stdio.h>

int main(void)

{

int *a = {(int *)1,(int *)2};
printf("%p\n%d\n",a,*a);
printf("%d %d",a[0],a[1]);

return 0;

}
#endif
#if 0
#include<stdio.h>
int main() {
int a[] = {1, 2, 3, 4, 5};

int *ptr, **ptr1;
 ptr = &a;
 ptr1 = &ptr;

}

//How do you update a[2] to 10 using ptr1?
#endif
#if 0

int main()

{

int a[][5] = {0};

int (*ptr)[5] = a;

printf("%d %d\n", sizeof (ptr), sizeof (*ptr));

} 

#endif 

#if 0

#include<stdio.h>

int main()

{

char *str = "GLobaledge";

*str = 'g';

printf("%s\n", str);

return 0;

}
#endif


#if 1
#include<stdio.h>

int main()

{

char *ptr="%d%t%shello";

while(*ptr++ != 't');

printf(ptr,ptr);
printf("\n");

}

//The output of this program is
#endif

#if 0
#include<stdio.h> 

void foo( int a, int b,...); 

int main() 

{  

	foo(1,5);  

	foo(2,5,6); 

}   

void foo(int a, int b, ...) 

{  

	int j;  

	int *ptr = &b;   j=0;  

	while(j<a) {   

		printf("%d",*ptr);   

		++j;   

		++ptr;
	}
}
#endif
#if 0
#include<stdio.h>

int main()

{

int a[][5]={0};

int (*ptr)[5]=a;

printf("%d %d",sizeof(ptr),sizeof(*ptr));

}

//if pointer is 4 byte and int is 4 byte then output for this program is :>
#endif


#if 0
void tmp(char *s)

{

char *q = ++s;

while (*q)

++q;

printf("%d",q-s);

} 
#endif
#if 0
#include<stdio.h>

void tmp(char *);

int main()

{

char *p = "abcdef";

tmp(p);

} 
#endif
#if 0
int main()

{

char *src="Hello";

char *dst;

while (*dst++ = *src++);

printf("%s",dst);

}
#endif
#if 0
#include<stdio.h>

int main()

{

char *p;

char *line[]={"monday","tuesday"};

if ( p = strchr(line[0], 'd' ) )

printf("%s",p);

}

//The output for this program is:
#endif
#if 0
#include<stdio.h>

int main()

{

char *p;

char *line[] = {"sunday", "monday", "tuesday"};

if (p = strstr(line[0], "day") ) 

printf("%s",p);

}

//The output for this program is
#endif
#if 0
#include<stdio.h>
#include <string.h>
void string(char*);
int main(void)
{
        char p[] = "tit for tat";
        string(p);
        printf("%s\n",p);
        return 0;
}
void string(char *q)
{
        char *r=q+strlen(q)-1;
        for(;q<r;q++,r--)
        {
                *q=*q^*r;
                *r=*r^*q;
                *q=*q^*r;
        }
}
#endif
#if 0
#include<stdio.h> 

int main(void) 

{ 

char *v[] = {"abc","efg","jkl"}; 

char **p = v; printf("%c",*++p[0]); 

printf("%c",(*++p)[0]); 

return 0; 

} 

 #endif
#if 0
#include<stdio.h> 

int main(void) 

{ 

int a[5] = {1,2,3,4,5}; 

int *ptr = (int*)(&a+1); 

printf("%d %d", *(a+1), *(ptr-1)); 

return 0; 

} 

 

//The output of this program is:
#endif
#if 0
# include <stdio.h>

int main (void)

{ 

 float a [ 10 ] [ 10 ]; 

 float *p,*q; 

 float *e, *f; 

 

 p = &a [ 5 ] [ 8 ]; 

 q = &a [ 10 ] [ 9 ]; 

 e = p - q + a;           /* exp1 */ 

 f = a + p - q;           /* exp2 */ 

} 
#endif
#if 0
include <stdio.h> 

int main(void) 

{ 

float a [ 10 ] [ 10 ]; 

float *p, *q; 

unsigned int nu; 

 

p = &a [ 5 ] [ 8 ]; 

q = &a [ 8 ] [ 5 ]; 

 

if ( (p - q) >= 0 )

    nu = p - q; 

else

    nu = -(p - q); 

 

printf("%u ",nu); 

} 
#endif
#if 0
# include <stdio.h> 
int main(void) 

{ 

 char *table[ ] = {"jan", "feb", "march"}; 

 char **ptr = &table[1];

 printf ("%s ", *(ptr - 1) ); 

} 

 

//The output for this Program:
#endif
#if 0


int main(void) 

{ 

 char *p; 

 char buf[10] = { 1, 2, 3, 4, 5, 6, 9, 8 }; 

 p = (buf+1)[5]; 

 printf ("%d", p); 

}
#endif
#if 0
#include<stdio.h> 

int main() 

{ 

char a[]="abcde"; 

char *p=a; 

p++; 

p++; 

p[2]='z'; 

printf("%s",p); 

} 
#endif
