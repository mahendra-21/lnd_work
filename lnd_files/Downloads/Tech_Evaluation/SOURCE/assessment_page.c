/* Function to display Menu for Assessment */
#include "../HEADER/header.h"
int assessment_page( void )
{
	char *int_buffer = NULL;
	char fun[MAX_BUF];
	char main_fun[MAX_BUF];
	int choice;
	int assessment_no;


    if((int_buffer = (char*) malloc ( 10 )) == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
	printf("\x1b[H\x1b[J");	
	system("tput bold");
	system("tput setf 6");
	printf("\t\t\t***ASSESSMENT***\n");
	system("tput sgr0");
	printf("1: Assesment question 1\n");
	printf("2: Assessment question 2\n");
	
	printf("Enter the Assessment question to attempt [1-2] : ");
	
	assessment_no = scan_int(int_buffer, 1, 2);	
	if (assessment_no == INT_MAX) {
		system("tput setf 4");
		printf("Invalid Choice\n");
		system("tput sgr0");
		sleep(1);
		return 0;
	}

	while ( 1 ) {
		printf("\x1b[H\x1b[J");	
		system("tput bold");
		system("tput setf 6");
		printf("\t\t*** ASSESSMENT %d ***\n", assessment_no);
		system("tput sgr0");
		printf("1: WRITE CODE FOR FUNCTION\n");
		printf("2: WRITE CODE FOR MAIN\n");
		printf("3: COMPILE \n");
		printf("4: EXECUTE \n");
		printf("5: VALIDATE \n");
		printf("6: MAIN PAGE\n");
		printf("7: EXIT\n\n");
		printf("Enter your choice : ");
		
		choice = scan_int(int_buffer, 1, 7);	
		if (choice == INT_MAX) {
			system("tput setf 4");
			printf("Invalid Choice\n");
			printf("Please enter your choice again\n");
			system("tput sgr0");
			sleep(1);
			continue;
		}

		
		switch ( choice )
		{
			case ASSE_FUN: 		sprintf( fun, "vim Assessment/Assessment_%d/fun.c", 
											assessment_no);
						   		system(fun);
						   		break;

			case ASSE_MAIN: 	sprintf( main_fun, "vim Assessment/Assessment_%d/main.c", 
											assessment_no);
								system(main_fun);
						    	break;
			
			case ASSE_COMPILE: 	asse_compile(assessment_no); 
						  		break;
	
			case ASSE_RUN: 		asse_execute(assessment_no);
					  			break;

			case ASSE_VALIDATE: asse_test_case_match(assessment_no);
								break;
			
			case ASSE_BACK: 	return 0;
					   			break;
			
			case ASSE_QUIT:  	system("tput setf 4");
								printf("EXITING THE PROGRAM\n");
								system("tput sgr0");
					   			exit(EXIT_SUCCESS);
					   			break;
			
			default : 			break;
		}
	}
	return 0;

}
