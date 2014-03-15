#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/stat.h>
void main(int argc, char *argv[])
{
	if(argc!=3)
	{ printf("Invalid Command\n");
	  exit(1);
	}
	printf("Reversing contents of %s in %s ...\n",argv[1],argv[2]);
	int fr, fw;
	fr=open(argv[1],O_RDONLY);
	fw=creat(argv[2],S_IREAD |S_IWRITE);
	 if (fr == -1)
	{
		printf("Cannot open %s\n", argv[1]);
		exit(1);
	}
	
	int position = lseek(fr, 0L, 2);
	int i,count=0;  
	lseek(fr, 0L, 0); 
	char *buffer = (char*)malloc(position*sizeof(char)); 
	char *rbuff = (char*)malloc(position*sizeof(char));
	read(fr, buffer, position);
	for(i=position-2; i>=0; i--)
	{
		rbuff[count++]=buffer[i];
		printf("%c",buffer[i]);
	}
	rbuff[count]='\0';
	//printf("\n%s\n\n",buffer);
	write(fw, rbuff, position-1);
	close(fr);
	close(fw);
}
