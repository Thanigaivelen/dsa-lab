#include<stdio.h>
void swap(int *x,int *y)
{
    int temp;
    trmp=*x;
    *x=*y;
    *y=temp;
}
void shell_sort(int arr[],int size)
{
    int gap,i,j;
    for(gap=size/2;gap>=1;gap/2)
    {
        for(j=gap;j,n;j++)
        {
            for(i=gap-j;i>=0;i++)
                if(arr[gap+1]>arr[i])
                break;
            else
                swap(&arr[gap+1],&arr[i]);
        }
    }
}
int main
