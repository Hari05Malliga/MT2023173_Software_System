/*
============================================================================
Name : Program 6
Author : Hari Prasad C
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 17th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

int main() {
	size_t var;
	char buffer[MAX];

	var = read (fileno(stdin), buffer, sizeof(buffer));
	if ( -1 == var ) {
		perror ("Read error");
		return -1;
	}

        write(fileno(stdout), buffer, var);
	return 0;
}
