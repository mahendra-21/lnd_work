/* Functions to LIST, EDIT, CREATE, DELETE a sub function */
#include "../HEADER/header.h"

int sub_func_page( int assignment_no )
{
	char *int_buffer = NULL;
	int choice;

    if((int_buffer = (char*) malloc ( 10 )) == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

	while ( 1 ) {
		printf("\x1b[H\x1b[J");
		printf("\t\t\t\t*** SUB_FUNCTION OPTIONS ***\n");
		printf("1: LIST THE FUNCTIONS PRESENT AND EDIT\n");
		printf("2: CREATE NEW SUBFUNCTION\n");
		printf("3: DELETE SUBFUNCTION\n");
		printf("4: BACK\n");
		printf("5: EXIT\n\n");
		printf("Enter your choice : ");
			
		choice = scan_int(int_buffer, 1, 5);	
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
			case LIST: list_sub_func(assignment_no); 
					   break;
		
			case CREATE: create_sub_func(assignment_no);
				  		 break;
			
			case DELETE: delete_sub_func( assignment_no);
						 break;
			
			case PREV_PAGE: free(int_buffer);
							return 0; 
					  		break;
	
			case ABORT: printf("EXITING THE PROGRAM\n");
						exit(EXIT_SUCCESS);
						break;
			
			default : break;
		}
	}
	free(int_buffer);
	return 0;

}


int list_sub_func(int assignment_no )
{

	int func_choice;
	int i;
	char path[MAX_BUF];
	char command[MAX_BUF];
	char *int_buffer = NULL;
	struct dirent *entry = NULL;
	DIR *dirp = NULL;

    if((int_buffer = (char*) malloc ( 10 )) == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    sprintf( path, "Assignment/sub_functions/Assignment_%d", assignment_no);
	printf("\x1b[H\x1b[J");

    if ( NULL == (dirp = opendir(path)) ) {
        perror ("Failed to open directory\n");
        exit(EXIT_FAILURE);
    }

	i = 0;
	while (( entry = readdir( dirp )) != NULL) {
		if( strcmp( entry -> d_name , ".") 
			&& (strcmp( entry -> d_name , "..")) 
			&& ( strcmp( entry -> d_name , "dont_remove.c")) ) {
			if( i == 0 )
				printf("The functions present are :\n");
			printf("%d: %s\n", ++i, entry -> d_name);
		}
	}
	closedir( dirp );

	if ( i == 0 ) {
		printf("Unable to list as there are no sub function present\n");
		free(int_buffer);
		sleep(1);
		return 0;
	}

	printf("\nEnter the respective number of function you want to edit[back : 0] [1-%d]: ", i);
	while( 1 ) {
		func_choice = scan_int(int_buffer, 0, i);	
		if (func_choice == INT_MAX) {
			printf("\nInvalid Choice ...");
			printf(" Please enter correct file number [back : 0] [1-%d] ", i);
			continue;
		}
		break;
	}

	if ( func_choice == 0 ) {
		printf("Returning to previous page\n");
		free(int_buffer);
		sleep(1);
		return 0;
	}

    if ( NULL == (dirp = opendir(path)) ) {
        perror ("Failed to open directory\n");
        exit(EXIT_FAILURE);
    }

	for ( i = 0; i < func_choice ; ) {
		if ( NULL == (entry = readdir( dirp )) ) {
			perror("Failed to read directory...\n");
			exit(EXIT_FAILURE);
		}

		if( strcmp( entry -> d_name , ".") 
				&& (strcmp( entry -> d_name , "..")) 
				&& ( strcmp( entry -> d_name , "dont_remove.c")) ) {
			i++;
		}
	}
	
	sprintf( command, "vim Assignment/sub_functions/Assignment_%d/%s", 
							assignment_no, entry -> d_name );
	system( command );
	free(int_buffer);
	return 0;

}


int create_sub_func( int assignment_no ) 
{

	char *name = NULL;
	char command[MAX_BUF];
	
    if((name = (char*) malloc ( MAX_BUF )) == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
	printf("Enter the name for the new file (ex: myatoi) : ");

	__fpurge(stdin);
    if (NULL == (fgets(name, MAX_BUF, stdin))) {
	    printf("Failure in read_input\n");
		exit(EXIT_FAILURE);
	}

	if ( file_name_val(name) ) {
		printf("Invalid File name.. Going back to previous page\n");
		sleep(1);
		free(name);
		return 0;
	}
	
	sprintf( command, "vim Assignment/sub_functions/Assignment_%d/%s.c", assignment_no, name );
	system( command );

	free(name);
	return 0;

}



int delete_sub_func(int assignment_no)
{

	int func_choice;
	int i;
	char path[MAX_BUF];
	char command[MAX_BUF];
	char *int_buffer = NULL;
	struct dirent *entry = NULL;
	DIR *dirp = NULL;

    if((int_buffer = (char*) malloc ( 10 )) == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    sprintf( path, "Assignment/sub_functions/Assignment_%d", assignment_no);
	printf("\x1b[H\x1b[J");

    if ( NULL == (dirp = opendir(path)) ) {
        perror ("Failed to open directory\n");
        exit(EXIT_FAILURE);
    }

	i = 0;
	while (( entry = readdir( dirp )) != NULL) {
		if( strcmp( entry -> d_name , ".") 
			&& (strcmp( entry -> d_name , "..")) 
			&& ( strcmp( entry -> d_name , "dont_remove.c")) ) {
			if( i == 0 )
				printf("The functions present are :\n");
			printf("%d: %s\n", ++i, entry -> d_name);
		}
	}
	closedir( dirp );

	if ( i == 0 ) {
		printf("Unable to list as there are no sub function present\n");
		free(int_buffer);
		sleep(1);
		return 0;
	}

	printf("\nEnter the respective number of function you want to edit[back : 0] [1-%d]: ", i);
	while( 1 ) {
		func_choice = scan_int(int_buffer, 0, i);	
		if (func_choice == INT_MAX) {
			printf("\nInvalid Choice ...");
			printf(" Please enter correct file number [back : 0] [1-%d] ", i);
			continue;
		}
		break;
	}

	if ( func_choice == 0 ) {
		printf("Returning to previous page\n");
		free(int_buffer);
		sleep(1);
		return 0;
	}

    if ( NULL == (dirp = opendir(path)) ) {
        perror ("Failed to open directory\n");
        exit(EXIT_FAILURE);
    }

	for ( i = 0; i < func_choice ; ) {
		if ( NULL == (entry = readdir( dirp )) ) {
			perror("Failed to read directory...\n");
			exit(EXIT_FAILURE);
		}

		if( strcmp( entry -> d_name , ".") 
				&& (strcmp( entry -> d_name , "..")) 
				&& ( strcmp( entry -> d_name , "dont_remove.c")) ) {
			i++;
		}
	}
	
	sprintf( command, "rm Assignment/sub_functions/Assignment_%d/%s", 
							assignment_no, entry -> d_name );
	system( command );
	free(int_buffer);
	return 0;
}
