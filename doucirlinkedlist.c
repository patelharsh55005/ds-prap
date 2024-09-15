#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node
{

    int id;
    char name[10];
    struct node *pre;
    struct node *next;
};

struct node* insert(struct node *head,int id,char nm[])
{
    struct node *n,*prev,*curr;

   n=(struct node*)malloc(sizeof(struct node)) ;
   n->id=id;
   strcpy(n->name,nm);
  

   
    if(head==NULL)
    {
      
        n->pre=n;
        n->next=n;
        head=n;
        return head;
    }
   curr=head;
   prev=NULL;
        do
        {
              prev=curr;
              curr=curr->next;
             if (curr == head || id < curr->id) {
              break;
             }
        }while (curr!=head);
            
            n->next=curr;
            n->pre=prev;
            prev->next=n;
            curr->pre=n;
   if (curr == head && id<head->id) {
        head = n;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;

    do
    {
        printf(" %d ",temp->id);
        printf(" %s ",temp->name);
        temp=temp->next;
    }while (temp!=head);

}



void main()
{
    struct node *head=NULL;

    int ele,c;
    char ch[10];

    while(1)
    {
        printf("\n1:insert");
        printf("\n2:delete");
        printf("\n3:display");
        printf("\n4:exit");
        printf("\nEnter your choice:");
        scanf("%d",&c);

        switch (c)
        {
        case 1:printf("\nEnter id:");
               scanf("%d",&ele);
               printf("\nEnter name:");
               scanf("%s",ch);
               head=insert(head,ele,ch);
               break;
        case 2:break;

        case 3:display(head);
               break;
        default:
            break;
        }
        
    }

}
