/** This is main program to implement the basic claculator **/
#include <calculator.h> 
//Including the header from the Other Directory
int main ()
{
//Declaring the variables what are we need in this program 
    int _num1 = 0;
    int _num2 = 0;
    int _num3 = 0;
    int _opt = 0;
	int start = 0;
	char _str1[SIZE] = {0};
	char _str2[SIZE] = {0};
//scaning the numbers from the user
	printf(" Enter the _num1:\n ");
    fgets(_str1, SIZE, stdin); //scaning the data from the user
	fflush(stdin); //clearing the stdin buffer

    printf(" Enter the _num2:\n ");
	fgets(_str2, SIZE, stdin);	//scaning the data from the user
    fflush(stdin);  //clearing the stdin buffer
    
    if ((1 == validation(_str1)) && (1 == validation(_str2))) {
		for (start = 0; _str1[start]; start++);
		_str1[start - 1] = '\0'; 
		
		for (start = 0; _str1[start]; start++);
		_str2[start - 1] = '\0';
	} else {
		printf("****** INVALID DATA *******\n");
		return 0;
	}

	printf("%s %s\n", _str1, _str2);
	_num1 = my_atoi(_str1);
	_num2 = my_atoi(_str2);

//scaning which option to do perticular operation  and calling respected function
L2: printf (" 1. Addition\n 2. Subtaction\n 3. Multiplication\n 4. Divi"				"sion\n 5. Exit\n Enter the Option:\n ");
   	scanf ("%d", &_opt);

	if (4 == _opt) {
		if (0 == _num2) {
			printf("*** Division Operation Not Possible\n");
			printf("*** error: floating point exception ***\n");
		}
	}

    switch (_opt) {
//calling the addition funtion to do the addition operation
  	case 1:
	     _num3 = addition(_num1, _num2);
   		 printf(" Addition of _num1 & _num2 = %d\n ", _num3);
   	   	 break;
//calling the subtraction function to do the subtraction operation
	case 2:
	     _num3 = subtraction(_num1, _num2);
		 printf(" Subtraction of _num1 & _num2 = %d\n ", _num3);
         break;
//calling the multiplication function to do the multiplication operation
	case 3:
         _num3 = multiplication(_num1, _num2);
		 printf(" Multiplication of _num1 & _num2 = %d\n", _num3);
		 break;
//calling the division funtion to do the division operation
 	case 4:
         _num3 = division(_num1, _num2);
		 printf(" Division of _num1 & _num2 = %d\n", _num3);
		 break;
	case 5:
		 break; //terminating the switch and goto
    default:
		 printf (" Enter the correct option\n");   
    	 goto L2; 
    }
	
    return 0;
}
