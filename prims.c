#include<stdio.h>
#include<stdlib.h>
#define inf 9999
#define max 20
int g[max][max],span[max][max],n;
int prims();
int main()
{
	int i,j,total;
	printf("Enter no of vertices:");
	scanf("%d",&n);
	printf("\n Enter the adjancecy matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	

	total=prims();
	printf("\n spannning tree matrix:");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",span[i][j]);
	}
	printf("\n\n Total cost of spanning tree=%d: ",total);
	return 0;
	
}
			
int prims()
{
	int u,v,min_d,d[max],start[max],cost[max][max],visited[max],edges,i,j,min_cost;
	for(i=0;i<n;i++)                 //cost matrix
	{
		for(j=0;j<n;j++)
		{
			if(g[i][j]==0)
				cost[i][j]=inf;
			else
				cost[i][j]=g[i][j];
				span[i][j]=0;
		}
	}

	d[0]=0;
	visited[0]=1;       //first node
	for(i=1;i<n;i++)
	{
		d[i]=cost[0][i];
		start[i]=0;
		visited[i]=0;
	}
	min_cost=0;
	edges=n-1;
	while(edges>0)
	{
		min_d=inf;
		for(i=1;i<n;i++)
			if(visited[i]==0 && d[i]<min_d)
			{
				v=i;
				min_d=d[i];
			}
		
			u=start[v];
			span[u][v]=d[v];
			span[v][u]=d[v];
			edges--;
			visited[v]=1;
		
			
		for(i=1;i<n;i++)
			if(visited[i]==0 && cost[i][v]<d[i])
			{
				d[i]=cost[i][v];
				start[i]=v;
			}
		min_cost=min_cost+cost[u][v];
	}
	
		return(min_cost);
}
	
			
			
			
			
			
			
			
			
			
