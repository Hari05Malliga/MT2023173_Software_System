/*
============================================================================
Name : Program 13
Author : Hari Prasad C
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
	      verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 17th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>

int main() {
	fd_set fd;
	FD_ZERO(&fd);

	FD_SET(fileno(stdin), &fd);

	struct timeval target_time;

	target_time.tv_sec = 10;
	target_time.tv_usec = 0;

	int val = select (fileno(stdin)+1, &fd, NULL, NULL, &target_time );
	if ( !val ) printf ("Waiting time expired...\n");
	else {
		printf ("Input available before time lapse...\n");
		char buff[100];
		scanf("%99[^\n]s", buff);
		printf ("Read contents are : \n%s\n", buff);
	}

	return 0;
}
