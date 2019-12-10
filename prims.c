#include<stdio.h>

#define MAX 10
int G[MAX][MAX],spanning[MAX][MAX],n;
int prims();
int main()
{
	int i,j,total_cost;
	printf("Enter no. of vertex in graph:");
	scanf("%d",&n);

	printf("\nEnter the cost of adjacency matrix:\n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	total_cost=prims();
	printf("\nspanning tree matrix for :\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",spanning[i][j]);
	}
	printf("\n\nTotal cost of spanning tree=%d",total_cost);
	return 0;
}

int prims()
{
	int cost[MAX][MAX];
	int u,v,min_distance,distance[MAX],from[MAX];
	int visited[MAX],i,min_cost=0,j,no_of_edges;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=9999;
			else
				cost[i][j]=G[i][j];
				spanning[i][j]=0;
		}
	distance[0]=0;
	visited[0]=1;
	for(i=1;i<n;i++)
	{
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	no_of_edges=n-1;
	while(no_of_edges>0)
	{
		min_distance=9999;
		for(i=1;i<n;i++)
			if(visited[i]==0 && distance[i]<min_distance)
			{

				min_distance=distance[i];
				u=i;
			}

		v=from[u];
		spanning[v][u]=distance[u];
		no_of_edges--;
		visited[u]=1;
		for(i=1;i<n;i++)
			if(visited[i]==0&&cost[i][u]<distance[i])
			{
				distance[i]=cost[i][u];
				from[i]=u;
			}
		min_cost=min_cost+cost[v][u];
	}
	return(min_cost);
}

