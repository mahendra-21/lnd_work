/* Function to compile the respective assignment question */

#include "../HEADER/header.h"

int compile (int assignment_no, int question_no)
{

	int flag = 0;
	long size;
	char main_path[MAX_BUF];
	char standard_path[MAX_BUF];
	char output_path[MAX_BUF];
	char temp[MAX_BUF];
	char directory_path[MAX_BUF];
	char command[MAX_BUF];
	struct dirent *entry = NULL;
	FILE *fp1 = NULL;
	DIR *dirp = NULL;
	
	sprintf(temp, "main_%d.c", question_no);
	sprintf(directory_path, "Assignment/main_functions/Assignment_%d", assignment_no);
		
    if ( NULL == (dirp = opendir(directory_path)) ) {
        perror ("Failed to open directory\n");
        exit(EXIT_FAILURE);
    }

	while (( entry = readdir( dirp )) != NULL) {
		if ( !strcmp( entry -> d_name, temp)) {
			flag = 1;
			break;
		}
	}

	if ( flag == 0 ) {
		printf("No main function written for respective question.. Cannot Compile\n");
		printf("Returning back to previous page\n");
		sleep(2);
		return 0;
	}

	flag = 0;
	sprintf(temp, "ques_%d.c", question_no);
	sprintf(directory_path, "Assignment/standard_functions/Assignment_%d", assignment_no);		
    if ( NULL == (dirp = opendir(directory_path)) ) {
        perror ("Failed to open directory\n");
        exit(EXIT_FAILURE);
    }

	while (( entry = readdir( dirp )) != NULL) {
		if ( !strcmp( entry -> d_name, temp)) {
			flag = 1;
			break;
		}
	}

	if ( flag == 0 ) {
		printf("No standard function written for respective question.. Cannot Compile\n");
		printf("Returning back to previous page\n");
		sleep(2);
		return 0;
	}
	
    //this is to store the error messages
   	if(NULL == (fp1 = fopen("error.err", "w"))) {
       	perror("file open failed");
       	exit(EXIT_FAILURE);
   	}

	sprintf(main_path, "Assignment/main_functions/Assignment_%d/main_%d.c"
					, assignment_no, question_no);

	sprintf(standard_path, "Assignment/standard_functions/Assignment_%d/ques_%d.c"
					, assignment_no, question_no);

	sprintf(output_path, "Assignment/Output/Assignment_%d/output_%d"
					, assignment_no, question_no);

	sprintf( command,
		"gcc -Wall -o %s %s %s Assignment/sub_functions/Assignment_%d/*.c 2>>error.err"
		, output_path, main_path, standard_path, assignment_no);

	system( command );
    if(NULL != fp1) {
	    fseek(fp1, 0, SEEK_END);
        size = ftell(fp1);
      	fclose(fp1);
            
		if(size != 0) {
			system("tput setf 4");
			printf( "Warnings or errors generated.. present in error.err file\n");
			system("tput sgr0");
			sleep(2);
			system("vim error.err");
				
        } else {
			system("tput setf 2");
			printf("Successfully compiled ... No Errors\n");
			printf("Executable file generated.. You can execute the program\n");
			system("tput sgr0");
			sleep(2);
		}
	}

	system("rm error.err");
	return 0;

}	
