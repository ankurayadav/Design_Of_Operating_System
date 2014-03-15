#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include <time.h> 
void main(int argc, char *argv[])
{	char *ctime();
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

	printf("File %s status :\n\n", argv[1]);
	printf("1) Device number :%d\n", stat_buf.st_dev);
	printf("2) I-Node :%d\n", stat_buf.st_ino);
	printf("3) Links :%d\n", stat_buf.st_nlink);
	printf("4) Size :%ld\n", stat_buf.st_size);
	printf("5) Access Time :%s", ctime (&stat_buf.st_atime));
	printf("6) Mode :%d\n", stat_buf.st_mode);
	printf("7) Owner uid :%d\n",stat_buf.st_uid);
	printf("8) Group id :%d\n",stat_buf.st_gid);
	printf("9) Modification Time :%d\n",stat_buf.st_mtime);

}
