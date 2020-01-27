/** Implementing Our own atoi() function **/
int my_atoi (const char *str)
{
	int int_num = 0;	
	int start;

	if ((str[0] == '+') || (str[0] == '-')) {
		start = 1;
	} else {
		start = 0;
	}

	for (; str[start]; start++) {
		int_num = int_num * 10 + (str[start] - 48);
	}

	if (str[0] < 0) {
		int_num = -int_num;
	}

	return int_num;
}
