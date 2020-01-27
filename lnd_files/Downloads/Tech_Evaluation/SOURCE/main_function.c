/* Function to create file and edit main function for respective assignment question */
#include "../HEADER/header.h"

int main_function(int assignment_no, int question_no )
{

	char command[MAX_BUF];

	sprintf( command, "vim Assignment/main_functions/Assignment_%d/main_%d.c", assignment_no, question_no);
	system( command );
			
	return 0;

}	
