/* Function to open a file to edit standard function with its respective prototype */
#include "../HEADER/header.h"

int standard_function(int assignment_no, int question_no )
{

	int flag = 0;
	int i;
	char path[MAX_BUF];
	char proto[MAX_BUF];
	char ques_no[MAX_BUF];
	char command[MAX_BUF];
	char buffer[MAX_BUF];	
	struct dirent *entry = NULL;
	FILE *fp_proto = NULL;
	FILE *fp1 = NULL;
	DIR *dirp = NULL;

	sprintf(ques_no, "ques_%d.c", question_no);
	sprintf( path, "Assignment/standard_functions/Assignment_%d", assignment_no);
	
    if ( NULL == (dirp = opendir(path)) ) {
        perror ("Failed to open directory\n");
        return -1;
    }

	while (( entry = readdir( dirp )) != NULL) {
		if ( !strcmp( entry -> d_name, ques_no)) {
			flag = 1;
			break;
		}
	}
	sprintf(ques_no, "ques_%d", question_no);

	sprintf( command, "vim %s/%s.c", path, ques_no);
	
	if ( flag == 1 ) {
		system( command );
	} else {
		sprintf( ques_no, "%s/ques_%d.c", path, question_no );
		sprintf( proto, "Assignment/prototype/proto_%d.txt", assignment_no );

		if( NULL == ( fp1 = fopen( ques_no, "w+" ))) {
        	perror("file opening failed");
            exit( EXIT_FAILURE );
		}

		if(NULL == ( fp_proto = fopen( proto, "r"))) {
        	perror("file open failed");
        	exit(EXIT_FAILURE);
    	}

		for ( i = 0; i <= ( 5 * ( question_no - 1 ) ); i++ ) {
			fgets( buffer, MAX_BUF, fp_proto );
		}
		
        do {
            fgets( buffer, MAX_BUF, fp_proto);
            fwrite( buffer, 1, strlen(buffer), fp1);
        } while (*buffer != '}');

		fclose( fp1 );
		fclose( fp_proto );
		closedir( dirp );
		system( command );
			
	}
	return 0;

}	
