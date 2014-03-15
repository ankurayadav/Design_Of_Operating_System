#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

void main(int argc, char *argv[])
{	
	int isdevice = 0;
	struct stat stat_buf;
	if(argc!=2)
	{
		printf("Improper input :(\n");
		exit(1);
	}
	if((stat(argv[1], &stat_buf))==-1)
	{
		printf("Stat erro :(\n");
		exit(1);
	}
	
	printf("File: %s status :\n\n", argv[1]);
	if((stat_buf.st_mode & S_IFMT)==S_IFBLK)
		printf("Directory\n");
	else if((stat_buf.st_mode & S_IFMT)==S_IFBLK)
	{
		printf("Block specical file\n");
		isdevice = 1;
	}
	else if((stat_buf.st_mode & S_IFMT)==S_IFCHR)
	{
		printf("Character special file\n");
		isdevice = 1;
	}
	else if((stat_buf.st_mode & S_IFMT)==S_IFREG)
	{
		printf("Ordinary file\n");
	}
	else if((stat_buf.st_mode & S_IFMT)==S_IFIFO)
	{
		printf("FIFO\n");
	}
	

	 printf("Resides on device:%d, %d\n", (stat_buf.st_dev > 8) & 0377, stat_buf.st_dev & 0377);
	 printf("I-node: %d; Links: %d; Size: %ld\n", stat_buf.st_ino, stat_buf.st_nlink, stat_buf.st_size);
}
