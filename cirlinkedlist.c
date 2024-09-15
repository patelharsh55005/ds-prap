#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


struct node* insert(struct node *head,int ele)
{
	struct node *n,*prev,*curr;

	n=(struct node*)malloc(sizeof(struct node));

    n->data=ele;
	prev=NULL;
	curr=head;
     
	if(head==NULL)
	{
	   
		n->next=n;
		head=n;

	}
    else if(head->data>ele)
    {
        n->next=head;
        do
        {
            curr=curr->next;
        } while (curr->next!=head);
        curr->next=n;
        head=n;
    }
	else
	{
		 do
        {
            prev=curr;
            curr=curr->next;
             if (curr == head || ele < curr->data) {
              break;
        }
        }while (curr!=head);
        prev->next=n;
		n->next=curr;

       
	}
     if (curr == head && ele<head->data) {
           head = n;
         }

  return head;
}

struct node* del(struct node *head,int ele)
{
	struct node *prev,*curr;

	prev=NULL;
	curr=head;

	if(head==NULL)
	{
		printf("\n Link list is empty");
	}
	else
	{
	   while(curr!=NULL && ele!=curr->data)
	   {
		   prev=curr;
		   curr=curr->next;
	   }
	   if(head==curr)
	   {
		   head=curr->next;
		   free(curr);
	   }
	   else
	   {
		   prev->next=curr->next;
		   free(curr);
	   }
	 
	}
	return head;
}

int modify(struct node *head,int old,int newEl)
{
    struct node *curr;
    int i;
    curr=head;
   while( old!=curr->data)
   {
      curr=curr->next;
   }
   if(curr->data==old)
   {
    curr->data=newEl;
     i=1; 
   }
   else
   {
   i=0;
   }
   return i;
}
void display(struct node *head)
{
	struct node *temp;
	temp=head;
    do
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }while (temp!=head);

}
void main()
{
	struct node *head=NULL;
	int data,c,newEl,old;

	while(1)
	{
		printf("\n 1:insert");
		printf("\n 2:Delete");
		printf("\n 3:modify");
        printf("\n 4:display");
        printf("\n 5:exit");
		printf("\n Enter your chioce");
		scanf("%d",&c);
		switch(c)
		{
		case 1:printf("\n Enter element :");
			   scanf("%d",&data);
			   head=insert(head,data);
			   display(head);
			   break;
		case 2:printf("\n Enter element for delete:");
			   scanf("%d",&data);
			   head=del(head,data);
			   display(head);
			   break;
		case 3:printf("\n Enter old element:");
			   scanf("%d",&old);
               printf("\n Enter new element:");
			   scanf("%d",&newEl);
			   if(modify(head,old,newEl))
               {
                  printf("%d is replace by %d ",old,newEl);
               }
               else
               {
                printf("Value is not available:");
               }
               printf("\n");
			   display(head);
			   break;
        case 4:display(head);
               break;
        case 5:exit(0);
		}
	}
  
}
