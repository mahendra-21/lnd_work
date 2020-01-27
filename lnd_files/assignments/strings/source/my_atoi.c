/** Implementing Our own atoi() function **/

/* In string operations we are not taking the negative values and signed 
   values */

int my_atoi(const char *str) //funtion definition for 
{
	unsigned int int_num = 0;	
	int start = 0;

//	if ((str[0] == '+') || (str[0] == '-')) {

/* Checking the string having the '+' sign 
   there or not at zero'th position */
    if ('+' == str[0]) {
		start = 1;
	} else {
		start = 0;
	}
/* for-loop for converting the string into number */
	for (; str[start]; start++) {
		int_num = int_num * 10 + (str[start] - 48); // Logic for char-->num
        }
/*
	if ('-' == str[0]) {
		int_num = -int_num;
	}
 */
	return int_num; // returning the integer value to the called function
}
