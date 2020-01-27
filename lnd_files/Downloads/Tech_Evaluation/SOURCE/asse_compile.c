/* Function to compile the assessment code written */
#include "../HEADER/header.h"

int asse_compile(int assessment_no )
{

	long size;
	char command[MAX_BUF];
	FILE *fp1 = NULL;

   	if(NULL == (fp1 = fopen("error.err", "w"))) {
		system("tput setf 4");
       	perror("file open failed");
		system("tput sgr0");
       	exit(EXIT_FAILURE);
   	}

	/*
	 * Compiles the code and stores the error in error.err file
	 */
	sprintf( command,
		"gcc -Wall -o Assessment/Assessment_%d/Output Assessment/Assessment_%d/*.c 2>>error.err"
	 ,assessment_no, assessment_no);

	system( command );

    if(NULL != fp1) {
	    fseek(fp1, 0, SEEK_END);
        size = ftell(fp1);
      	fclose(fp1);
            
		if(size != 0) {
			system("tput setf 4");
			printf("\nWarnings or errors generated.. present in error file\n");
			system("tput sgr0");
			printf("If no errors, you can execute the program\n");
			sleep(2);
			system("vim error.err");
				
        } else {
			system("tput setf 2");
			printf("Successfully compiled ... No errors & warnings\n");
			printf("Executable file generated.. You can execute the program\n");
			system("tput sgr0");
			sleep(2);
		}
	}

	system("rm error.err");
	return 0;
}	
