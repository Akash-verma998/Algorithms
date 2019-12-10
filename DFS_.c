#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n;    
 int count=0;
int main()
{
    int i,j;
    printf("Enter number of vertices:");
   
	scanf("%d",&n);
	printf("\nEnter adjecency matrix of the graph:");
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
    DFS(0);
    for(i=0;i<n;i++)
    {
    	if(visited[i])
    	{
    		count++;
		}
	}
    if(count==n)
    {
    	printf("\nGraph is Connected\n");
	}
	else
	{
		printf("\nGraph is disconnected\n");
	}
}
 
void DFS(int i)
{
    int j;
	printf("\n%d",i);
    visited[i]=1;
	
	for(j=0;j<n;j++){
       if(!visited[j]&&G[i][j]==1){
            DFS(j);
        }
    }
}
