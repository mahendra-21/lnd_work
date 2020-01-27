#include<stdio.h>

#if QUES == 1
/* simple example for pointer usage */
int main(void)
{
	int a = 65;
	int *ptr = NULL;

	ptr = &a;
	printf("*ptr = %c\n",*ptr);
	printf("*ptr = %d\n",*ptr);
	printf("*ptr = %f\n",(float )*ptr);
	printf("*ptr = %p\n",(void *)*ptr);	
	printf("*ptr = %x\n",*ptr);
	//printf("*ptr = %s",*ptr);
	return 0;
}
/* floating point representation value changes for every execution */
/* last printf gives segmentation fault and since no \n is used, no system calls are invoked and no output is printed */
#endif


#if QUES == 2
/* simple example for pointer usage with new line character */
int main(void)
{
	int a = 65;
	int *ptr = NULL;

	ptr = &a;
	printf("*ptr = %c\n",*ptr);
	printf("*ptr = %d\n",*ptr);
	printf("*ptr = %f\n",*ptr);
	printf("*ptr = %p\n",*ptr);	
	printf("*ptr = %x\n",*ptr);
	printf("*ptr = %s\n",*ptr);
	return 0;
}
/* floating point representation value changes for every execution */
/* last printf gives segmentation fault and other outputs are printed */
#endif


#if QUES == 3
/* simple example for printing pointer addresses */
int main(void)
{
	int a = 65;
	int *ptr = NULL;

	ptr = &a;
	printf("*ptr = %c\n",ptr);
	printf("*ptr = %d\n",ptr);
	printf("*ptr = %f\n",ptr);
	printf("*ptr = %p\n",ptr);	
	printf("*ptr = %x\n",ptr);
	printf("*ptr = %s\n",ptr);

	return 0;
}
/* last printf will dereference the address and print the value of the variable a*/
#endif


#if QUES == 4
/* dereferencing a null pointer */
int main(void)
{
	int *ptr = NULL;

	printf("*ptr = %c\n",*ptr);
	printf("*ptr = %d\n",*ptr);
	printf("*ptr = %f\n",(float )*ptr);
	printf("*ptr = %p\n",(void *)*ptr);	
	printf("*ptr = %x\n",*ptr);
	//printf("*ptr = %s\n",*ptr);
	return 0;
}
/* all the printf will give segmentation faults */
#endif


#if QUES == 5
/* printing null pointers address in different formats */
int main(void)
{
	int *ptr = NULL;

	printf("*ptr = %c\n",ptr);
	printf("*ptr = %d\n",ptr);
	printf("*ptr = %f\n",ptr);
	printf("*ptr = %p\n",ptr);	
	printf("*ptr = %x\n",ptr);
	printf("*ptr = %s\n",ptr);
	return 0;
}
/* it starts printing the NULL values in different formats 
   the notable ones are %p which prints (nil) and %s which prints (null) */
#endif


#if QUES == 6
/* dereferencing a dangling pointer */
int main(void)
{
	int *ptr;

	printf("*ptr = %c\n",*ptr);
	printf("*ptr = %d\n",*ptr);
	printf("*ptr = %f\n",*ptr);
	printf("*ptr = %p\n",*ptr);	
	printf("*ptr = %x\n",*ptr);
	printf("*ptr = %s\n",*ptr);
	return 0;
}
/* every time it prints the same garbage value, but different float values 
   and seg fault for %s */
#endif


#if QUES == 7
/* printing the dangling pointer address in different formats */
int main(void)
{
	int *ptr;

	printf("*ptr = %c\n",ptr);
	printf("*ptr = %d\n",ptr);
	printf("*ptr = %f\n",ptr);
	printf("*ptr = %p\n",ptr);	
	printf("*ptr = %x\n",ptr);
	printf("*ptr = %s\n",ptr);
	return 0;
}
/* every time it prints the different garbage addresses the last printf dereferences  the value */
#endif



#if QUES == 8
/* dereferencing a dangling pointer declared globally */
int *ptr;
int main(void)
{
	printf("*ptr = %c\n",*ptr);
	printf("*ptr = %d\n",*ptr);
	printf("*ptr = %f\n",*ptr);
	printf("*ptr = %p\n",*ptr);	
	printf("*ptr = %x\n",*ptr);
	printf("*ptr = %s\n",*ptr);
	return 0;
}
/* all the printf will give seg fault */
/* optimized code for objdump */
#endif


#if QUES == 9
/* printing the addresses of the dangling pointer declared globally */
int *ptr;
int main(void)
{
	printf("*ptr = %c\n",ptr);
	printf("*ptr = %d\n",ptr);
	printf("*ptr = %f\n",ptr);
	printf("*ptr = %p\n",ptr);	
	printf("*ptr = %x\n",ptr);
	printf("*ptr = %s\n",ptr);
	return 0;
}
/* output is same as printing the addresses of NULL pointer in different formats */
/* float will print correct value (execute QUES 5 again) */
/* no optimization in objdumps output */
/* in higher versions of gcc float will print different values */
#endif


#if QUES == 10
/* experiment to dereference a pointer of type int using %d and %s */
int main(void)
{
	int a = 65;
	int b = 70;
	int c = 97;
	int *ptr = NULL;

	ptr = &a;
	printf("*ptr = %d\n",*ptr);
	printf("*ptr = %s\n",ptr);
	return 0;
}
/* as expected it will print the correct values */
/* warning for second printf */
#endif


#if QUES == 11
/*experiment to dereference a pointer of type char using %c and %s*/
int main(void)
{
	char a = 65;
	char b = 70;
	char c = 97;
	char *ptr = NULL;

	ptr = &a;
	printf("*ptr = %c\n",*ptr);
	printf("*ptr = %s\n",ptr);
	return 0;
}
/* for second printf it prints till it encounters null character */
#endif


#if QUES == 12
/* previous experiment with a variable having 0 as its value*/
int main(void)
{
	char a = 65;
	char b = 70;
	char c = 97;
//	char d = 0;
	char e = 98;
	char *ptr = NULL;

	ptr = &a;
	printf("*ptr = %c\n",*ptr);
	printf("*ptr = %s\n",ptr);
	return 0;
}
/* for second printf it prints till it encounters null character ie., AFa  */
/* what happens in QUES 10 in case of int data type */
#endif


