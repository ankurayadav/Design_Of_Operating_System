//Algorithm :- iget

#include<stdio.h>
#include<stdlib.h>
struct inode
{
        int num;
        int ref;		//reference count
        struct inode *fr;
        struct inode *next;
}*q[4],*fl; 			//hash and free list

struct inode *check(int n)
{
        struct inode *temp;
        int i=n%4;		//hash function % 4
        temp=q[i];
        while(temp!=NULL)
        {
                if(temp->num==n)
                        return temp;
                temp=temp->next;
        }
        return temp;
}

void rem(int n)			//remove from free list
{
        struct inode *temp,*prev;
        temp=fl;
        if(temp->num==n)
        {
                fl=fl->fr;
                return;
        }
        while(temp->num!=n && temp->fr!=NULL)
        {
                prev=temp;
                temp=temp->fr;
        }
        prev->fr=temp->fr;
        temp->fr=NULL;
        return;
}
void remov(int n)
{
        struct inode *temp,*prev;
        temp=q[n%4];
        if(temp->num==n)
        {
                q[n%4]=q[n%4]->next;
                return;
        }
        while(temp->num!=n && temp->next!=NULL)
        {
                prev=temp;
                temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        return;
}
int iget(int n)
{
        struct inode *temp,*t;
        temp=check(n);
        if(temp!=NULL)
        {
                if(temp->ref==0)
                        rem(n);
                ++temp->ref;
                return 1;
        }
        if(fl==NULL)
                return -1;
        t=fl;
        fl=fl->fr;
        if(t->num)      
		remov(t->num);
        t->num=n;
        t->ref=1;
        t->fr=NULL;
        temp=q[n%4];
        if(temp==NULL)
        {       
		q[n%4]=t;
                return 1;
        }
        while(temp->next!=NULL)
                temp=temp->next;
        temp->next=t;
        return 1;
}

void insert(int n)
{
        struct inode *temp,*t;
        temp=fl;
        t=(struct inode *)malloc(sizeof(struct inode));
        t->num=n;
        t->next=NULL;
        t->ref=0;
        t->fr=NULL;

        if(temp==NULL)
        {
                fl=t;
                return;
        }
        while(temp->fr!=NULL)
                temp=temp->fr;
        temp->fr=t;
        return;
}


void print(struct inode *qu,int i)
{
        struct inode *temp;
        temp=qu;
        if(temp==NULL)  return;
        if(!i)
        {
                while(temp!=NULL)
                {
                        printf("%d,%d\t",temp->num,temp->ref);
                        temp=temp->next;
                }
        }
        else
        {
                while(temp!=NULL)
                {
                        printf("%d,%d\t",temp->num,temp->ref);
                        temp=temp->fr;
                }
        }
}



int main()
{
int i,ch,n;
fl=NULL;
for(i=0;i<=3;i++)
        q[i]=NULL;
for(i=1;i<=10;i++)
        insert(0);
do
{
        printf("Inode - iget \n");
        printf("1. Allocate inode.\n");
        printf("2. Release inode.\n");
        printf("3. Display hash queues.\n");
        printf("0.Exit.\n");
        printf("Please enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1: printf("Please enter the inode number:\n");
                        scanf("%d",&n);
                        if(iget(n)==-1)
                                printf("No inode available.\n");
                        else
                                printf("Iget successful.\n");
                        break;
                case 2: printf("Please enter the inode number:\n");
                        scanf("%d",&n);
                        remov(n);
                        insert(0);
                	
               		break;
                case 3: for(i=0;i<4;i++)
                        {
                                printf("\n");
                                printf("Queue %d:\t",i);
                                print(q[i],0);
                        }
                        printf("\n");
                        printf("Free list:\t");
                        print(fl,1);
                        printf("\n");
                        break;
                case 0:
                        exit(1);
                default:
                        continue;

        }       printf("\n");
}while(ch>=1 && ch<=3);

                      return 0;
}


                                                      
