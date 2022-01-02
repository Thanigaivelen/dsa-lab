#include <stdio.h>
#include<stdlib.h>
struct hash
{
  int data,key;
  struct hash *next;
};
int size;
struct hash *tab[10]; 
void init()
{
  for(int i=0;i<size;i++)
    tab[i]=NULL;

}
int i;

int insert(int value)
{
  struct hash *newnode=(struct hash *)malloc(sizeof(struct hash));
  newnode->data=value;
  newnode->next=NULL;
  int key=value%size;
  if(tab[key]==NULL)
  {
    tab[key]=newnode;
  }
  else
  {
    struct hash *temp=(struct hash *)malloc(sizeof(struct hash));
    temp=tab[key];
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=newnode;
  }
  return 0;

}

void display()
{
   struct hash *temp=(struct hash *)malloc(sizeof(struct hash));
   for(i=0;i<size;i++)
   {
     temp=tab[i];
     printf("Chain[%d]",i);
     while(temp)
     {
       printf("-->%d",temp->data);
       temp=temp->next;
     }
     printf("\n");
   }
}

int main()
{
  init();
  int n,choice;
  printf("enter size : ");
  scanf("%d",&size);
  printf("enter values :");
  for(i=0;i<size;i++)
    {
      scanf("%d",&n);
      insert(n);
    }
  display();

  while(1)
  {
    printf("Enter the operarion");
    printf("\n1.Insertion\n2.Display\n3.Exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
      {
        printf("Enter the element\n");
        scanf("%d",&n);
        insert(n);
      }
      case 2:
      {
        display();
        break;
      }
      case 3:
      {
        printf("quit the program");
        exit(0);
      }
    }
  }
}