#if QUES == 13
/* same as QUES 10 but with different value of variable a */
int main(void)
{
	int a = 0x6765;
	int b = 70;
	int c = 97;
	int *ptr = NULL;

	ptr = &a;
	printf("*ptr = %d\n",*ptr);
	printf("*ptr = %s\n",ptr);
	return 0;
}
/* second printf prints till it encounters 0 */
/* try for a = 0x69686765 */
#endif


#if QUES == 14
/* experiment on pointer address arithmetic */
int main(void)
{
	char a;
	short int b;
	int c;
	long d;
	float e;
	double f;
	long double g;

	char *ptr1 = &a;
	short int *ptr2 = &b;
	int *ptr3 = &c;
	long *ptr4 = &d;
	float *ptr5 = &e;
	double *ptr6 = &f;
	long double *ptr7 = &g; 

	printf("ptr1 = %p , ptr1 + 1 = %p\n",ptr1,ptr1 + 1);
	printf("ptr2 = %p , ptr2 + 1 = %p\n",ptr2,ptr2 + 1);
	printf("ptr3 = %p , ptr3 + 1 = %p\n",ptr3,ptr3 + 1);
	printf("ptr4 = %p , ptr4 + 1 = %p\n",ptr4,ptr4 + 1);
	printf("ptr5 = %p , ptr5 + 1 = %p\n",ptr5,ptr5 + 1);
	printf("ptr6 = %p , ptr6 + 1 = %p\n",ptr6,ptr6 + 1);
	printf("ptr7 = %p , ptr7 + 1 = %p\n",ptr7,ptr7 + 1);
	return 0;
}
/* as expected by incrementing its address it points to next object */
/* this can also be used to check the size of that variable */
#endif

#if QUES == 15
/* to check the subtraction of two pointers of same data type */
int main(void)
{   
	char a;
	short int b;
	int c;
	long d;
	float e;
	double f;
	long double g;

	char *ptr1 = &a;
	short int *ptr2 = &b;
	int *ptr3 = &c;
	long *ptr4 = &d;
	float *ptr5 = &e;
	double *ptr6 = &f;
	long double *ptr7 = &g;

	printf("(ptr1 - (ptr1 + 1)) = %d\n",ptr1 - (ptr1 - 1));
	printf("(ptr2 - (ptr2 + 1)) = %d\n",ptr2 - (ptr2 - 1));
	printf("(ptr3 - (ptr3 + 1)) = %d\n",ptr3 - (ptr3 - 1));
	printf("(ptr4 - (ptr4 + 1)) = %d\n",ptr4 - (ptr4 - 1));
	printf("(ptr5 - (ptr5 + 1)) = %d\n",ptr5 - (ptr5 - 1));
	printf("(ptr6 - (ptr6 + 1)) = %d\n",ptr6 - (ptr6 - 1));
	printf("(ptr7 - (ptr7 + 1)) = %d\n",ptr7 - (ptr7 - 1));
	return 0;

	return 0;
}
/* all the printf will give 1 as output because pointer subtraction gives the number of objects present between them */
#endif


#if QUES == 16
/* pointer arithematic(subtraction) for different data type */
int main(void)
{
	char a;
	short int b;
	int c;
	long d;
	float e;
	double f;
	long double g;

	char *ptr1 = &a;
	short int *ptr2 = &b;
	int *ptr3 = &c;
	long *ptr4 = &d;
	float *ptr5 = &e;
	double *ptr6 = &f;
	long double *ptr7 = &g;

	printf("(ptr1 - ptr2) = %d\n",ptr1 - ptr2);
	printf("(ptr2 - ptr3) = %d\n",ptr2 - ptr3);
	printf("(ptr3 - ptr4) = %d\n",ptr3 - ptr4);
	printf("(ptr4 - ptr5) = %d\n",ptr4 - ptr5);
	printf("(ptr5 - ptr6) = %d\n",ptr5 - ptr6);
	printf("(ptr6 - ptr7) = %d\n",ptr6 - ptr7);
	return 0;
}
/* all the printf will throw error because different data types */
/* invalid operands to binary - */
#endif


#if QUES == 17
/*pointer arithmetic(subtraction)with a generic pointer (void) and other data type */
int main(void)
{
	char a;
	short int b;
	int c;
	long d;
	float e;
	double f;
	long double g;

	char *ptr1 = &a;
	short int *ptr2 = &b;
	int *ptr3 = &c;
	long *ptr4 = &d;
	float *ptr5 = &e;
	double *ptr6 = &f;
	long double *ptr7 = &g;

	printf("(ptr1 - ptr2) = %d\n",ptr1 - (void *)ptr2);
	printf("(ptr2 - ptr3) = %d\n",ptr2 - (void *)ptr3);
	printf("(ptr3 - ptr4) = %d\n",ptr3 - (void *)ptr4);
	printf("(ptr4 - ptr5) = %d\n",ptr4 - (void *)ptr5);
	printf("(ptr5 - ptr6) = %d\n",ptr5 - (void *)ptr6);
	printf("(ptr6 - ptr7) = %d\n",ptr6 - (void *)ptr7);

	return 0;
}
/* all the printf will throw error because different data types */
/* invalid operands to binary - */
#endif


#if QUES == 18
/* pointer address arithmetic with a generic pointer(void) */
int main(void)
{
	char a;
	short int b;
	int c;
	long d;
	float e;
	double f;
	long double g;

	char *ptr1 = &a;
	short int *ptr2 = &b;
	int *ptr3 = &c;
	long *ptr4 = &d;
	float *ptr5 = &e;
	double *ptr6 = &f;
	long double *ptr7 = &g;

	printf("(ptr1 - ptr2) = %d\n",(void *)ptr1 - (void *)ptr2);
	printf("(ptr2 - ptr3) = %d\n",(void *)ptr2 - (void *)ptr3);
	printf("(ptr3 - ptr4) = %d\n",(void *)ptr3 - (void *)ptr4);
	printf("(ptr4 - ptr5) = %d\n",(void *)ptr4 - (void *)ptr5);
	printf("(ptr5 - ptr6) = %d\n",(void *)ptr5 - (void *)ptr6);
	printf("(ptr6 - ptr7) = %d\n",(void *)ptr6 - (void *)ptr7);
	return 0;
}
/* the output depends on how the variables are stored in the stack frame */
#endif


