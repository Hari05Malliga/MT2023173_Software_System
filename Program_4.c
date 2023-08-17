#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open ( "new_file", O_RDWR, 0744);
	if ( fd == -1 ) {
		perror ( "File opening failed");
		return fd;
	}
	printf("File opened successfully...\n");
	close(fd);

	return 0;
}
