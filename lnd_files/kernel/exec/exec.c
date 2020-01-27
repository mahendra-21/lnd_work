
#define _GNU_SOURCE	/* Required for execvpe() */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main( int argc, char *argv[], char *envp[] )
{
	int ret = -1;
	
	char *args[] = { "ls", "-l", "-a", "-h", "-t", (char *)0 };

	/*	args[] - Argument array for execv() and execvp()
		[1] First argument args[0] should be the name of the executable
		[2] Arguments args[1] to args[n-1] are the user specified argumants to the executable
		[3] Last argument args[n] should be a NULL pointer which is used to indicate the
			end of argument list, since it is a variable length list.
	*/ 
	
	#if EXECL
	printf( "Output of execl()\n" );
	/*
		execl() - exec with arguments as list
		[1] Takes the absolute/relative pathname of a file as first argument
		[2] Second argument onwards the argument list starts
			arg0 - must be the name of the executable
			arg1 to argn-1 - are the user specified arguments for the executable
			argn should be a NULL pointer which is used to indicate the 
			end of the argument list.
	*/
	ret = execl( "/usr/bin/ls", "ls", "-l", "-h", "-a", (char *)0 );
	if( ret == -1 )
	{
		printf( "execl() failed : %s\n", strerror( errno ) );
		return EXIT_FAILURE;
	}
	#endif

	#if EXECLP
	printf( "Output of execlp()\n" );
	/*
		execlp() - exec with arguments as list & evaluates PATH
		[1] Takes the filename as first argument and searches the path entries in
			environment variable $PATH for the executable file specified
		[2] Second argument onwards the argument list starts
			arg0 - must be the name of the executable
			arg1 to argn-1 - are the user specified arguments for the executable
			argn should be a NULL pointer which is used to indicate the 
			end of the argument list.
	*/
	ret = execlp( "ls", "ls", "-l", "-a", (char *)0 );
	if( ret == -1 )
	{
		printf( "execlp() failed : %s\n", strerror( errno ) );
		return EXIT_FAILURE;
	}
	#endif
	
	#if EXECV
	printf( "Output of execv()\n" );
	/*
		execv() - exec with arguments as vector/array
		[1] Takes the absolute/relative pathname of a file as first argument
		[2] Second argument is the argument vector/array - args[]
	*/
	ret = execv( "/usr/bin/ls", args );
	if( ret == -1 )
	{
		printf( "execv() failed : %s\n", strerror( errno ) );
		return EXIT_FAILURE;
	}
	#endif

	#if EXECVP
	printf( "Output of execvp()\n" );
	/*
		execvp() - exec with arguments as vector/array and evaluates PATH	
		[1] Takes the filename as first argument and searches the path entries in
			environment variable $PATH for the executable file specified
		[2] Second argument is the argument vector/array - args[]
	*/
	ret = execvp( "ls", args );
	if( ret == -1 )
	{
		printf( "execvp() failed : %s\n", strerror( errno ) );
		return EXIT_FAILURE;
	}
	#endif

	#if EXECVE
	printf( "Output of execve()\n" );
	/*
		execve() - exec with arguments as vector/array along with environment list	
		[1] Takes the absolute/relative pathname of a file as first argument
		[2] Second argument is the argument vector/array - args[]
		[3] Third argument is the environment list - envp[]
	*/
	ret = execve( "/usr/bin/ls", args, envp );
	if( ret == -1 )
	{
		printf( "execve() failed : %s\n", strerror( errno ) );
		return EXIT_FAILURE;
	}
	#endif
	
	#if EXECLE
	printf( "Output of execle()\n" );
	/*
		execle() - exec with arguments as list and environment list
		[1] Takes the absolute/relative pathname of a file as first argument
		[2] Second argument onwards the argument list starts
			arg0 - must be the name of the executable
			arg1 to argn-1 - are the user specified arguments for the executable
			argn should be a NULL pointer which is used to indicate the 
			end of the argument list.
		[3] Third argument is the environment list - envp[]
	*/
	ret = execle( "/usr/bin/ls", "ls", "-l", "-h", "-a", (char *)0, envp );
	if( ret == -1 )
	{
		printf( "execle() failed : %s\n", strerror( errno ) );
		return EXIT_FAILURE;
	}
	#endif
	
	#if EXECVPE
	printf( "Output of execvpe()\n" );
	/*
		execvp() - exec with arguments as vector/array along with environment list & evaluates PATH	
		[1] Takes the filename as first argument and searches the path entries in
			environment variable $PATH for the executable file specified
		[2] Second argument is the argument vector/array - args[]
		[3] Third argument is the environment list - envp[]
	*/
	ret = execvpe( "ls", args, envp );
	if( ret == -1 )
	{
		printf( "execvpe() failed : %s\n", strerror( errno ) );
		return EXIT_FAILURE;
	}
	#endif

	return EXIT_SUCCESS;
}
