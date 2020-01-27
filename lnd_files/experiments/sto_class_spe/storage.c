/* In main change the value "num" with out 
   	disturbing "num" in main function
 */

#include <stdio.h>

int *ptr;
void exter(void);

int main()
{
	int num = 10;
	ptr = &num;
	exter();
	printf("number = %d\n", num);
	return 0;
}

void exter(void)
{
	++(*ptr);
}
