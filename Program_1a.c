#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int link,fd;

	fd = open("temp1", O_CREAT | O_RDWR, 0744);
       	if ( fd == -1 ) {
		printf ("File not Created...\n");
		return fd;
	}

        link = symlink("temp1","temp2");
        if ( link == -1 ) {
	       	printf ("Softlink Creation failed...\n");
		return link;
	}

	return 0;
}
