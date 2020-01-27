/* Funtion to validate test cases */
#include "../HEADER/header.h"

int asse_test_case_match(int assessment_no)
{

	int flag = 1;
	int i;
	int total_tc;
	int tc_count = 0;
	int attempts = 0;
	char path[MAX_BUF];
	char test_case[MAX_BUF];
	char command[MAX_BUF];
	char buffer[MAX_BUF];
	char exp_output[MAX_BUF];
	char act_output[MAX_BUF];
	struct dirent *entry = NULL;
	DIR *dirp = NULL;
	FILE *fd1 = NULL;
	FILE *fd2 = NULL;
	FILE *fd3 = NULL;
	FILE *fd4 = NULL;

    sprintf(path, "Assessment/Assessment_%d", assessment_no);

	if ( NULL == (dirp = opendir(path)) ) {
		perror ("Failed to open directory\n");
		return -1;
    }

    while (( entry = readdir( dirp )) != NULL) {
        if ( !strcmp( entry -> d_name, "Output")) {
            flag = 0;
            break;
        }
    }																			    
	closedir( dirp);

	if ( flag == 1 ) {
		system("tput setf 4");
		printf("No Executable generated to match test cases\n");
		printf("Please compile the program and check if any errors\n");
		system("tput sgr0");
		sleep(2);
		return 0;
	}

	sprintf( path, "Assessment/test_cases/Assessment_%d", assessment_no);
	sprintf( test_case, "inputfile.txt");
    if ( NULL == (dirp = opendir(path)) ) {
        perror ("Failed to open directory\n");
        return -1;
    }

	while (( entry = readdir( dirp )) != NULL) {
		if ( !strcmp( entry -> d_name, test_case)) {
			flag = 1;
			break;
		}
	}
	
	closedir( dirp );

	if ( flag == 1 ) {
		sprintf( test_case, "%s/inputfile.txt", path);
		if ( NULL == ( fd1 = fopen ( test_case , "r"))) {
			perror("File open failed\n");
			exit(EXIT_FAILURE);
		}

		sprintf( test_case, "%s/outputfile.txt", path);
		if ( NULL == ( fd2 = fopen ( test_case , "r"))) {
			perror("File open failed\n");
			exit(EXIT_FAILURE);
		}

	
		if( NULL == fgets( buffer, MAX_BUF, fd1)) {
			perror("Some Fault in validation");
			return 0;
		}
		total_tc = myatoi(buffer);
		if( NULL == fgets( buffer, MAX_BUF, fd1)) {
			perror("Some fault in validation");
			return 0;
		}

		if ( (*buffer == 'p') || (*buffer == 'P') ) {
		
			for( i = 1; i <= total_tc; i++) {
				flag = 1;
				if ( NULL == ( fd3 = fopen ( "input.txt", "w+"))) {
					perror("File open to write failed");
					exit(EXIT_FAILURE);
				}

				while(*buffer != EOF) {
					fgets( buffer, MAX_BUF, fd1);
					if ( *buffer == '\n' ) 
						break;
					fwrite(buffer, strlen(buffer), 1, fd3);
				}
				fclose(fd3);
				sprintf( command, "./Assessment/Assessment_%d/Output < input.txt > output.txt", assessment_no);
				system( command );
				
				if ( NULL == ( fd4 = fopen ( "output.txt", "a+"))) {
					perror("File open to write failed");
					exit(EXIT_FAILURE);
				}

				fseek(fd4, 0, SEEK_END);
				if( ftell(fd4) == 0 ) {
					flag = 0;
					fseek(fd4,0,SEEK_SET);
					fprintf(fd4,"No Output\n");
					do {
						if( NULL == fgets(exp_output , MAX_BUF, fd2)) 
							break;
					} while(*exp_output != '\n');
				} else {
					fseek(fd4,0,SEEK_SET);
					while( (NULL != fgets(act_output, MAX_BUF, fd4)) &&
							(*act_output != '\n') && (*act_output != EOF)) {
						fgets(exp_output, MAX_BUF, fd2);
						if (*exp_output == '\n') {
							flag = 0;
							break;
						}
						if( strcmp(act_output, exp_output) ) {
							flag = 0;
							break;
						}
					}
				}
				while(*exp_output != '\n' && *exp_output != EOF) {
					if ( NULL == fgets(exp_output, MAX_BUF, fd2))
						break;
				}
				fclose(fd4);
	
				if ( 0 == flag){
					system("cat input.txt > failed_i.txt");
					system("cat output.txt > failed_o.txt");
					system("tput bold");
					system("tput setf 4");
					printf("FAILED : %d\n",i);
					system("tput sgr0");
				} else {
					system("tput bold");
					system("tput setf 2");
					printf("PASSED : %d\n",i);
					system("tput sgr0");
					tc_count++;
				}
			}
		} else if ( (*buffer == 'C') || (*buffer == 'c') ) {
			for( i = 1; i <= total_tc; i++) {
				flag = 1;

				while ( (NULL == fgets( buffer, MAX_BUF, fd1)) || *buffer == '\n' ) {
					continue;
				}
				rm_new_line(buffer);
				sprintf( command, "./Assessment/Assessment_%d/Output %s > output.txt", assessment_no , buffer);
				system( command );
		
				if ( NULL == ( fd4 = fopen ( "output.txt", "a+"))) {
					perror("File open to write failed");
					exit(EXIT_FAILURE);
				}
				fseek(fd4, 0, SEEK_END);
				if( ftell(fd4) == 0 ) {
					flag = 0;
					fseek(fd4,0,SEEK_SET);
					fprintf(fd4,"No Output\n");
					do {
						if( NULL == fgets(exp_output , MAX_BUF, fd2)) 
							break;
					} while(*exp_output != '\n');

				} else {
					fseek(fd4,0,SEEK_SET);
					while( (NULL != fgets(act_output, MAX_BUF, fd4)) &&
							(*act_output != '\n') && (*act_output != EOF)) {
						fgets(exp_output, MAX_BUF, fd2);
						if (*exp_output == '\n') {
							flag = 0;
							break;
						}
						if( strcmp(act_output, exp_output) ) {
							flag = 0;
							break;
						}
					}
				}
				while(*exp_output != '\n' && *exp_output != EOF) {
					if ( NULL == fgets(exp_output, MAX_BUF, fd2))
						break;
				}
				fclose(fd4);
						
					
				if ( 0 == flag){
					if ( NULL == ( fd3 = fopen ( "input.txt", "w+"))) {
						perror("File open to write failed");
						exit(EXIT_FAILURE);
					}
					fprintf(fd3,"%s",buffer);
					fclose(fd3);
					system("cat input.txt > failed_i.txt");
					system("cat output.txt > failed_o.txt");
					system("tput bold");
					system("tput setf 4");
					printf("FAILED : %d\n",i);
					system("tput sgr0");
				} else {
					system("tput bold");
					system("tput setf 2");
					printf("PASSED : %d\n",i);
					system("tput sgr0");
					tc_count++;
				}
			}
		} else {
			fclose(fd1);
			fclose(fd2);
			printf("Improper Test case file\n");
			getchar();
			return 0;
		}
			
		printf("\nNumber of test cases passed: %d of %d\n\n",tc_count, total_tc);

		if ( tc_count < total_tc ) {
			system("tput setf 4");
			system("tput bold");
			printf("FAILED TEST CASE : \n");
			system("tput setf 2");
			printf("Input :\n");
			system("tput sgr0");
			system("cat failed_i.txt");
			system("tput bold");
			system("tput setf 6");
			printf("\nYour Output :\n");
			system("tput sgr0");
			system("cat failed_o.txt");
		} else if ( tc_count == total_tc ) {
			system("tput bold");
			system("tput setf 2");
			printf("Cleared all test cases\n");
			system("tput sgr0");
		}
	
		system("rm input.txt");
		system("rm output.txt");
	
		sprintf( path, "Assessment/Assessment_%d/record.csv", assessment_no);
		if ( NULL == ( fd3 = fopen ( path, "a+"))) {
			perror("File open to write failed");
			exit(EXIT_FAILURE);
		}

		while(NULL != fgets(buffer, MAX_BUF, fd3)) {
			sscanf(buffer," %u ", &attempts);
		}
	
		fprintf(fd3, "%2u , %2u , %2u , %3.2f%\n", ++attempts, tc_count, total_tc, ((float)tc_count/(float)total_tc) * 100 );

		
		getchar();
		fclose(fd1);
		fclose(fd2);
		fclose(fd3);
	
	} else {
		printf("No Test cases defined for this question\n");	
		printf("Verify output yourself\n");
		sleep(1);
	}
	
	return 0;

}	
