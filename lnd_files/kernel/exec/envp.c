/*
	Program to print the environment list that is
	used in execle(), execve() & execvpe() functions
	using envp[] and environ & also understand the use 
	of getenv(), setenv() functions
*/
	
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define ENV_VAR "PWD"
#define ENV_VAL "/"

int main( int argc, char *argv[], char *envp[] )
{
	/*	environ - array of character pointers to the environment strings */
	extern char **environ;
	int i = 0;
	int ret = -1;
	char *env_str = NULL;
	
	/*	Using envp[] to print the environment list */
	while( envp[i] != NULL )
	{
		printf( "%s\n", envp[i] );
		i++;
	}
	printf( "\n" );
	
	i = 0;
	/*	Using environ to print the environment list	*/
	while( environ[i] != NULL )
	{
		printf( "%s\n", environ[i] );
		i++;
	}
	printf( "\n" );
	
	env_str = getenv( ENV_VAR );
	
	/*	getenv() functions returns the environment variable value as string
		specified by the argument to getenv()
		Returns NULL if not found
	*/
	
	if( env_str == NULL )
	{
		printf( "No environment value found for %s\n", ENV_VAR );
		return EXIT_FAILURE;
	}
	
	/*	Print the returned environment variable value */
	printf( "%s = %s\n", ENV_VAR, env_str );
	
	/*	setenv() functions sets the environment variable value as specified
		in the second argument for the environment variable in the first argument.
		The third argument specifies whether to overwrite or to maintain a separate copy.
		Returns -1 on failure, 0 on success
	*/
	ret = setenv( ENV_VAR, ENV_VAL, 1 );
	if( ret == -1 )
	{
		printf( "setenv() failed : %s\n", strerror( errno ) );
		return EXIT_FAILURE;
	}
	
	/*	Fetching the new updated value */ 
	env_str = getenv( ENV_VAR );
	if( env_str == NULL )
	{
		printf( "No environment value found for %s\n", ENV_VAR );
		return EXIT_FAILURE;
	}
	
	/*	Print the new environment variable value */
	printf( "%s = %s\n", ENV_VAR, env_str );
	
	i = 0;
	/*	Using environ to print the environment list	*/
	while( environ[i] != NULL )
	{
		printf( "%s\n", environ[i] );
		i++;
	}
	printf( "\n" );
	return EXIT_SUCCESS;
}
