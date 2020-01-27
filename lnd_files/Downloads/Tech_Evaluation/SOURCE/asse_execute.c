/* Function to execute the compiled assessment code */
#include "../HEADER/header.h"

int asse_execute(int assessment_no )
{

	int flag = 0;
	int choice;
	char *int_buffer = NULL;
	char *command_line = NULL;
	char path[MAX_BUF];
	char command[MAX_BUF];
	struct dirent *entry = NULL;
	DIR *dirp = NULL;
	
	if((int_buffer = (char *) malloc ( 10 )) == NULL) {
		perror("Unable to allocate memory");
		exit(EXIT_FAILURE);
	}

	while ( 1 ) {
		printf("\x1b[H\x1b[J");
		printf("\t\t*** EXECUTE OPTIONS ***\n");
		printf("1 : INPUT THROUGH PROGRAM\n");
		printf("2 : INPUT THROUGH COMMAND LINE\n");
		printf("3 : BACK\n");
		printf("Enter your choice : ");

		choice = scan_int(int_buffer, 1 , 3);
		if ( choice == INT_MAX) {
			system("tput setf 4");
			printf("Invalid Choice\n");
			printf("Please enter your choice again\n");
			system("tput sgr0");
			sleep(1);
			continue;
		}
		break;
	}

	
	sprintf(path, "Assessment/Assessment_%d", assessment_no);
	
    if ( NULL == (dirp = opendir(path)) ) {
        perror ("Failed to open directory");
        return -1;
    }

	/* 
	 * Checks if the executable of the respective question is generated or not
	 */
	while (( entry = readdir( dirp )) != NULL) {
		if ( !strcmp( entry -> d_name, "Output")) {
			flag = 1;
			break;
		}
	}
	closedir(dirp);
	
	/* 
	 * If executable is present run the executable
	 */
	if ( flag == 1 ) {
		if ( choice == 1 ) {

			sprintf( command, "./Assessment/Assessment_%d/Output", assessment_no );
			system( command );
			printf("\nPress Enter to return\n");
			getchar();

		} else if ( choice == 2 ) {

			if ( (command_line = (char *) malloc ( MAX_BUF )) == NULL) {
				perror("Unable to allocate memory");
				exit(EXIT_FAILURE);
			}

			printf("Enter the command line inputs :\n---------------\n");
			printf("ex :./add 5 6\n");
			printf("input : 5 6\n---------------\n");
			printf("Your input : ");
			__fpurge(stdin);

			if ( NULL == (fgets(command_line, MAX_BUF , stdin))) {
				perror("Failure in reading input");
				exit(EXIT_FAILURE);
			}

			sprintf( command, "./Assessment/Assessment_%d/Output %s", assessment_no, command_line);
			system( command );
			printf("\nPress Enter to return\n");
			getchar();
		
		} else {
			free(int_buffer);
			return 0;
		}
	} else {
		system("tput setf 4");
		printf("No Executable present to run\n");	
		printf("Please recompile and check if any errors\n");
		system("tput sgr0");
		sleep(1);
	}
	return 0;
}	
