#include<stdio.h>
#include<dirent.h>
#include<string.h>

void directory_reader(DIR *f){
	struct dirent *d;
	DIR *sf;
	int i=0;
	static int fg=0;
	for(;;)
	{
		d=readdir(f);
		if(d==NULL)
		{
			break;
		}
		for(i=0; i<=fg; i++)
		{
			printf("\t");
		}
		
		printf("%s\n",d->d_name);
		
		sf= opendir(d->d_name);
		
		if(sf!=NULL && strcmp(d->d_name,".")!=0 && strcmp(d->d_name,"..")!=0)
		{
			chdir(d->d_name);
			fg++;
			directory_reader(sf);
		}
		
	}

chdir("..");
fg--;
}

int main(int argc, char *argv[]) {
	DIR *f;
	f=opendir(argv[1]);
	chdir(argv[1]);
	directory_reader(f);
	closedir(f);
	return 0;
}
