#include<stdio.h>
#define N 2048
void main()
{	long int byte, add, directb, sindirect=0, dindirect=0, tindirect=0;
	printf("Enter the byte offset address :");
	scanf("%ld", &add);
	
	
	if(add<(N*10))
	{
		directb=add/N;
		byte = add%N;
	}
	else if(add<(256*N+N*10))
	{
		add=add-(N*10);
		directb=add/N;
		byte = add%N;
	}
	else if(add<(256*256*N+256*N+N*10))
	{
		add=add-(256*N+N*10);
		sindirect = add/(256*N);
		add=add%(256*N) ;
		directb=add/N;
		byte = add%N;		
	}
	else
	{
		add=add-(256*256*N+256*N+N*10);
		dindirect = add/(256*256*N);
		add=add%(256*256*N);
		sindirect = add/(256*N);
		add=add%(256*N) ;
		directb=add/N;
		byte = add%N;
		
	}
	
	printf("triple indirect:%ld\ndouble indirect:%ld\nsingle indirect:%ld\ndirect:%ld\ndata offset:%ld\n",tindirect,dindirect,sindirect,directb,byte);
}
