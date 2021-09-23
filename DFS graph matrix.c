// Iplementation of graph using matrix
#include<stdio.h>
#include<stdlib.h>
void DFS (int x ,int size);
int G[20][20],visited[20];
void main()
{
    int i,j,size;
    printf("ENTER THE SIZE OF THE MATRIX\n");
    scanf("%d",&size);
    printf("ENTER THE ADJACENCY OF THE MATRIX :\n");
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
           scanf("%d",&G[i][j]);
        }
    }

    for (i=0;i<size;i++)
    {
        visited[i]=0;
    }

    DFS(0,size);
}
void DFS(int x,int size)
{
    int j;

    printf("%d",x);

    printf("\n");

    visited[x]=1;

    for(j=0;j<size;j++)

       if(!visited[j]&&G[x][j]==1)
        DFS(j,size);
}
