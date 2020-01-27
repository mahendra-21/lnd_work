#if 0
#include<stdio.h> 

static unsigned char h[5]={1,2,3,4,5}; 

int main() 

{ 

struct ad{ unsigned short a; unsigned short b; };

struct ad *it; 

it=(struct ad*)h; 

printf("%d ",it->a);

printf("%d ",it->b); 

}
#endif

#if 0
#include<stdio.h> 

static int a; 

char b[10]; 

struct st

{ 

float x,y; 

} pt; 

int main(void) 

{ 

static float v[] = {1.2, 1.3}; 

static struct st pt1; 

printf("%f %f",v[1],v[2]); 

return 0; 
}
#endif
#if 1
#include<stdio.h> 

int main(void) 

{ 

struct ab

{ 

char *a;int b; int c;

}; 

struct ab y = {"547895",5,6}; 

struct ab *p = &y; 

printf("++p->a = %s\n", ++p->a); 

printf("*p->a = %c\n", *p->a++); 

printf("(*p->a)++ = %c\n", *(p->a)++); 

return 0; 

} 
#endif
#if 0 
#include<stdio.h>

 int main(void)

 { 

struct a

{

 int tmp[3];

 };

 int j; 

static int p[3]={1,2,3};

static int q[3]={4,5,6}; 

*(struct a*)q=*(struct a*)p; for(j=0;j<3;j++) printf("%3d",*(q+j)); 

return 0;

 } 
#endif
#if 0
Which of the following declaration is incomplete type struct tag; (1) struct tag{int a} (2) typedef struct {int a;} abc (3) 
#endif
#if 0
#include <stdio.h> 

typedef union

{ 

struct 

{ 

int a; 

} A; 

struct 

{ 

int a; float b; 

} B; 

} dd; 

int main(void) 

{ 

dd D; 

D.A.a=3; 

D.B.b=5.3; 

printf("%d",D.B.a); 

return 0; 

}
#endif
#if 0
8	#include<stdio.h> 

void test(unsigned char *c); 

int main() 

{ 

unsigned char c; 

int i; 

c=128; 

i=0; 

while(i<8)

{ 

test(&c);

 ++i; 

} 

printf("%d", c); 

} 

void test(unsigned char *c) 

{ 

union 

{ 

unsigned u; 

unsigned char c[2]; 

} 

uvar={0}; 

uvar.c[0]=*c; 

uvar.u=uvar.u<<1; 

if(uvar.c[1]) uvar.c[0]=uvar.c[0]|1; *c=uvar.c[0]; 

} 

//The output for this program is:
#endif
#if 0
#include <stdio.h> 

void f(char**); 

int main(void) 

{ 

char *argv[] = {"ab","cd","ef","gh","ij","kl"}; 

f(argv); 

return 0; 

} 

void f(char **p)

{ 

char *t; 

t = (p+=sizeof(int))[-1]; 

printf("%s",t); 
}
#endif
#if 0

#include<stdio.h> 

int main() 

{ 

struct test

{ 

int i; 

char c; 

union 

{ 

int iu; 

char cu; 

}u; 

}; 

struct test su={0}; 

printf("%d %d %d %d",su.u.cu, su.u.iu, su.c, su.i); 

} 
#endif
#if 0
#include<stdio.h> 

int main() 

{ 

int sum; 

enum tmp {A,B,C=5,D,E}; 

sum=A+B+C+D+E; 

printf("%d", sum); 

} 
#endif
#if 0

Consider following statement s1: Different enumeration may have same name s2: Values must be distinct in the same enumeration Which of the following is true?
#endif
#if 0
#include<stdio.h> 

int main() 

{ 

unsigned int j,i; 

union

{ 

unsigned int i; 

unsigned char a[2]; 

} u={129}; 

int n; n=1; 

while(n-->0)

{ 

j=((u.a[0]&1)<<7); 

u.a[0]=u.a[0]>>1;

u.a[0]=u.a[0]|j; 

} 

printf("%d",u.i); 

} 
#endif
#if 0

