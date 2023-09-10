/*
============================================================================
Name : Program 14
Author : Hari Prasad C
Description : Write a program to find the type of a file.
		a. Input should be taken from command line.
		b. program should be able to identify any type of a file.
Date: 20th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc , char* argv[]) {
	if(argc!=2) {
    		printf("Execute appropriately.\n");
        	return 0;
    	}

	struct stat st;

        if( stat(argv[1],&st) == -1 ) {
            printf("No stat\n");
            return 0;
        }

	if(S_ISREG(st.st_mode))
        {
            printf("Regular File\n");
        }
        else if(S_ISDIR(st.st_mode))
        {
            printf("Directory File\n");
        }
        else if(S_ISBLK(st.st_mode))
        {
            printf("Block File\n");
        }
        else if(S_ISCHR(st.st_mode))
        {
            printf("Character File\n");
        }
        else if(S_ISLNK(st.st_mode))
        {
            printf("Symbolic Link\n");
        }
        else if(S_ISSOCK(st.st_mode))
        {
            printf("Socket File\n");
        }
        else if(S_ISFIFO(st.st_mode))
        {
            printf("Fifo File\n");
        }
        else
        {
            printf("Unknown File type\n");
        }
    return 0;
}
