/*
============================================================================
Name : Program 21
Author : Hari Prasad C
Description : Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
	if ( !fork() ) 
		printf ("Child Process Id : %d\n", getpid() );
	else 
		printf ("Parent Process Id : %d\n", getpid() );
	return 0;
}
