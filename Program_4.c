/*
============================================================================
Name : Program 4
Author : Hari Prasad C
Description : Write a program open an existing file with read write mode. Try O_EXCL flag also.
Date: 18th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
	int fd = open ("new_file", O_RDWR);

	if ( fd == -1 )	perror ( "File opening failed");
	else printf ("File opened successfully...\n");

	int fd1 = open ("new_file", O_CREAT | O_EXCL, 0644);

	if ( fd1 == -1 ) {
		if ( errno == EEXIST ) printf("File already exists.\n");
		else perror ("File creation error");
	}
	else printf("File opened successfully...\n");

	close(fd);

	return 0;
}
