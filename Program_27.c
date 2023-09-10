/*
============================================================================
Name : Program 27 
Author : Hari Prasad C
Description : Write a program to execute ls -Rl by the following system calls 1) execl 2) execlp 3) execle 4) execv 5) execvp
Date: 6th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int choice;

	printf ("Please select an option below : \n");
	printf ("1) execl\n2) execlp\n3) execle\n4) execv\n5) execvp\n");
	printf ("Enter your choice : ");
	scanf ("%d", &choice);

	switch ( choice ) {
		case 1 : if ( -1 == execl ("/bin/ls", "ls", "-Rl", NULL)) {
				perror ("execl failed");
				return -1;
			 } 
			 break;
		case 2 : if ( -1 == execlp ("/bin/ls", "ls", "-Rl", NULL)) {
				 perror ("execlp failed");
				 return -1;
			 }
			 break; 
		case 3 : char *envp[] = {NULL};
			 if ( -1 == execle ("/bin/ls", "ls", "-Rl", NULL, envp)) {
				 perror ("execle failed");
				 return -1;
			 }
			 break;
		case 4 : char *args1[] = {"ls", "-Rl", NULL};
			 if ( -1 == execv ("/bin/ls", args1)) {
				 perror ("execv failed");
				 return -1;
			 }
			 break;
		case 5 : char *args2[] = {"ls", "-Rl", NULL};
			 if ( -1 == execvp ("/bin/ls", args2)) {
				 perror ("execvp failed");
				 return -1;
			 } 
			 break;
		default : printf ("Please select appropriate choice.\n");
	}
	return 0;
}
