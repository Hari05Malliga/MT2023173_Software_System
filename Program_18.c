/*
============================================================================
Name : Program 18
Author : Hari Prasad C
Description : Write a program to perform Record locking.
		a. Implement write lock
		b. Implement read lock
	      Whenever you access a particular record, first lock it then modify/access to avoid race condition.
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

struct employee {
	int emp_num;
	char name[20];
	int sal;
}emp_record;

void acquire_lock (int fd, struct flock lock) {
	printf ("Attempting Record lock...\n");
	fcntl ( fd, F_SETLKW, &lock );
	printf("Acquired lock...\n");
}

void release_lock (int fd, struct flock lock) {
	lock.l_type = F_UNLCK;
	fcntl ( fd, F_SETLK, &lock );
	printf ("\nLock Released...\n");
}

void read_record( int fd, struct employee * emp, size_t size ) {
	size_t var = read ( fd, emp, size );
	if ( -1 == var ) {
		perror ("File read error");
		close ( fd );
		exit(0);
	}
}

void write_record( int fd, struct employee * emp, size_t size ) {
	
	printf ("\nEnter the field you want to modify : ");
	printf ("\n1)Employee Number\n2)Employee Name\n3)Employee Salary\n");
	printf ("Enter the choice : ");
	int choice;
	scanf ("%d", &choice);

	read_record ( fd, emp, size);
	lseek ( fd, -size, SEEK_CUR );

	switch (choice) {
		case 1 : printf ("Employee Number : ");
			 scanf ("%d", &emp->emp_num ); 
			 break;
		case 2 : printf ("Employee Name : ");
			 scanf ("%s", emp->name );
			 break;
		case 3 : printf ("Employee Salary : ");
			 scanf ("%d", &emp->sal );
			 break;
		default : printf ("Please select appropriate option.\n");
	}

	size_t var = write ( fd, emp, size );
	if ( -1 == var ) {
		perror ("File write error");
		close ( fd );
		exit(0);
	}
	printf ("Record Updated Successfully.\n");
}

int main ( int argc, char* argv[] ) {

	struct flock lock;

	lock.l_len  = sizeof(struct employee);
	lock.l_pid  = getpid();


	int fd = open ( "db", O_RDWR | O_CREAT, 0666);
	if ( fd == -1 ) {
		perror ("File opening error");
		return -1;
	}

	while (1) {
		printf ("1) Read Employee Record.\n2) Update Employee Record.\n3) Exit.\n");
		printf ("Enter your choice : ");
		int choice;
		scanf ("%d", &choice);

		if ( choice == 3 ) break;
		lock.l_type = (choice == 1) ? F_RDLCK : F_WRLCK;

		int record_num;
		if ( choice == 2 ) {
			printf ("Enter the Record Number to modify [1-3] : ");
			scanf("%d", &record_num);
			if ( record_num <0 || record_num>3 ) {
				printf ("Invalid Record Number.\n");
				break;
			}

			lock.l_whence = SEEK_SET;
			lock.l_start  = sizeof(struct employee) * (record_num-1) ;
			lseek ( fd, lock.l_start, SEEK_SET );

			acquire_lock ( fd, lock );
			write_record ( fd, &emp_record, sizeof(emp_record));

			getchar();
			release_lock ( fd, lock );
		}
		else { 
			printf ("Enter the Record Number to be read [1-3] : ");
			scanf ("%d", &record_num);
			if ( record_num <0 || record_num>3 ) {
				printf ("Invalid Record Number.\n");
				break;
			}

			lock.l_whence = SEEK_SET;
			lock.l_start  = sizeof(struct employee) * (record_num-1) ;
			lseek ( fd, lock.l_start, SEEK_SET );

			acquire_lock ( fd, lock );
			read_record (fd, &emp_record, sizeof(emp_record));

			printf ("\nEmployee Number : %d", emp_record.emp_num );
			printf ("\nEmployee Name : %s", emp_record.name );
			printf ("\nEmployee Salary : %d\n", emp_record.sal );

			getchar(); getchar();
			release_lock ( fd, lock );
		}
	}

	close (fd);
	
	return 0;
}

