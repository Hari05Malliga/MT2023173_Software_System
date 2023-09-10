/*
============================================================================
Name : Program 25
Author : Hari Prasad C
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date: 6th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int pid1, pid2, pid3;
	if ( pid1 = fork() ) {
		// Parent
		printf ("Parent Process ID : %d\n", getpid());
		if ( pid2 = fork() ) {
			// Parent
			if ( pid3 = fork() ) {
				// Parent
				printf ("1. Child Process ID-1 : %d\n", pid1);
				printf ("2. Child Process ID-2 : %d\n", pid2);
				printf ("3. Child Process ID-3 : %d\n", pid3);
				
				int id;
				printf ("Enter your choice : ");
				scanf ("%d", &id);
				switch ( id ) {
					case 1 :  id = pid1; break;
					case 2 :  id = pid2; break;
					case 3 :  id = pid3; break;
					default : printf ("Please select appropriate option...\n"); exit(0);
				}
				waitpid(id, NULL, 0);
				printf ("Parent Process starting execution...\n");
			} else {
				// Child 3
				sleep(20);
				printf ("Child-3 Completed execution...\n");
			}
		} else {
			// Child 2
			sleep(30);
			printf ("Child-2 Completed execution...\n");
		}
	} else {
		// child 1 
		sleep(40);
		printf ("Child-1 Completed execution...\n");
	}
	return 0;
}
