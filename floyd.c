#include<stdio.h>
#include<stdlib.h>
#define max 30
#define inf 9999
typedef struct
{
	int vertex;
	int edge;
	int arr[max][max];
}graph;
void initialise(graph *g)
{
	int i,j,u,v,w;
	for(i=0;i<g->vertex;i++)
	{
		for(j=0;j<g->vertex;j++)
		{   
	        if(i==j)
			    g->arr[i][j]=0;
		    else
				g->arr[i][j]=inf;
		}
	}
	printf("\n Enter the edges and the weights:\n");
	for(i=0;i<g->edge;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		g->arr[u-1][v-1]=w;
	}
}

void floyd(graph g)
{
	int i,j,k;
	for(k=0;k<g.vertex;k++)
	{
		for(i=0;i<g.vertex;i++)
		{
			for(j=0;j<g.vertex;j++)
			{
				if(g.arr[i][j]>g.arr[i][k]+g.arr[k][j])
					g.arr[i][j]=g.arr[i][k]+g.arr[k][j];
			}
		}
	}
	printf("\n the required shortest path:\n");
	for(i=0;i<g.vertex;i++)
	{
		for(j=0;j<g.vertex;j++)
		{
			printf("%d ",g.arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	graph g;
	printf("\n no. of vertices and edges: ");
	scanf("%d%d",&g.vertex,&g.edge);
	initialise(&g);
	floyd(g);
}