#if QUES == 19
/* pointer address arithmetic for global variables using generic pointers */
char a;
short int b;
int c;
long d;
float e;
double f;
long double g;

char *ptr1 = &a;
short int *ptr2 = &b;
int *ptr3 = &c;
long *ptr4 = &d;
float *ptr5 = &e;
double *ptr6 = &f;
long double *ptr7 = &g;

int main(void)
{
	printf("(ptr1 - ptr2) = %d\n",(void *)ptr1 - (void *)ptr2);
	printf("(ptr2 - ptr3) = %d\n",(void *)ptr2 - (void *)ptr3);
	printf("(ptr3 - ptr4) = %d\n",(void *)ptr3 - (void *)ptr4);
	printf("(ptr4 - ptr5) = %d\n",(void *)ptr4 - (void *)ptr5);
	printf("(ptr5 - ptr6) = %d\n",(void *)ptr5 - (void *)ptr6);
	printf("(ptr6 - ptr7) = %d\n",(void *)ptr6 - (void *)ptr7);
	return 0;
}
/* the output depends on how the variables are stored in bss section */
#endif


#if QUES == 20
/* dereferencing the single pointer two times */
int main(void)
{
	int a = 10;
	int b = &a;
	int *ptr = NULL;

	ptr = &b;
	printf("**ptr = %d\n",ptr);
	return 0;
}
/* warning for initialization of b (integer from pointer) */
/* error for printf (invalid type argument of unary *)  */
#endif


#if QUES == 21
/* to check the why pointer cant be dereferenced 2 times */
int main(void)
{
	int a = 10;
	int b = &a;
	int *ptr = NULL;

	ptr = &b;
	printf("&a = %d\n",&a);
	printf("b = %d\n",b);
	printf("*ptr = %d\n",*ptr);
	return 0;
}
/* warning for initialization for b */
/* warning for first printf */
/* it will print the same value of different types */
/* every time the address of the variable is changing */
#endif



#if QUES == 22
/* to overcome the problem occured in QUES 20 */
int main(void)
{
	int a = 10;
	int b = &a;
	int **ptr = NULL;

	ptr = &b;
	printf("**ptr = %d\n",**ptr);
	return 0;
}
/* ofcourse it gives warning for initialization of b and ptr, but it can be dereferenced correctly */ 
#endif


#if QUES == 23
/* simple experiment on pointer with const data type */
int main(void)
{
	int a = 65;
	int const *ptr1 = NULL;
	int *const ptr2 = NULL;

	ptr1 = &a;
	ptr2 = &a;
	printf("ptr1 = %d\n",ptr1);
	printf("ptr2 = %d\n",ptr2);
	printf("*ptr1 = %d\n",*ptr1);
	printf("*ptr2 = %d\n",*ptr2);
	return 0;
}
/* error for ptr2 (assignment of read only variable ptr2) */
#endif


#if QUES == 24
/* simple experiment on pointer with const data type variable */
int main(void)
{
	int const a = 65;
	int *ptr1 = NULL;

	ptr1 = &a;
	printf("ptr1 = %d\n",ptr1);
	printf("*ptr1 = %d\n",*ptr1);

	*ptr1 = 70;
	printf("ptr1 = %d\n",ptr1);
	printf("*ptr1 = %d\n",*ptr1);

//	a = 75;
	printf("a = %d\n",a);
	return 0;
}
/* since assignment to ptr1 discards const qualifier the variable a can be changed through but it cant be changed directly */
/* error assignment of read only variable a (comment this assignment and run)*/
#endif


#if QUES == 25
/* simple experiment on pointer to const data type declared globally */
int const a = 65;
int *ptr1 = NULL;

int main(void)
{
	ptr1 = &a;
	printf("ptr1 = %d\n",ptr1);
	printf("*ptr1 = %d\n",*ptr1);

	*ptr1 = 70;
	printf("ptr1 = %d\n",ptr1);
	printf("*ptr1 = %d\n",*ptr1);

	return 0;
}
/* seg fault will occur during assignment of ptr1 which is present in rodata */
#endif


#if QUES == 26
/* simple experiment with const pointer */

/* as expected it will print correctly */
#endif


#if QUES == 27
/* simple experiment with const pointer */
int main(void)
{
	int const * const ptr = NULL;
	ptr = NULL;

	printf("ptr = %c\n",ptr);
	printf("ptr = %d\n",ptr);
	printf("ptr = %f\n",ptr);
	printf("ptr = %p\n",ptr);
	printf("ptr = %x\n",ptr);
	printf("ptr = %s\n",ptr);
	return 0;
}
/* error because of assignment of read only variable */
#endif


#if QUES == 28
/* assignment of different data types to the pointer */
int main(void)
{
	int i = 0x12345678;
	char *ptr = NULL;

	ptr = &i;
	printf("&i = %p\n",&i);
	printf("ptr = %p\n",ptr);
	printf("i = %x\n",i);
	printf("*ptr = %x\n",*ptr);

	printf("*(ptr + 1) = %x\n",*(ptr + 1));
	printf("*(ptr + 2) = %x\n",*(ptr + 2));
	printf("*(ptr + 3) = %x\n",*(ptr + 3));
	printf("*(ptr + 4) = %x\n",*(ptr + 4));
	printf("*(ptr + 5) = %x\n",*(ptr + 5));
	printf("*(ptr - 1) = %x\n",*(ptr - 1));
	printf("*(ptr - 2) = %x\n",*(ptr - 2));

	return 0;
} 
/* till ptr + 4 it prints the corect value after that garbage value */
#endif


