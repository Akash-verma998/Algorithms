#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *next;
    int vertex;
}node;

node *G[20];
int visited[20];
int n;
void read_graph();
void insert(int,int);
int DFS(int);

void main()
{
    int i,x;
    read_graph();

	for(i=0;i<n;i++)
        visited[i]=0;
    printf("The Traversal is: ");
   int z= DFS(0);
   if(z==n)
   {
       printf("\nThe graph is connected...");

   }
   else
    printf("\nThe graph is not connected...");
}
int ct=0;
int DFS(int i)
{
    node *p;

	printf("\n%d",i);
	ct++;
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;

	   if(!visited[i])
            DFS(i);
        p=p->next;
    }
    return ct;
}

void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("Enter number of vertices:");

	scanf("%d",&n);

	for(i=0;i<n;i++)
    {
        G[i]=NULL;

		printf("Enter number of edges:");
       	scanf("%d",&no_of_edges);

       	for(i=0;i<no_of_edges;i++)
        {
        	printf("Enter an edge(u,v):");
			scanf("%d%d",&vi,&vj);
			insert(vi,vj);
        }
    }
}

void insert(int vi,int vj)
{
    node *p,*q;

	q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;

    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        p=G[vi];

		while(p->next!=NULL)
        	p=p->next;
        p->next=q;
    }
}
