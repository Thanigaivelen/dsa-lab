#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *p;
};
struct node *top =0;

void push(int x){
  struct node *newnode;
  newnode= (struct node*)malloc(sizeof(struct node));
  newnode-> data = x;
  newnode->p = top;
  top= newnode;
}

void display(){
  struct node *temp;
  temp = top;
  if(top==0){
    printf("stack is empty");
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
    printf("stack is empty");
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
  push(10);
  push(20);
  push(30);
  push(40);
  push(50);
  push(60);
  display();
  peek();
  pop();
  peek();
  printf("\nthe remaining elements are :");
  display();
  return 0;
}