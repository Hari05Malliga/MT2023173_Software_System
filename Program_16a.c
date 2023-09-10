/*
============================================================================
Name : Program 16a
Author : Hari Prasad C
Description : Write a program to perform mandatory locking. Implement write lock.
Date: 25th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ( int argc, char* argv[] ) {
	if ( argc != 2 ) {
		perror ("Execute the program correctly");
		return -1;
	}

	int fd = open ( argv[1], O_CREAT | O_RDWR, 0644 );

	struct flock lock;

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	printf ("Attempting Write lock...\n");
	fcntl ( fd, F_SETLKW, &lock );

	printf("Acquired lock...\n");
	getchar();
	
	lock.l_type = F_UNLCK;
	fcntl ( fd, F_SETLK, &lock );

	printf("Lock released...\n");
	close ( fd );

	return 0;
}

