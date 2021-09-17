#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node *next;
};
struct node *front = 0;
struct node *rear =0;
int x;

void enq(int x){
  
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  if (front==0&&rear==0){
    front = newnode;
    rear= newnode;
    newnode->data=x;
    rear->next=0;
  }
  else{
      rear->next =newnode;
      newnode->data=x;
      rear=newnode;
      rear->next=0;
      
  }
}

void deq(){
  if (front==0&&rear==0){
    printf("\nqueue is empty");
  }
  else{
  	struct node *temp;
  	temp= front;
  	front= front->next;
  	free(temp);
  }
  printf("\ndequeue is success");
}
void display(){
  struct node*temp;
  temp=front;
  if(front==0&&rear==0){
    printf("\nqueue is empty");
  }
  else{
    while(temp!=0){
      printf("\n%d",temp->data);
      temp=temp->next;
    }
  }
}

int main() {
    enq(588);
    enq(250);
    enq(55);
    enq(68);
    enq(99);
    display();
    deq();
    display();
    printf("\nHello World\n");
    return 0;
} 
