#include<stdio.h>

#include<stdlib.h>

void insert(int sq[],int gq[],int *r,int *f,int *r1,int *f1)
{
	int v;
	
	if(*r!=9)
	{
		printf("Enter element:");
		scanf("%d",&v);
		
		if(v>60)
		{
			if(*r==-1&&*f==-1)
			{
				*r=0;
				*f=0; 
				sq[*r]=v;
			}
			else
			{
				*r=*r+1;
				sq[*r]=v;
			}
		}
		else
		{
			if(*r1==-1 &&  *f1==-1)
			{
				*r1=0;
				*f1=0;
				gq[*r1]=v;
			}
			else
			{
				*r1=*r1+1;
				gq[*r1]=v;
			}
		}
	}
}
void display(int sq[],int gq[],int *r,int *f,int *r1,int *f1)
{
	int i=0;
	 printf("\n\n");
	for(i=*f;i<=*r;i++)
	{
		printf(" %d ",sq[i]);
	}
	printf("\n");
	for(i=*f1;i<=*r1;i++)
	{
		printf(" %d ",gq[i]);
	}
}

void rem(int sq[],int gq[],int *r,int *f,int *r1,int *f1)
{
	if(*r!=-1)
	{ 
		if(*f==*r)
		{
			printf("Remove GQ %d value:",*f);
			printf("%d",sq[*f]);
		    *r=-1;
			*f=-1;
			
		}
		else
		{ 
			printf("Remove SQ %d value:",*f);
			printf("%d",sq[*f]);
			*f=*f+1;
			
		}
		
	}
	
	else
	{
		
		if(*r==-1)
		{
			if(*r1!=-1)
			{
				if(*f1==*r1)
				{
					printf("Remove GQ %d value:",*f1);
					printf("%d",gq[*f1]);
					*r1=-1;
					*f1=-1;
					
				}
				else
				{
					printf("Remove GQ %d value:",*f1);
					printf("%d",gq[*f1]);
				    *f1=*f1+1;
					
				}
				
			}
			else
			{
				printf("\ng-q is empty:");
			}
		}
	}
}
int simpleFind(int sq[],int gq[],int *r,int *r1,int serchEl)
{
  int i=0,t=0;
  if(serchEl>60)
  {
  for(i=0;i<=*r;i++)
  {
    if(sq[i]==serchEl)
    {
        t=i;
        break;
    }
  }
  }
  else
  {
    for(i=0;i<=*r1;i++)
  {
    if(gq[i]==serchEl)
    {
        t=i;
        break;
    }
   }  
  }
  if(i>*r||i>*r1)
  {
    return -1;
  }
  return t;
}
void modify(int sq[],int gq[],int *r,int *f,int *r1,int *f1)
{
  int ind,ne,pe;
   printf("\nEnter old value:");
   scanf("%d",&pe);
   printf("\nEnter new value:");
   scanf("%d",&ne);
   ind=simpleFind(sq,gq,r,r1,pe);
   if(ne>60&&pe>60)
   {
   if(ind!=-1)
   {
     sq[ind]=ne;
     printf("Change value %d  to %d",pe,ne);
   }
   else
   {
     printf("\nElement is not present in array");
   }
   }
   else if(ne<60&&pe<60)
   {
       if(ind!=-1)
   {
     gq[ind]=ne;
     printf("Change value %d  to %d",pe,ne);
   }
   else
   {
     printf("\nElement is not present in array");
   }   
   }
   else
   {
    printf("Plz,Enter valid value:");
   }

}


void main()
{
     int sq[10];
     int gq[10];
	int rr=-1,rr2=-1,ff=-1,ff2=-1,c;
	
	int *r=&rr,*r1=&rr2,*f=&ff,*f1=&ff2;
	
	while(1)
	{
		printf("\n1:insert:");
		printf("\n2:delete:");
		printf("\n3:modify:");
		printf("\nEnter value");
		scanf("%d",&c);
		
		switch(c)
		{
		case 1:insert(sq,gq,r,f,r1,f1);
			   display(sq,gq,r,f,r1,f1);
			   break;
		case 2:rem(sq,gq,r,f,r1,f1);
			   display(sq,gq,r,f,r1,f1);
			break;
		case 3:	modify(sq,gq,r,f,r1,f1);
			   display(sq,gq,r,f,r1,f1);
			break;
		case 4:exit(0);
		}
	}

	
}
