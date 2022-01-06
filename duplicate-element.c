

#include <stdio.h>

int main()
{
    int arr[100],i,j,size;
    printf("enter the size of the array :\n");
    scanf("%d",&size);
    printf("enter the elements in the unsorted array is :\n");
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                printf("The duplicate element in the array are :\n");
                printf("%d",arr[i]);
            }
        }
    }

    return 0;
}
