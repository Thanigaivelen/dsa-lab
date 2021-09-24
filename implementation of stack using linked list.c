#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *p;
};
struct node *top =0;

void push(){
  struct node *newnode;
  int a;
  for(int i=0;i<5;i++)
  {
     printf("element to insert in the stack :");
     scanf("%d",&a);
     newnode= (struct node*)malloc(sizeof(struct node));
     newnode-> data = a;
     newnode->p = top;
     top= newnode;
  }
}

void display(){
  struct node *temp;
  temp = top;
  if(top==0){
    printf("stack is empty\n");
  }
  else{
    while(temp!=0){
      printf("\n%d",temp->data);
      temp= temp->p;
    }
  }
}
void peek(){
  if(top==0){
    printf("stack is empty\n");
  }
  else{
    printf("\n%d is the top element ",top->data);
  }
}
void pop(){
  struct node *temp;
  temp=top;
  top=temp->p;
  free(temp);
  printf("\npop is done");
}

int main(void) {
   push();
 /* push(10);
  push(20);
  push(30);
  push(40);
  push(50);
  push(60);*/
  display();
  peek();
  pop();
  peek();
  printf("\nthe remaining elements are :");
  display();
  return 0;
}
