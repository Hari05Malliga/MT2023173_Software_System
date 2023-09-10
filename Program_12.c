/*
============================================================================
Name : Program 12
Author : Hari Prasad C
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 20th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void open_status ( int flag ) {

	if ( flag & O_WRONLY )	printf ("Write only mode.\n");
	else  if ( flag & O_RDWR )  printf ("Read and Write mode.\n");
	else  printf ("Read only mode.\n");

}

int main(int argc, char* argv[]) {
	if( argc !=2 ) {
		perror ("Enter the file to check its opened status");
		return -1;
	}
	
	int fd = open ( argv[1], O_WRONLY | O_CREAT, 0644 );
	if ( fd == -1 ) {
		perror ("File opening error");
		return -1;
	}

	printf ("File was opened in ");
	open_status ( fcntl( fd, F_GETFL ));

	close ( fd );

	return 0;
}
