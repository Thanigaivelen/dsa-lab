// Iplementation of graph using matrix
#include <stdio.h> 

int dfs(int x,int size);
int graph[10][10],visited[10];
int main()
{
  int i,j,size;
  printf("enter the size less then 10 \t");
  scanf("%d",&size);
  for(i=0;i<size;i++)
  {
    for(j=0;j<size;j++)
      scanf("%d",&graph[i][j]);
    visited[i]=0;

  }
  printf("\nMatrix \n");
  for(i=0;i<size;i++)
  {
    printf("\n");
    for(j=0;j<size;j++)
      printf(" %d ",graph[i][j]);
  }
  printf("\n\n");
  dfs(0,size);

}
int dfs(int x,int size)
{
  int j;
  visited[x]=1;
  printf("\n%d",x);
  for(j=0;j<size;j++)
  {
    if(visited[j]!=1&&graph[x][j]==1)
      dfs(j,size);
  }
   return 0;
}
