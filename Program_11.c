#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX 100

int main(int argc, char* argv[]) {
	if ( argc != 2 ) {
		printf ("Execute the program in required format.");
		return -1;
	}

	int fd = open ( argv[1], O_RDWR | O_CREAT, 0664);
	if ( -1 == fd ) {
		perror ("File opening error");
		return fd;
	}

	printf ("Original file descriptor : %d\n",fd);

	// Appendening File with Original descriptor

	char var[MAX];
	memset ( var, '\0', MAX);
	strcpy( var,"\nAppending the file content using original File descriptor\n\n");

	if ( -1 == write ( fd, var, strlen(var)) ) {
		perror ("Error while appending file with original descriptor");
		return -1;
	}

	// Appending File with Duplicate descriptor created using dup
	
	int fd_dup = dup (fd);

	if ( -1 == fd_dup ) {
		perror ("Unable to dup file descriptor using dup system call");
		return -1;
	}

	printf ("File descriptor using dup : %d\n",fd_dup);
	
	memset ( var, '\0', strlen(var) );
	strcpy ( var,"Using dup system call appending the file content\n\n");

	if ( -1 == write ( fd_dup, var, strlen(var)) ) {
		perror ("Error while appending file with duplicate descriptor");
		return -1;
	}

	// Appending File with Duplicate descriptor created using dup2

	int fd_dup2 = dup2 (fd, 10);
	if ( -1 == fd_dup2 ) {
		perror ("Unable to dup file descriptor using dup2 system call");
		return -1;
	}

	printf ("File descriptor using dup2 : %d\n",fd_dup2);

	memset ( var, '\0', strlen(var) );
	strcpy ( var,"Using dup2 system call appending the file content\n\n");

	if ( -1 == write ( fd_dup2, var, strlen(var)) ) {
		perror ("Error while appending file with Duplicate descriptor");
		return -1;
	}
	
	// Appending File with Duplicate descriptor created using fcntl

	int fd_fcntl = fcntl (fd, F_DUPFD, 2);
	if ( -1 == fd_fcntl ) {
		perror ("Unable to dup file descriptor using fcntl system call");
		return -1;
	}

	printf ("File descriptor using fcntl : %d\n",fd_fcntl);

	memset ( var, '\0', strlen(var) );
	strcpy ( var,"Using fcntl system call appending the file content\n\n");

	if ( -1 == write ( fd_fcntl, var, strlen(var)) ) {
		perror ("Error while appending file with Duplicate descriptor");
		return -1;
	}
	
	return 0;
}
