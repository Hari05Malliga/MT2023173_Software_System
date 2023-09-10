/*
============================================================================
Name : Program 17
Author : Hari Prasad C
Description : Write a program, to open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 25th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

struct ticket_tracker {
	int tic_num;
}ticket;

int main ( int argc, char* argv[] ) {
	struct flock lock;

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	printf ("Attempting Write lock...\n");

	int fd = open ( "db", O_RDWR );
	if ( fd == -1 ) {
		perror ("File opening error");
		return -1;
	}

	fcntl ( fd, F_SETLKW, &lock );
	printf("Acquired lock...\n");

	size_t size = read(fd, (struct ticket_tracker *) &ticket, sizeof(ticket));
	if ( 0 == size ) {
		perror ("File read error");
		close ( fd );
		return -1;
	}

	printf ("Updated ticket number : %d\n", ++ticket.tic_num);
 	lseek ( fd, 0L, SEEK_SET );

	size = write (fd,  (const struct ticket_tracker *) &ticket, sizeof(ticket));
	if ( 0 == size ) {
		perror ("File write error");
		close ( fd );
		return -1;
	}
	getchar();
	close (fd);
	
	lock.l_type = F_UNLCK;
	fcntl ( fd, F_SETLK, &lock );

	printf("Lock released...\n");
	return 0;
}

