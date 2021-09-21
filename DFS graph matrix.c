// Iplementation of graph using matrix
#include<stdio.h>
int main()
{
 int a[100][100],i,j,n,k;
 printf("enter size of graph : ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
   for(j=0;j<n;j++)
   {
     printf("do u want to map : ");
     scanf("%d",&k);
     if(k==1)
     {
       a[i][j]=1;
     }
     else
     a[i][j]=0;
   }
 }
 for(i=0;i<n;i++)
 {
   for(j=0;j<n;j++)
   {
     if(a[i][j]==1)
     printf("mapped index are %d,%d \n",i,j);
   }
 }
 return 0;
}
