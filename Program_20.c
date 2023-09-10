/*
============================================================================
Name : Program 20 
Author : Hari Prasad C
Description : Write a C, Ansi-style program to find out the priority of your running program. Modify the priority with nice command.
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main () {
	int priority = getpriority ( PRIO_PROCESS, getpid() );

	printf ("Intial Priority of the process : %d\n", priority );
/*
	int value;
	printf ("Enter the value by which you want to update Priority : ");
	scanf ("%d", &value);

	int status = nice ( value );
	if ( status == -1 ) {
		perror ("Error while changing priority");
		return -1;
	}

        priority = getpriority ( PRIO_PROCESS, 0 );

	printf ("\nUpdated Priority of the process : %d\n", priority );
*/
	while (1);	

	return 0;
}
