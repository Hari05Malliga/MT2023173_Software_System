/*
============================================================================
Name : Program 3
Author : Hari Prasad C
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 19th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = creat ( "new_file", 0544);
	if ( fd == -1 ) {
		perror ("File Creation failed...");
		return fd;
	}
	printf ("File Descriptor value : %d\n", fd);
	close(fd);
	return 0;
}
