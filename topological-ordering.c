#include<stdio.h>

void topo (int G[20][20] ,int size);
int visited[20];
int main()
{
	int i, j, size;
	int G[20][20];
	printf("Enter the size of matrix: ");
	scanf("%d",&size);
	printf("Enter the adjacency of matrix:\n");
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

	printf("vertices according to topological sorting are: \n");
  topo(G, size);

  return 0;
}

void topo (int G[20][20],int size)
{
	// find zero pointing node 
  for (int k = 0; k < size; k++) {
    int count = 0, node = -1;
    for (int i = 0; i < size; i++) {
      count = 0;
      for(int j = 0; j < size; j++) {
        // printf("%d ", G[j][i]);
        if(G[j][i] == 0 && !visited[i]) {
          count++;
        }
      }
      // printf("count: %d and i = %d\n", count, i);
      if (count == size) {
        node = i;
        visited[node] = 1;
        break;
      }
    }
    printf("%d\n", node);

    for (int i = 0; i < size; i++) 
      G[node][i] = 0;
  }
}
