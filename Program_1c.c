/*
============================================================================
Name : Program 1c
Author : Hari Prasad C
Description : Write a program, Create a FIFO  using system call mknod.
Date: 17th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#define MAX 100

int main() {
	int pipe, pid;

	if ( access("namedFifo", F_OK) ) mkfifo ("namedFifo", 0744);

	pipe = open ( "namedFifo", O_RDWR);

	if (!( pid = fork() )) {
		char message[MAX];
		memset(message,'\0',sizeof(message));
		
		printf ("Child Process\nEnter the Message : ");
		scanf ("%99[^\n]", message);

		write ( pipe, message, strlen(message) + 1 );
	}
	else {	
		wait( &pid );

		char buffer[MAX];
		memset(buffer,'\0',sizeof(buffer));

		int size = read ( pipe, buffer, sizeof(buffer) );

		if ( size > 0 )	printf ("Parent Process\nRecieved Message : %s\n", buffer);
	}

	close(pipe);
	return 0;
}
