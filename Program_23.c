/*
============================================================================
Name : Program 23
Author : Hari Prasad C
Description : Write a program to create a Zombie state of the running program.
Date: 5th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
	if ( fork() ) {
		sleep (60); // use command ps aux | grep Z+ to check the process status
	} else {
		printf ("Child completed execution.\n");
	}
	return 0;
}
