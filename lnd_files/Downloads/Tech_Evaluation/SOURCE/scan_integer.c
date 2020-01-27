/* Function to read input and convert string to integer if valid input */

#include "../HEADER/header.h"

int scan_int(char *input, int min_range, int max_range)
{
	int n;

	input = read_input(input);
	if (intval(input) || (n = myatoi(input)) > max_range 
					  || n < min_range) {
		return INT_MAX;
	}
	return n;
}
