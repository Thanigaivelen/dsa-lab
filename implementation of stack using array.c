#include <stdio.h>

#define N 5
int top = -1;
int arr[N];

void push(){
  int x;
  printf("Enter number:");
  scanf("%d",&x);
  if(top==N-1)
  {
    printf("\nstack is full");
  }
  else
  {
    top++;
    arr[top]=x;
    printf("\npush is successful");
    
  }
}
void pop(){
  int y;
  if(top ==-1){
    printf("\nStack is empty");
  }
  else{
    arr[top]=y;
    top--;
    printf("\n%d is popped out",y);
  }
}
void Top(){
  if (top==-1){
    printf("\nstack is empty");
  }
  else{
    printf("\n The top element is %d",arr[top]);
  }
}
void display(){
  int i;
  if(top==-1){
    printf("\nstack is empty");
  }
  else{
    printf("\nThe elements in stack are :");
    for(i=top;i>=0;i--){
      printf("\n %d",arr[i]);
    }
  }
}


int main(void) {
  push();
  push();
  push();
  pop();
  Top();
  display();
  printf("\nHello World\n");
  
  return 0;
}