#if QUES == 29
/* assignment of different data types to the pointer declared globally */
int i = 0x12345678;
char *ptr = NULL;
int main(void)
{
	ptr = &i;
	printf("&i = %p\n",&i);
	printf("ptr = %p\n",ptr);
	printf("i = %x\n",i);
	printf("*ptr = %x\n",*ptr);

	printf("*(ptr + 1) = %x\n",*(ptr + 1));
	printf("*(ptr + 2) = %x\n",*(ptr + 2));
	printf("*(ptr + 3) = %x\n",*(ptr + 3));
	printf("*(ptr + 4) = %x\n",*(ptr + 4));
	printf("*(ptr + 5) = %x\n",*(ptr + 5));
	printf("*(ptr + 500) = %x\n",*(ptr + 500));
	printf("*(ptr - 1) = %x\n",*(ptr - 1));
	printf("*(ptr - 2) = %x\n",*(ptr - 2));
	printf("*(ptr - 200) = %x\n",*(ptr - 200));
	return 0;
}
/* till ptr + 4 it prints the corect value after that zero value */
#endif


#if QUES == 30
/* to check whether we get a warning for lower to higher */
int main(void)
{
	char i = 0x65;
	int *ptr = NULL;

	ptr = &i;
	ptr =(int *)&i;
	ptr =(void *) &i;

	printf("*ptr = %x\n",*ptr);
	return 0;
}
/* yes we will get a warning for (char *) to (int *) assignment */
#endif


#if QUES == 31
/* assignment of different data types to the pointer */
float g = 2.5f;
char *ptr2;
int main(void)
{
	float f = 1.6f;
	char *ptr1 = NULL;

	ptr1 = &f;
	printf("*ptr1 = %x\n",*ptr1);

	ptr2 = &g;
	printf("*ptr2 = %x\n",*ptr2);
	return 0;
}
/* for both  it is giving 0  */
#endif


#if QUES == 32
/* assignment of different data types to the pointer */
float g = 2.53f;
char *ptr2;
int main(void)
{
	float f = 1.53f;
	char *ptr1 = NULL;

	ptr1 = &f;
	printf("*ptr1 = %x\n",*ptr1);

	ptr2 = &g;
	printf("*ptr2 = %x\n",*ptr2);
	return 0;
}
/* now the last byte of floating point representation is printed */
#endif

#if QUES == 33
/* assignment of different data types to the pointer */
#include<stdio.h>
int main(){
	int a = 130;
	unsigned char *ptr;
	ptr = (char *)&a;
	printf("%d ",*ptr);
	return 0;
}
/* by default cahr is signed so we get -126 as answer */
/* try with unsigned char */
#endif

#if QUES == 34
/* experiment to show that void pointer cant be used to store values without typecasting*/
int main(void)
{
	void *ptr = NULL;
	char a = 0x65;

	(char)ptr = &a;
	*ptr = 0x75;

	return 0;
}
/* error: invalid use of void expression for dereferencing the void pointer */ 
/* void pointer address can be changed but there is no way to dereference and chage the value it is pointing */
#endif


#if QUES == 35
/* experiment to show that void pointers cant be dereferenced without typecasting*/
int main(void)
{
	void *ptr = NULL;
	char a = 0x65;

	ptr = &a;
	printf("*ptr = %x\n",*ptr);
	return 0;
}
/* error dereferencing and invalid use of void expression */ 
#endif


#if QUES == 36
/* experiment to demostrate how void pointers can be used  to remove all warnings*/
int main(void)
{
	void *ptr = NULL;
	char a = 0x65;
	int b = 0x66;
	float c = 1.53f;

	ptr = &a;
	printf("*ptr = %x\n",*(char *)ptr);

	ptr = &b;
	printf("*ptr = %x\n",*(int *)ptr);

	ptr = &c;
	printf("*ptr = %f\n",*(float *)ptr);
	return 0;
}
/* the output is  as expected */
/* (char *)*ptr is wrong typecasting */
#endif


#if QUES == 37
/* experiment of pointers and function arguments  */
void func(int a)
{
	int *ptr = NULL;
	ptr = a;
	*ptr = 10;
}

int main(void)
{
	int b = 20;

	func(&b);
	printf("b = %d\n",b);
	return 0;
}
/* this is another way of changing the variable b*/
#endif


