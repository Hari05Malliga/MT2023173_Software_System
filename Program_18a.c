/*
============================================================================
Name : Program 18a
Author : Hari Prasad C
Description : Write a program to Create three records in a file.
Date: 25th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct employee {
	int emp_num;
	char name[20];
	int sal;
}emp;

int main ( int argc, char* argv[] ) {

	int fd = open ( "db", O_RDWR );
	if ( fd == -1 ) {
		perror ("File open error");
		return -1;
	}

	size_t temp = sizeof (struct employee);
	struct flock lock;
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();

	fcntl (fd, F_SETLKW, &lock);

	for ( int i=0 ; i<3 ; i++ ) {

		printf ("\nDetails of Employee Record : %d\n", i+1);

		printf ("Employee Number : ");
		scanf ("%d", &emp.emp_num);

		printf ("Employee Name : ");
		scanf ("%s", emp.name);

		printf ("Employee Salary : ");
		scanf ("%d", &emp.sal);

		size_t size = write (fd, &emp, temp);

		if ( size == -1 ) {
			perror ("File writing error");
			close ( fd );
			return -1;
		}
	}

	close ( fd );

	lock.l_type = F_UNLCK;
	fcntl (fd, F_SETLK, &lock);

	return 0;
}
