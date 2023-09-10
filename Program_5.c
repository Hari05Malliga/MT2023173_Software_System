/*
============================================================================
Name : Program 5
Author : Hari Prasad C
Description : Write a program to create five new files with infinite loop. Execute the program in the background
	      and check the file descriptor table at /proc/pid/fd.
Date: 18th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd1 = open ( "file1", O_CREAT, 0744);
	int fd2 = open ( "file2", O_CREAT, 0744);
	int fd3 = open ( "file3", O_CREAT, 0744);
	int fd4 = open ( "file4", O_CREAT, 0744);
	int fd5 = open ( "file5", O_CREAT, 0744);

	while(1);
}
