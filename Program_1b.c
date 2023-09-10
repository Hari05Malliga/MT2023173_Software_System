/*
============================================================================
Name : Program 1b
Author : Hari Prasad C
Description : Write a program, Create a hard link using system call link.
Date: 17th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
	int hard_link,fd;

	fd = open("temp1", O_CREAT | O_RDWR, 0744);
       	if ( fd == -1 ) {
		printf ("File not Created...\n");
		return fd;
	}

        hard_link = link("temp1","temp2");
        if ( hard_link == -1 ) {
	       	printf ("Softlink Creation failed...\n");
		return hard_link;
	}

	return 0;
}
