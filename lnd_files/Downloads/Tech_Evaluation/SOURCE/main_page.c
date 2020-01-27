/* 
 * Main Function to display the main page of training evaluation application 
 */
#include "../HEADER/header.h"
int main ( void )
{
	char *int_buffer = NULL;
	int choice;

    if((int_buffer = (char*) malloc ( 10 )) == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
	system("reset");
	system("rm error.err");


	while ( 1 ) {
		printf("\x1b[H\x1b[J");
		system("tput bold");
		printf("\t\t\t*** MAIN PAGE ***\n");
		system("tput sgr0");
		printf("1:Assignment \n2:Assessment\n3:Exit\n\n");
		printf("Enter your choice [ 1-3 ] : ");
		
		choice = scan_int(int_buffer, 1, 3);	
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
			case ASSIGNMENT: assignment_page(); 
							 break;
	
			case ASSESSMENT: assessment_page(); 
							  break;
	
			case EXIT:  system("tput setf 4"); 
						printf("EXITING THE PROGRAM\n");
						system("tput sgr0");
					    return 0;
			
			default : break;
		}
	}
	return 0;
}
