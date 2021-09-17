#include <stdio.h>
#include <stdlib.h>
int i,size=5;

int insertion(int arr[6],int element,int position)
{
  int i;
  size=5;
  int k=size;
  for(i=0;i<size;i++)
  {
    if(k>=position)
    arr[k]=arr[k-1];
    k--;
  }
  arr[position]=element;
  printf("New Array");
  for (i=0;i<size+1;i++)
  {
  printf("%d \t",arr[i]);
  }
  return 0;
}



int deletion(int arr[5],int position)
{
  size=5;
  for(i=position;i<size-1;i++)
  {
    arr[i]=arr[i+1];
  }
  printf("New array");
   for (i=0;i<size-1;i++)
  {
  printf("%d \t",arr[i]);
  }
  return 0;
}



int travers(int arr[5])
{
  for(i=0;i<size;i++)
  {
    printf("%d \n",arr[i]);
  }
  return 0;
}


int SearchElement(int arr[5],int N)
{

  for(i=0;i<size;i++)
  {
    if(arr[i]==N)
    {
      printf("Element Found at %d position",i+1);
      exit(0);

    }

  }
  printf("Element not Found");
  return 0;

}

int SearchPosition(int arr[5],int N)
{
  if(i<N)
  {
    printf("Element in the position: %d",arr[N]);
  }
  else
  {
    printf("provide valid position");
  }
  return 0;
}


int main() {
  int arr[6],i,choice,element,position,flag,p;
  
  printf("Enter the elements \n");
  for(i=0;i<5;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Enter the Operation \n");
  printf("1.Insertion \n2.Deletion \n3.Search \n4.Travers \n\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    {
      printf("Enter the element to insert and index of the elements \n");
      scanf("%d %d",&element, &position);

    insertion(arr,element,position);
    break;
    }
    case 2:
    {
    printf("Enter the index to be deleted \n");
    scanf("%d",&position);
    deletion(arr,position);
    break;
    }
   
    case 3:
    {
      printf("1.search by element \n2.search by position \n");
      scanf("%d",&p);
      if(p==1)
      {
      printf("Enter the element to be searched \n");     
      scanf("%d",&element);
      SearchElement(arr,element);
      }
      else{
        printf("Enter the position to be searched \n");
        scanf("%d",&position);
        SearchPosition(arr,position-1);
      }
      break;
    }
   
    case 4:
    {
      travers(arr);
      break;
    }
    default:
    {
      printf("Enter the valid case");
    }

 
  }

  

  return 0;
}
