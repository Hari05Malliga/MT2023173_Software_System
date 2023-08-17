#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
	int i,fd;

	fd = open("temp1", O_CREAT | O_RDWR, 0744);

       	if ( fd == -1 ) printf("File not Created");

        i = symlink("temp1","temp2");
	return 0;
}
