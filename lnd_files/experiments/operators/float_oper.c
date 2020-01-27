#include <stdio.h>
int main ()
{
	float f1=2.34;
	float f2=3.32;
	//float f3=f1/f2;
	//float f3=f1%f2;
	//float f3=f1|f2;
	//float f3=f1&&f2;
	float f3 = ++ f1 - f2++;
	printf("%f\n",f3);
	return 0;
}