#include<stdio.h> 

struct st{ int a; int b; }; 

void foo(struct st*); 

int main() 

{ 

struct st ab={128,768}; 

struct st *pq=&ab; foo(pq); 

} 

void foo(struct st *p) 

{ 

char *pt; 

p->a=768; 

p->b=128; 

pt=(char *)p; 

printf("%d",*++pt); 

} 
#endif
#if 0

#include<stdio.h> 

int main() 

{ 

union

{ 

struct

{

char c[2]; 

char ch[2]; 

}s; 

struct

{ 

int i; int j; 

	  }st; 

}u={12,1}; 

printf("%d %d",u.st.i,u.st.j); 

} 
#endif

#if 0

#include<stdio.h> 

int main()

{ 

union

{ 

struct

{ 

char c[2]; 

char ch[2]; 

}s; 

struct

{ 

int i; int j; 

}st; 

}u={12,1, 15,1}; 

printf("%d %d",u.st.i,u.st.j);
#endif
#if 0

#include<stdio.h> 

int main(void)

{ 

unsigned char c; 

typedef struct name

{ 

long a; 

int b; 

long c; 

}r; r re = {3,4,5}; 

r *na = &re; 

printf("%d\n",*(int*)((char*)na+(unsigned int) & (((struct name*)0)->b))); 

return 0; 

}
#endif
#if 0
#include<stdio.h>
struct st 

{ 

int a:4; int b:4; 

}v1={-1,-1}; 

main() 

{ 

printf("%u %u",v1.a, v1.b); 

} 
#endif
#if 0
#include<stdio.h>
struct st

{ 

 unsigned int a:4; 

 unsigned int b:4; 

} v1={18,18}; 

int main() 

{ 

 printf("%d %d",v1.a, v1.b); 

} 
#endif
#if 0
#include<stdio.h>
structure struct 

st 

{ 

 unsigned int a:4; 

 unsigned int b:4; 

}v1={-1,-1}; 

int main() 

{ 

 printf("%u %u",v1.a, v1.b); 

} 

#endif
#if 0
union u1

 { 

 int a; 

 char b[2]; 

 }v1 = {2,2}; 

 

 union u2

 {

 int b[2]; 

 int a; 

 }v2 = {2,2}; 

 

 Which of the above is valid one to initialize union? 
#endif
#if 0
union u1

{ 

 int a; 

 char b[2]; 

 }v1 = {2,2}; 

 

 union u2

{ 

 int b[2]; 

 int a; 

 }v2 = {2,2}; 

 

 union u3

{ 

 int a; 

 char b[2];

 }v3 = {514}; 

 

 Which one of the above initializes b[0] and b[1] to values 2
#endif
#if 0
#include <stdio.h>
struct st

{ 

int a; 

char b[10]; 

}; 

void foo(struct st *); 

main() 

{ 

struct st ab = {5, "ready"}; 

foo(&ab); 

printf("%d %s\n", ab.a, ab.b); 

} 

void foo(struct st *p) 

{ 

p -> a = 6; 

p -> b[4] = 'e'; 

} 

//Whats the output?
#endif
#if 0
#include <stdio.h>
struct st 

{ 

 int a; 

 int b; 

}; 

void foo(struct st *); 

main() 

{ 

 struct st ab = { 128, 768 }; 

 struct st *pq = &ab; foo(pq); 

} 

void foo(struct st *p) 

{ 

 char *pt; 

 p -> a = 768; 

 p -> b = 128; 

 pt = (char *)p; 

 printf("%d\n", *++pt); 

} 

//output of the program is:
#endif
#if 0
#include <stdio.h>
main()

{ 

 struct node

 { 

 int a; 

 int b; 

 int c; 

 }; 

 struct node s = {3, 5, 6}; 

 struct node *pt = &s; 

 printf("%d", *(int *)pt); 

} 
#endif
