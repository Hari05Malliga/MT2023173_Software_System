/*
============================================================================
Name : Program 22
Author : Hari Prasad C
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes.
	      Check output of the file.
Date: 5th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd = open ("Sample.txt",O_CREAT | O_RDWR, 0644 );
	if ( fd == -1 ) {
		perror ("File opening error.");
		return -1;
	}
	
	if ( fork() ) {
		char str[] = "Parent writing in file.";

		size_t size = write (fd, &str, strlen(str));
		if ( -1 == size ) {
			perror ("File write error");
			return -1;
		}
	} else {
		char str[] = "Child writing in file.";

		size_t size = write (fd, &str, strlen(str));
		if ( -1 == size ) {
			perror ("File write error");
			return -1;
		}

	}

	return 0;
}

