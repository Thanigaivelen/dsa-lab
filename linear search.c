#include <stdio.h>
int main(void) {
   int a[100],i,s,n,f=0;
   printf(" Enter size : ");
   scanf("%d",&n);
   printf(" Enter the array : ");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   printf(" Enter the element to search : ");
   scanf("%d",&s);
   for(i=0;i<n;i++)
   if(a[i]==s)
   {
       f++;
       break;
   }
   if(f==1)
   printf(" Element's position is %d Element is %d",(i+1),a[i]);
   else
   printf(" Element not found ");
  return 0;
}
