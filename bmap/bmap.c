#include<stdio.h>

void main()
{	long int byte, add, directb, sindirect=0, dindirect=0, tindirect=0;
	printf("Enter the byte offset address :");
	scanf("%ld", &add);
	if(add<10240)
	{
		directb=add/1024;
		byte = add%1024;
	}
	else if(add<272384)
	{
		add=add-10240;
		directb=add/1024;
		byte = add%1024;
	}
	else if(add<67381248)
	{
		add=add-272384;
		sindirect = add/262144;
		add=add%262144 ;
		directb=add/1024;
		byte = add%1024;		
	}
	else
	{
		add=add-67381248;
		dindirect = add/67108864;
		add=add%67108864;
		sindirect = add/262144;
		add=add%262144 ;
		directb=add/1024;
		byte = add%1024;
		
	}
	
	printf("triple indirect:%ld\ndouble indirect:%ld\nsingle indirect:%ld\ndirect:%ld\ndata offset:%ld\n",tindirect,dindirect,sindirect,directb,byte);
}