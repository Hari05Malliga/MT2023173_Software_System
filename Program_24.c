/*
============================================================================
Name : Program 24
Author : Hari Prasad C
Description : Write a program to create an orphan process.
Date: 5th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int main() {
	if ( !fork() ) {
		sleep(10);
		printf ("Child Process ID : %d\n", getpid());
		printf ("Parent Process ID after Parent exited : %d\n", getppid());
		while(1);
	} else {
		printf ("Parent Process ID : %d\n", getpid());
		exit(0);
	}
	return 0;
}
