/*
============================================================================
Name : Program 17a
Author : Hari Prasad C
Description : Write a program to open a file, store a ticket number and exit.
Date: 17th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct ticket {
	int tic_num;
}t;

int main ( int argc, char* argv[] ) {
	if ( argc != 2 ) {
		perror ("Execute the program correctly");
		return -1;
	}

	int num;
	printf ("Enter the starting ticket number : ");
	scanf ("%d",&num);
	t.tic_num = num;

	int fd = open ( argv[1], O_CREAT | O_RDWR, 0666 );
	if ( fd == -1 ) {
		perror ("File open error");
		return -1;
	}

	size_t size = write (fd, (const struct ticket *) &t, sizeof(struct ticket));

	if ( size == -1 ) {
		perror ("File writing error");
		close ( fd );
		return -1;
	}

	close ( fd );
	printf("\n");
	return 0;
}
