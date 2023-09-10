/*
============================================================================
Name : Program 8
Author : Hari Prasad C
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
	      Close the file when end of file is reached.
Date: 18th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1000

int main(int argc, char* argv[]) {
	if ( argc < 2 ) {
	       printf("Please pass the file to print.\n");
	       return 0;
	}

	for ( int j=1 ; j <= argc-1 ; j++ ) {

		int fd = open ( argv[j], O_RDONLY), i = 0;

		if ( -1 == fd ) {
			perror ("Unable to open file");
			continue;
		}
	
		char buffer[MAX], var;
		memset ( buffer, '\0', sizeof(buffer) );
	
		while ( read ( fd, &var, 1) ) {
			if ( var != '\n' && i < MAX) buffer[i++] = var;
			else {
				buffer[i] = '\n';
				write ( fileno(stdout), buffer, i+1 );
				i = 0;
				memset ( buffer, '\0', sizeof(buffer) );
			}
		}
		close(fd);
	}

	return 0;
}

