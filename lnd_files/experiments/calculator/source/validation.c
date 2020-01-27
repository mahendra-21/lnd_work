/* Validation Funtion for the raw data */

int validation(const char *_str)
{
	int start = 0;

	for (start = 0; _str[start]; start++) { 
        
        if (_str[start] == ' ') {
            while (_str[start] == ' ') {
                start++;
            }
        }

		if ((_str[0] == '-') || (_str[0] == '+')) {
			continue; 
		} else if ((_str[start] >= '0') && (_str[start] <= '9')) {
			continue;
		} else {
			if (_str[start] == '\n') {
				break;
			}
			return 0;
		}
	}	

	return 1;
}			