#if QUES == 38
/* experiments on pointers and function arguments */
void func(int *ptr1, int *ptr2)
{
	int temp;

	temp =* ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
int main(void)
{
	int a = 10;
	int b = 20;

	printf("before function call a = %d, b = %d\n",a,b);
	func(&a,&b);
	printf("after function call a = %d, b = %d\n",a,b);
	return 0;
}
/* only local copies of addresses are changed */
#endif


#if QUES == 39
/* experiments on pointers and function arguments */
void func(int *ptr1, int *ptr2)
{
	int temp;

	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
int main(void)
{
	int a = 10;
	int b = 20;

	printf("before function call a = %d, b = %d\n",a,b);
	func(&a,&b);
	printf("after function call a = %d, b = %d\n",a,b);
	return 0;
}
/* here local copies of addresses are changed and thier contents are also changed */
#endif


#if QUES == 40
/* experiments on pointers and function arguments */
void func(int a, int b)
{
	int *temp = NULL;

	temp = a;
	a = b;
	b = temp; 
}
int main(void)
{
	int *ptr1 = 1.73f;
	int *ptr2 = 2.75f;

	func(ptr1,ptr2);
	printf("ptr1 is %p\n",ptr1);
	printf("ptr2 is %p\n",ptr2);
	return 0;
}
/* error :- we cant initialize a pointer with float or double */
/* even if it is float * it cant be initialized */
#endif


#if QUES == 41
/* experiments on pointers and function arguments */
void func(int a, int b)
{
	int *temp = NULL;

	temp = a;
	a = b;
	b = temp; 
}
int main(void)
{
	float *ptr1 = NULL;
	float *ptr2 = NULL;

	ptr1 = 1.73f;
	ptr2 = 2.75f;

	func(ptr1,ptr2);
	printf("ptr1 is %p\n",ptr1);
	printf("ptr2 is %p\n",ptr2);
	return 0;
}
/* error : incompatible types when assigning , it will never take float */

#endif


#if QUES == 42
/* experiments on pointers and function arguments */
void func(int a, int b)
{
	int *temp = NULL;

	temp = a;
	a = b;
	b = temp; 
}
int main(void)
{
	float *ptr1 = NULL;
	float *ptr2 = NULL;

	ptr1 = (int) 1.73f;
	ptr2 = (int) 2.75f;

	func(ptr1,ptr2);
	printf("ptr1 is %p\n",ptr1);
	printf("ptr2 is %p\n",ptr2);
	return 0;
}
/* observe the warnings and the values are not changed */
#endif


#if QUES == 43
/* experiments on pointers and function arguments */
void func(int *ptr)
{
	printf("*ptr = %d\n",*ptr);
}
int main(void)
{
	int i = 10;

	func((&i)++);
	return 0;
}
/* error : we cant increment the address of a variable (lvalue required as increment operand) */
#endif


#if QUES == 44
/* experiments on pointers and function arguments */
void func(int *ptr)
{
	printf("%d\n",*ptr);
}
int main(void)
{
	int i = 10;
	int *p = &i;

	func(p++);
	return 0;
}
/* as expected it will give output correctly and no warnings during compilation*/
#endif


#if QUES == 45
/* experiments on pointers and function arguments */
void func(float *ptr)
{
	printf("%f\n",*ptr);
}
int main(void)
{
	int i = 10;
	int *ptr = &i;

	func(&i);
	return 0;
}
/* it is printing zero as output */
/* see objdump */
/* doubt */
#endif


#if QUES == 46
/* experiments on pointers and function arguments */
void func(int *ptr)
{
	int j = 2;
	ptr = &j;
	printf("%d \n",*ptr);
}
int main(void)
{
	int i = 97;
	int *ptr = &i;

	func(ptr);
	printf("%d \n",*ptr);
	return 0;
}
#endif


#if QUES == 47
/* review question  */
int main(void)
{
	float a=3.14;
	char *j;
	j = (char *)&a;
	printf("%d\n", *j);

	return 0;
}
/* it will print the decimal equivalent of the last byte of floating point representation */
#endif


#if QUES == 48
/* review question */
int main(void)
{
	int a=10, *j;
	void *k;
	j=k=&a;
	j++;
	k++;
	printf("&a is %u\n",&a);
	printf("%u %u\n", j, k);
	return 0;
}
/* as expected int pointer will increment by 4 and void by 1 */
#endif


#if QUES == 49
/* review question  */
/* will the following program give warning during compilation */
int main(void)
{
	int *p1, i=25;
	void *p2;
	p1=&i;
	p2=&i;
	p1=p2;
	p2=p1;
	return 0;
}
#endif


#if QUES == 50
/* review question */
#include <string.h>
int main(void)
{
	register a = 1;
	int *ptr; //what is this
	ptr = &a;
	printf("%p\n",ptr);
	return 0;
}
/* error : address of register variable a requested */
#endif


#if QUES == 51
/* review question */
int main(void)
{
	char a = 30, b = 5;
	char *p = &a, *q = &b;
		printf("(p - q) = %d\n", p - q);
	printf("(q - p) = %d\n", q - p);
	return 0;
}
/* it is based on how variables are placed in stack */
#endif


#if QUES == 52
/* experiment on dangling pointer */
int main(void)
{
	int a = 25, b;
	int *ptr, *ptr1;
	ptr = &a;
	ptr1 = &b;
	b = 36;
	printf("%d %d\n",*ptr, *ptr1);
	return 0;
}
/* as expected we will get 25 and 36 */
#endif


#if QUES == 53
/* experiments on dangling pointer */
int main(void)
{
	int *ptr;
	*ptr = 5;
	printf("%d" , *ptr);
	return 0;
}
/* it will give warning and seg fault */
#endif


#if QUES == 54
/* review question */
int main(void)
{
	int a = 36;
	int *ptr;
	ptr = &a;
	printf("%p %p\n", *&ptr , &*ptr);
	return 0;
}
/* as expexted we will get output without warning and errors */
#endif


#if QUES == 55
/* review question on NULL pointer */
int main(void)
{
	int a, b, c;
	char *p = 0;//doubt
	int *q = 0;
	double *r = 0;
	a = (int)(p + 1);
	b = (int)(q + 1);
	c = (int)(r + 1);
	printf("%d %d  %d\n",a, b, c);
	return 0;
}
/* why not getting any warning */
/* this can be used to get the size of the each data type */
#endif


#if QUES == 56
/* review question const qualifier */
int main(void)
{
	const int a = 5;
	const int *ptr;
	ptr = &a;
	*ptr = 10;
	printf("%d\n", a);
	return 0;
}
/* error : assignment of read-only location */
#endif


#if QUES == 57
/* experiment on NULL pointer */
#define NULL "pointer"
int main(void)
{
	char *ptr = NULL;
	printf("%s\n",ptr);
	return 0;
}
/*NULL is used for stylistic convention. Thus NULL itself a macro which is defined in #include<stdio.h> header files, thus modifing macro cause no error. Thus outputted "pointer" */
#endif


#if QUES == 58
/* experiment on NULL pointer */
int main(void)
{	
	int *ptr = NULL;
	*ptr = 65;
	printf("%d \n",ptr);
	return 0;
}
/* we will get segmentation fault when we dereference the NULL pointer */
#endif


#if QUES == 59
/* experiments on pointers and arrays */
int main(void)
{
	char a[10] = {'a','b','c','d','e'};
	printf("a[0] = %c\n",a[0]);
	printf("a[1] = %c\n",a[1]);
	printf("a[2] = %c\n",a[2]);
	printf("a[3] = %c\n",a[3]);
	printf("a[4] = %c\n",a[4]);
	printf("a[5] = %c\n",a[5]);
	printf("a[6] = %c\n",a[6]);
	printf("a[7] = %c\n",a[7]);
	printf("a[8] = %c\n",a[8]);
	printf("a[9] = %c\n",a[9]);
	return 0;
}
/* the rest of the array is initialized to zero */
#endif


#if QUES == 60
/* experiments on pointers and arrays */
int main(void)
{
	char a[10] = {'a','b','c','d','e'};
	printf("a[0] = %c\n",*(a + 0));
	printf("a[1] = %c\n",*(a + 1));
	printf("a[2] = %c\n",*(a + 2));
	printf("a[3] = %c\n",*(a + 3));
	printf("a[4] = %c\n",*(a + 4));
	return 0;
}
/* see objdump output */
/* array indexing will generate movzbl and movsbl instructions */
/* movzbl 0x12(%esp),%eax
   movsbl %al,%eax    */
#endif



#if QUES == 61
/* experiments on pointers and arrays */
int main(void)
{
	char a[10] = {'a','b','c','d','e'};
	char *p = NULL;

	p = a;
	printf("*(p + 0) = %c\n",*(p + 0));
	printf("*(p + 1) = %c\n",*(p + 1));
	printf("*(p + 2) = %c\n",*(p + 2));
	printf("*(p + 3) = %c\n",*(p + 3));
	printf("*(p + 4) = %c\n",*(p + 4));
	return 0;
}
/* see objdump output */
/*  movzbl (%eax),%eax */

#endif


#if QUES == 62
/* experiments on pointers and arrays */
int main(void)
{
	char a[10] = {'a','b','c','d','e'};
	char *p = NULL;

	p = a;
	printf("p[0] = %c\n",p[0]);
	printf("p[1] = %c\n",p[1]);
	printf("p[2] = %c\n",p[2]);
	printf("p[3] = %c\n",p[3]);
	printf("p[4] = %c\n",p[4]);
	return 0;
}
/* see objdump output */
/* same as above (61) question */
#endif


#if QUES == 63
/* experiments on pointers and arrays */
int main(void)
{
	char a[10] = {'A','B','C','D','E'};

	printf("&a = %p, a = %p, *a = %d\n",&a,a,*a);
	printf("&&a = %p, &a = %p, a = %p, a[0] = %d\n",&&a,&a,a,a[0]);

	return 0;
}
/* error in second printf : label 'a' used but not defined */
#endif


#if QUES == 64
/* experiments on pointers and arrays */
int main(void)
{
	char a[10] = {'A','B','C','D','E'};

	printf("&a = %p, a = %p, a[0] = %d, a[0][0]\n",&a,a,a[0],a[0][0]);
	printf("&a = %p, a = %p, *a = %d, **a\n",&a,a,*a,**a);
	return 0;
}
/* compile time error : subscripted value is neither array nor pointer nor vector */
/* compile time error : invalid type argument of unary type *  */
#endif


#if QUES == 65
/* experiments on pointers and arrays */
int main(void)
{
	char a[10] = {'A','B','C','D','E'};
	char *ptr = NULL;

	ptr = a;

	printf("&&ptr = %p, &ptr = %p, ptr = %p, ptr[0] = %d\n",&&ptr,&ptr,ptr,ptr[0]);
	return 0;
}
/* same error as in 63 : label 'ptr' used but not defined */
#endif


#if QUES == 66
/* experiments in pointers and arrays */
int main(void)
{
	char a[10] = {'A','B','C','D','E'};
	char *ptr = NULL;

	ptr = a;
	printf("&ptr = %p, ptr = %p, ptr[0] = %d, ptr[0][0]\n",&ptr,ptr,ptr[0],ptr[0][0]);
	printf("&ptr = %p, ptr = %p, *ptr = %d, **ptr\n",&ptr,ptr,*ptr,**ptr);
	return 0;
}
/* same as arrays in 64 */
/* compile time error : subscripted value is neither array nor pointer nor vector */
/* compile time error : invalid type argument of unary type *  */
#endif


#if QUES == 67
/* experiment on pointers to arrays of different data types */
int main(void)
{
	char a[10] = {'A','B','C','D','E'};
	int *ptr = NULL;

	ptr = a;
	printf("*(ptr + 0) = %x\n",*(ptr + 0));
	printf("*(ptr + 1) = %x\n",*(ptr + 1));
	printf("*(ptr + 2) = %x\n",*(ptr + 2));
	return 0;
}
#endif


#if QUES == 68
/* experiment on pointers to arrays of different data types */
int main(void)
{
	char a[10] = {'A','B','C','D','E'};
	float *ptr = NULL;

	ptr = a;
	printf("*(ptr + 0) = %f\n",*(ptr + 0));//doubt
	printf("*(ptr + 1) = %f\n",*(ptr + 1));
	printf("*(ptr + 2) = %f\n",*(ptr + 2));
	return 0;
}
/* it will throw a warning during initialization */
/* printf will print some not recognised characters */
#endif


#if QUES == 69
/*experiments in pointer arithmetic */
int main(void)
{
	char a[10] = {'A','B','C','D','E'};
	char *ptr1 = NULL;
	char *ptr2 = NULL;

	ptr1 = &a[1];
	ptr2 = &a[4];

	if (ptr2 < ptr1) {
		printf("Yes \n");
	} else {
		printf("NO\n");
	}
	return 0;
}
/* as expected it will work and give NO as output */
#endif


#if QUES == 70
/* experiments in pointer arithemetic for pointers pointing to different arrays */
int main(void)
{
	char a[10] = {'A','B','C','D','E'};
	int b[10] = {'E','F','G','H','I'};
	char *ptr1 = NULL;
	int *ptr2 = NULL;

	ptr1 = &a[1];
	ptr2 = &b[4];

	if (ptr2 < ptr1) {
		printf("Yes \n");
	} else {
		printf("NO\n");
	}
	return 0;
}
/* warning of distinct pointer types lacks a cast */
#endif


#if QUES == 71
/* experiments on arrays as function arguments */
void func(char a[])
{
	a++;
	//printf("in func %d\n",a);
	//printf("in func a[1] is %c\n",a[1]);
}
int main(void)
{
	char a[10] = {'A','B','C','D','E'};

	func(a);
	printf("a[1] = %c\n",a[1]);
	return 0;
}
/* in func  a[] is treated as pointer not array */ 
#endif


#if QUES == 72
/* experiment on unintialized arrays */
char b[10];
int main(void)
{
	char a[10];

	printf("%s\n",a);
	printf("%s\n",b);
	return 0;
}
#endif


#if QUES == 73
/* experiments on arrays as function arguments */
void func(char a[])
{
	printf("a[0] = %c, a[1] = %c\n",a[0],a[1]);
}
int main(void)
{
	char a[10] = {'A','B','C','D','E'};

	func(a + 2);
	return 0;
}
#endif


#if QUES == 74

/* experiments on pointer to string literal */
int main(void)
{
	char a[] = "abcde";
	char b[] = {'f','g','h','i','j'};
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof(b));
	return 0;
}
/* null character is appended only for string literals */
/* see objdump of this */
#endif


#if QUES == 75
/* experiments on pointer to string literals */
int main(void)
{
	char a[] = "abcde"; 
	char *b = "xyz";

	*(a + 2) = 'g';
	*(b + 1) = 'h';
	printf("a is %s\n",a);
	printf("b is %s\n",b);
	return 0;
}
/* seg fault while assigning to b */
#endif


#if QUES == 76
/* experiments on pointer to string literals */
int main(void)
{
	char *a = {'A','B','C','D','E'};

	printf("%s\n",a);
	return 0;
}
/* it will give warning for execcess initialization and typecasting */
/* and printf will give you seg fault */
#endif


#if QUES == 77
/* experiments on pointer to string literals */
int main(void)
{
	char *a = "abcde" "xyz";

	printf("%s\n",a);
	return 0;
}
/* strings will be combined and null character will be placed at the end */
#endif


#if QUES == 78
/* experiments on pointer to string literals */
int main(void)
{
	char a[] = "abcde" "xyz";

	printf("%s\n",a); 
	return 0;
}
#endif


#if QUES == 79
/* experiments on pointers and arrays and function arguments */
void func(char a[3])
{
	a++;
	//printf("%d\n",a);
	printf("%s\n",a);
}
int main(void)
{
	char a[] = "abcdef";

	func(a);
	return 0;
}
/* the declaration in the function parameter is a pointer */
/* uncomment the printf we will get the type */
#endif


#if QUES == 80
/* experiments on pointers and arrays and function arguments */
void func(int a[3])
{
	//a++;
	printf("%s\n",a);
}
int main(void)
{
	int a[] = {65,66,67,68,69};

	func(a);
	return 0;
}
/* the declaration in the function parameter is a pointer */
#endif


#if QUES == 81
/* experiments on pointers and arrays and function arguments */
void func(char *s)
{
	printf("%s\n",s);
}
int main(void)
{
	char a[] = "abcdef";

	func(&a[2]);	
	return 0;
}
/* we can pass the subarray to the function */
#endif


#if QUES == 82
/* expriments on pointers and string literals */
int main(void)
{
	char a[];
	char *b = NULL;

	a[] = "qwert";
	b = "pqrst";
	printf("a is %s\n",a);
	printf("b is %s\n",b);
	return 0;
}
/*two errors : array size missing acd */
/* expected expression in assingning to that array */
#endif


#if QUES == 83
int main(void)
{
	char a[10];
	char *b = NULL;

	a = "qwert";
	b = "pqrst";
	printf("a is %s\n",a);
	printf("b is %s\n",b);
	return 0;
}
/* error incompatible types char[10] and char *  */
#endif


#if QUES == 84
/* experiments on pointers and string literals */
int main(void)
{
	char *str;
	str = "%d\n";
	str++;
	str++;
	printf(str-2, 300);
	return 0;
}
/* the most common usage of string literal is in i/o fuctions */
#endif


#if QUES == 85
/* usage of string literals */
int main(void)
{
	printf("%c\n", 7["Pointers"]);
	return 0;
}
/* see objdump and direct addressing happens and s is passed */
#endif


#if QUES == 86
/* experiment with arrays and pointers with typecasting */
int main(void)
{
	int arr[3] = {2, 3, 4};
	char *p;
	p = arr;
	p = (char*)((int*)(p));
	printf("%d\n ", *p);
	p = (int*)(p+1);
	printf("%d\n", *p);
	return 0;
}
/* typecasting happens after incrementing */
#endif


#if QUES == 87
/* experiment on pointers and string literal */
int main(void)
{
	char *p;
	p="hello";
	printf("%s\n", *&*&p);
	return 0;
}
/* it make no difference */
#endif


#if QUES == 88
/* experiment on pointers and string literals */
int main(void)
{
	char str1[] = "abcde";
	char str2[] = "XYZ";
	char *s1 = str1, *s2=str2;
	while((*(s1++) = *(s2++)))
		printf("%s", str1);

	printf("\n");
	return 0;
}
/* we will get the output as expected */
#endif


#if QUES == 89
#include <string.h>
/* experiment on string literals */
int main(void)
{
	int i, n;
	char *x="Alice";
	n = strlen(x);
	*x = x[n];
	for(i=0; i<=n; i++)
	{
		printf("%s ", x);
		x++;
	}
	printf("\n");
	return 0;
}
/* we will get seg fault while assigning the value  */
#endif


#if QUES == 90
/* review question */
#include <string.h>
int main()
{
	char *ptr = "hello";
	char a[22];
	strcpy(a, "world");
	printf("%s %s\n",ptr, a);
	return 0;
}
/* output is as expected */
#endif


#if QUES == 91
/* review question */
int main(void)
{
	char *ptr = "hello";
	char a[22];
	*ptr = "world";
	printf("%s %s\n",ptr,a);
	return 0;
}
/* as expected seg fault */
#endif


#if QUES == 92
/* review question */
int main(void)
{
	char *ptr = "helloworld";
	printf(ptr + 4);//doubt 
	return 0;
}
/* format not a string literal */
#endif


#if QUES == 93
int main(void)//doubt
{
	char *ptr = "Pointer in c", arr[15];
	arr[15] = *ptr; // stack smashing detected
	printf("%c",arr[0]);
	return 0;
}
/* A pointer variable which is initialized by a string cannot to assigned to a array variable of size n. Thus some garbage value or empty output will be displayed  */
#endif


#if QUES == 94
/* reviw question */
#include <string.h>
int main(void)
{
	char *str = "His";
	int i;
	for(i = 0; i < strlen(str); i++)
		printf("%s", str++);	
	return 0;
}
/* as calculated we will get the output */
#endif


#if QUES == 95
/* experiments on pointers and const character string */
int main(void)
{
	const char a[10] = "abcde";
	char *ptr = NULL;

	ptr = a;
	*(ptr + 1) = 't';
	printf("a is %s\n",a);
	printf("ptr is %s",ptr);
	return 0;
}
/* since it is not kept in rodata it can be changed */
#endif


#if QUES == 96
/* experiments on pointers and const character string */
const char a[10] = "abcde";
char *ptr = NULL;
int main(void)
{
	ptr = a;
	*(ptr + 1) = 't';
	printf("a is %s\n",a);
	printf("ptr is %s",ptr);
	return 0;
}
/* it is kept in rodata */
#endif


#if QUES == 97
/* experiments on two dimentional array */
int main(void)
{
	int arr[2][3] = {{1,2,3},{6,7,8,}};
	int **ptr = arr;
	printf("&arr is %d\n",&arr);
	printf("arr is %d\n",arr);
	printf("*arr is %d\n",*arr);
	printf("**arr is %d\n",**arr);
	return 0;
}
#endif


#if QUES == 98
/* experiment on typecasting of pointers */
int main(void)
{
	int arr[3] = {2, 3, 4};
	char *p;
	p = arr;
	p = (char*)((int*)(p));
	printf("%d, ", *p);
	p = (int*)(p+1);
	printf("%d", *p);
	return 0;
}
/* as expected the ans is 2,  0 */
/* in the second assignment to p it is incremented by 1 and typecasted to int * and again internally it remains same as char */
#endif


#if QUES == 99
/* experiment on single pointers */
int *ptr = 0x8048000;
int main(void)
{
	*ptr = 23;
	printf("%d\n",*ptr);
	return 0;
}
/* as expected it will give seg fault if the address is not valid */
#endif

#if QUES == 100
/* experiments on two dimensional arrays */
int main(void)
{
	int arr[2][3] = {{1,2,3},{7,8,9}};
	printf("&arr is %p and &arr + 1 is %p\n",&arr,&arr + 1);
	printf("arr is %p and arr + 1 is %p\n",arr,arr + 1);
	printf("arr[0] is %p and arr[0] + 1 is %p\n",arr[0],arr[0] + 1);
	printf("arr[0][0] is %d and arr[0][0] + 1 is %d\n",arr[0][0],arr[0][0] + 1);
	return 0;
}
#endif

#if QUES == 101
/* checking the sizeof the two dimentional array */
int main(void)
{
	int arr[2][3] = {{1,2,3},{7,8,9}};
	printf("sizeof(&arr) is %d\n",sizeof(&arr));
	printf("sizeof(arr) is %d\n",sizeof(arr));
	printf("sizeof(arr[0]) is %d\n",sizeof(arr[0]));
	printf("sizeof(arr[0][0]) is %d\n",sizeof(arr[0][0]));
	return 0;
}
#endif


#if QUES == 102
/* initialising the array of pointers */
int main(void)
{
	char *arr[2] = {"abcd", "efgh"};
	printf("arr[0] is %s\n",arr[0]);
	printf("arr[1] is %s\n",arr[1]);
	return 0;
}
/* as expected the output is abcd efgh */
#endif


#if QUES == 103
/* experiment on initializing an array of pointers */
int main(void)
{
	char *arr[2] = "abcd";
	printf("arr[0] is %s\n",arr[0]);
	printf("arr[1] is %s\n",arr[1]);
	return 0;
}
/* it gives invalid initializer error */
#endif


#if QUES == 104
/* experiments on initializing an array of pointers */
int main(void)
{
	char *arr[2] = {'a','b','c'};

	printf("arr[0] is %s\n",arr[0]);
	printf("arr[1] is %s\n",arr[1]);
	return 0;
}
/* initialization makes pointer from interger without cast */
/* and it gives segmentation fault */
#endif


#if QUES == 105
/* initialization of array of pointers */
int main(void)
{
	char *arr[2];
	arr[0] = "abcd";
	arr[1] = "efgh";
	printf("arr[0] is %s\n",arr[0]);
	printf("arr[1] is %s\n",arr[1]);
	return 0;
}
/* as expected it will give correct output and strings are stored in rodata */
#endif


#if QUES == 106
int main(void)
{
	return 0;
}
#endif
#if QUES == 107
int main(void)
{
	return 0;
}
#endif
#if QUES == 108
int main(void)
{
	return 0;
}
#endif
#if QUES == 109
int main(void)
{
	return 0;
}
#endif
#if QUES == 110
int main(void)
{
	return 0;
}
#endif
#if QUES == 111
int main(void)
{
	return 0;
}
#endif
#if QUES == 112
int main(void)
{
	return 0;
}
#endif
#if QUES == 113
int main(void)
{
	return 0;
}
#endif
#if QUES == 114
int main(void)
{
	return 0;
}
#endif
#if QUES == 115
int main(void)
{
	return 0;
}
#endif
#if QUES == 116
int main(void)
{
	return 0;
}
#endif
#if QUES == 117
int main(void)
{
	return 0;
}
#endif
#if QUES == 118
int main(void)
{
	return 0;
}
#endif
#if QUES == 119
int main(void)
{
	return 0;
}
#endif
#if QUES == 120
int main(void)
{
	return 0;
}
#endif
#if QUES == 121
int main(void)
{
	return 0;
}
#endif
#if QUES == 122
int main(void)
{
	return 0;
}
#endif
#if QUES == 123
int main(void)
{
	return 0;
}
#endif
#if QUES == 124
int main(void)
{
	return 0;
}
#endif
#if QUES == 125
int main(void)
{
	return 0;
}
#endif


