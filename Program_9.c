#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	struct stat s;
	int temp;
	if ( temp = stat ("/home/hari/Desktop/Linux_Tutorial/temp1", &s) ) {
		perror ("Unable to fetch file detail");
		return temp;
	}

	printf ("Inode of the file : %ld\n", s.st_ino);
	printf ("Number of hard links : %ld\n", s.st_nlink);
	printf ("User ID of owner : %d\n", s.st_uid);
	printf ("Group ID of owner : %d\n", s.st_gid);
	printf ("Total size, in bytes : %ld\n", s.st_size);
	printf ("Block size for filesystem I/O : %ld\n", s.st_blksize);
	printf ("Number of 512B blocks allocated : %ld\n", s.st_blocks);

	printf ("Time of last access : %ld\n", s.st_atim.tv_nsec);
	printf ("Time of last modification : %ld\n", s.st_mtim.tv_nsec);
	printf ("Time of last status change : %ld\n", s.st_ctim.tv_nsec);

	return 0;
}
