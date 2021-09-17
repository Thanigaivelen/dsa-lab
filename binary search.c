#include <stdio.h>

int main(void) {
   int a[100],i,s,mid,n,j,beg=0;
   printf("Enter size : ");
   scanf("%d",&n);
    printf("Enter Array : ");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   printf("Enter search element : ");
   scanf("%d",&j);
   while(beg<=n)
   {
     mid=(n+beg)/2;
     if(a[mid]==j)
     {
         printf("Search element's position %d and Element is %d",(mid+1),a[mid]);
         break;
     }
     if(j<a[mid]) 
      n=mid-1;
     else if(j>a[mid])
      beg=mid+1;
   }
  return 0;
}
