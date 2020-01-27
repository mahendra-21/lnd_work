/* Funtion to display menu for Assignment */

#include "../HEADER/header.h"

int assignment_page( void )
{
	char *int_buffer = NULL;
    char proto[MAX_BUF];
    char buffer[MAX_BUF];
	int choice;
	int assignment_no;
	int question_no;
	int total_ques;
	FILE *fp_proto = NULL;


    if((int_buffer = (char*) malloc ( 10 )) == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

	printf("\x1b[H\x1b[J");	
	system("tput bold");
	system("tput setf 6");
	printf("\t\t\t***ASSIGNMENTS***\n");
	system("tput sgr0");
	printf("1: Bitwise Assignment\n");
	printf("2: String Assignment\n");
	printf("3: Commandline Assignment\n");
	printf("4: Data Structures Assignment\n");
	printf("5: File Operations Assignment\n\n");
	
	printf("Enter the Assignment number which u want to work on [1-5] : ");
	
	assignment_no = scan_int(int_buffer, 1, 5);	
	if (assignment_no == INT_MAX) {
		system("tput setf 4");
		printf("Invalid assignment choice\n");
		printf("Returning to main page\n");
		system("tput sgr0");
		free(int_buffer);
		sleep(1);
		return 0;
	}

    sprintf( proto, "Assignment/prototype/proto_%d.txt", assignment_no );
	if(NULL == ( fp_proto = fopen( proto, "r"))) {
		system("tput setf 4");
		perror("Prototype file open failed\n");
		system("tput sgr0");
        exit(EXIT_FAILURE);
    }

    fgets( buffer, MAX_BUF, fp_proto );
    total_ques = myatoi(buffer);
    fclose(fp_proto);

	printf("Enter the question number you want to work on [1 - %d]: ",total_ques);
	question_no = scan_int(int_buffer, 1, total_ques);
	if (question_no == INT_MAX) {
		system("tput setf 4");
		printf("Invalid question choice\n");
		printf("Returning to main page\n");
		system("tput sgr0");
		free(int_buffer);
		sleep(1);
		return 0;
	}

	while ( 1 ) {
		printf("\x1b[H\x1b[J");	
		system("tput bold");
		system("tput setf 5");
		printf("\t\t*** ASSIGNMENT %d ***\n", assignment_no);
		system("tput setf 3");
		printf("\t\t*** QUESTION %d   ***\n", question_no);
		system("tput sgr0");
		printf("1: WRITE CODE FOR STANDARD FUNCTION\n");
		printf("2: WRITE CODE FOR MAIN FUNCTION\n");
		printf("3: WRITE CODE FOR SUB FUNCTION\n");
		printf("4: COMPILE \n");
		printf("5: EXECUTE \n");
		printf("6: VALIDATION \n");
		printf("7: MAIN PAGE\n");
		printf("8: EXIT\n\n");
		printf("Enter your choice : ");
		
		choice = scan_int(int_buffer, 1, 8);	
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
			case STD_FUN : standard_function(assignment_no, question_no); 
						   break;

			case MAIN_FUN : main_function(assignment_no, question_no);
						    break;
	
			case SUB_FUN : sub_func_page(assignment_no);
						   break;
			
			case COMPILE : compile(assignment_no, question_no); 
						   break;
	
			case RUN : execute(assignment_no, question_no);
					   break;

			case VALIDATE : test_case_match(assignment_no, question_no);
							break;
			
			case BACK : return 0;
					    break;
			
			case QUIT:  system("tput setf 4");
						printf("EXITING THE PROGRAM\n");
						system("tput sgr0");
					   	exit(EXIT_SUCCESS);
					   	break;
			
			default : break;
		}
	}
	free(int_buffer);
	return 0;

}
