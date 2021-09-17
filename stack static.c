 #include <stdio.h>
 int a[100],n,i,x,c,top=-1;
void push()
{
    if(top>=n-1)
    printf("full \n");
    else
    {
        top++;
        printf("enter element : ");
        scanf("%d",&x);
        a[top]=x;
    }
}
void pop()
{
    if(top>-1)
    {
         printf("element  deleted is : %d \n ",a[top]);
         top--;
    }
    else
    printf("stack is empty \n");
}
void disp()
{
    printf("stack has : \n ");
  while(top!=-1)
    {
         printf("\t %d \n ",a[top]);
         top--;
    }
}
int main(void) 
{
     printf("enter size : ");
     scanf("%d",&n);
    do
    {
         printf("enter code : ");
         scanf("%d",&c);
         switch(c)
         {
             case 1:
             {
                 push();
                 break;   
             }
             
             case 2:
             {
                 pop();
                 break;
             }
             case 3:
             { 
                 disp();
                 break;
             }
             deafult:
             {
                 printf("enter valid choice \n");
             }
         }      
    }while(c<=4);          
  return 0;
}
