/*
============================================================================
Name : Program 10
Author : Hari Prasad C
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
		a. check the return value of lseek
		b. open the file with od and check the empty spaces in between the data.
Date: 19th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	if ( argc < 2 ) {
		perror ("Please execute it appropriately.\n");
		return -1;
	}

	int fd = open ( argv[1], O_RDWR | O_CREAT, 0664);
	if ( fd == -1) {
		perror ("File opening error");
		return fd;
	}

	char var1[] = "Hello How are you?";
	char var2[] = "I am fine. How is your day?";

	if ( -1 == write ( fd, var1, sizeof(var1)) ) {
		perror ("File writing error");
		return -1;
	}

	off_t seek = lseek ( fd, 10, SEEK_END);
	printf("Return value of lseek : %ld\n", seek);


	if ( -1 == write ( fd, var2, sizeof(var2)) ) {
		perror ("File writing error");
		return -1;
	}

	int fd_close = close (fd);
	if ( -1 == fd ) {
		perror ("File closing error");
		return fd_close;
	}

	return 0;
}
