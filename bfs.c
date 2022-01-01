#include<stdio.h>
int q[20],visited[20],g[20][20],r=-1;
void bfs(int x,int n)
{
    printf("Visited : %d\n",x);
    visited[x]=1;
    for(int i=0;i<n;i++)
    if((g[x][i]==1)&&(!visited[i]))
    {  
     q[++r]=i;
     bfs(i,n);
     r--;
    }
}
int main()
{
    int i,j,m,s;
    printf(" Enter size of matrix : ");
    scanf("%d",&m);
    printf(" Enter Matrix : \n");
    for(i=0;i<m;i++)
    for(j=0;j<m;j++)
    scanf("%d",&g[i][j]);
    for(i=0;i<m;i++)
    visited[i]=0;
    printf(" Enter staring node : ");
    scanf("%d",&s);
    bfs(s,m);
    return 0;
}
