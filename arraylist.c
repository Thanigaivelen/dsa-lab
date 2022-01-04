#include<stdio.h>
void insert(int b[20],int m)
{
    int i,s,value;
    printf("Enter index to insert :");
    scanf("%d",&s);
    printf("Enter value to insert :");
    scanf("%d",&value);
    for(i=m;i>s;i--)
    b[i]=b[i-1];
    b[s]=value;
}
void deleten(int b[20],int m)
{
  int i,s,f;
  printf("Enter index to delete : ");
  scanf("%d",&s);
  for(i=s;i<m;i++)
  b[i]=b[i+1];
}
void searchv(int b[20],int m)
{
  int i,s;
  printf("Enter element to search : ");
  scanf("%d",&s);
  for(i=0;i<m;i++)
  {
   if(b[i]==s)
   printf("Element found %d at index %d\n",b[i],i);
   else
   printf("Element is not there\n");
  }
}
void search(int b[20],int m)
{
    int i,s;
    printf("Enter index to search : ");
    scanf("%d",&s);
    for(i=0;i<m;i++)
    {
      if(i==s)
      printf("Element found at index %d is %d\n",i,b[i]);
      else
      printf("Element is not there\n");
    }
}
void display(int b[20],int m)
{
  int i;
  printf("array elements are :\n");
  for(i=0;i<m;i++)
  printf("%d",b[i]);
  printf("\n");
}
int main()
{
    int a[20],i,n,ch,f;
    printf("Enter size : ");
    scanf("%d",&n);
    printf("Enter Array : ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    do
    {
    printf("Enter choice : \n");
    printf("1.insert 2.delete 3.seacrh by value 4. search by index 5.dsiplay\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert(a,n);
        n++;
        break;
        case 2:deleten(a,n);
        n--;
        break;
        case 3:searchv(a,n);
        break;
        case 4:search(a,n);
        break;
        case 5:display(a,n);
        break;
        default : printf("PROGRAM TERMINATED");
    }
    printf("Do u want to continue ");
    scanf("%d",&f);
    }while(f==1);
return 0;
}
