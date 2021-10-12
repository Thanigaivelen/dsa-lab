#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int val;
    struct queue *next;
    struct queue *prev;
};
struct queue *head=NULL;
struct queue *last=NULL;

void insertbeg(int value)
{
    struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode->prev=NULL;
    newnode->val=value;
    if(head==NULL)
    {
        head=newnode;
        last=newnode;
        head->next=NULL;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    if(last==NULL)
        last=head;
}
void insertlast(int value)
{
    struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode->val=value;
    newnode->next=NULL;
    if(head==NULL)
    {
          newnode->prev=NULL;
          last=newnode;
          head=last;
          return;
    }
    newnode->prev=last;
    last->next=newnode;
    last=newnode;

}
void deletebeg()
{
    if(head==NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct queue* newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode=head;
    head=newnode->next;
    free(newnode);
    head->prev=NULL;
    if(head==NULL)
        last=NULL;
}
void deletelast()
{
    if(head==NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct queue* newnode=(struct queue*)malloc(sizeof(struct queue));
    struct queue* prev=(struct queue*)malloc(sizeof(struct queue));
    newnode=head;
    while(newnode->next!=NULL)
    {
        prev=newnode;
        newnode=newnode->next;
    }
    last=prev;
    last->next=NULL;
    free(newnode);
    if(last==NULL)
        head=NULL;

}
void search(int value)
{
    struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode=head;
    int i=1,flag=0;
    while(newnode!=NULL)
    {
        if(newnode->val==value)
        {
             printf("\n%d is found in %d position\n",newnode->val,i);
             flag=1;
        }
        i++;
        newnode=newnode->next;
    }
    if(flag==0)
    {
        printf("Element not found in queue");
    }
}
void print()
{
    if(head==NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct queue* newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode=head;
    while(newnode!=NULL)
    {
        printf(" %d ",newnode->val);
        newnode=newnode->next;
    }
}  
int main()
{
    int choice;
    int s,insert;
do
{
    printf("\n\t\tMenu\n1.Insert at front\t\t\t2.Insert at rear\n3.Delete at front\t\t\t4.Delete at rear\n5.Search\t\t\t6.Display\n7.Exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter number :");
        scanf("%d",&insert);
        insertbeg(insert);
        break;
    case 2:
        printf("Enter number :");
        scanf("%d",&insert);
        insertlast(insert);
        break;
    case 3:
        deletebeg();
        break;
    case 4:
        deletelast();
        break;
    case 5:
        printf("Enter search element: ");
        scanf("%d",&s);
        search(s);
        break;
    case 6:
        print();
        break;
    case 7:
        break;
    default:
        printf("Wrong input. Try again");
    }
}while(choice!=7);
return 0;
}
