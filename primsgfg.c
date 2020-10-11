#include<stdio.h>
#include<stdlib.h>
#define max 100
#define inf 9999
int g[max][max];
int cost[max][max];
int span[max][max];
int n;
int prims()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(g[i][j]==0)
				cost[i][j]=inf;
			else{
				cost[i][j]=g[i][j];
				span[i][j]=0;
			}
				
		}
	}
	d[0]=0;
	visited[0]=1;
	for(int i=1;i<n;i++)
	{
		d[i]=cost[0][i];
		visited[i]=0;
		start[i]=0;
	}
	edge = n-1;
	while(edge>0)
	{
		min_d=inf;
		for(int i=1;i<n;i++)
		{
			if(!visited[i] && d[i]<min_d)
			{
				min_d=d[i];
				v=i;
			}
		}
		u=start[v];
		span[u][v]=d[v];
		span[v][u]=d[v];
		visited[i]=1;
		edge--;
		
		for(int i=1;i<n;i++)
		{
			if(!visited[i] && cost[i][v]<d[i])
			{
				cost[v][i]=d[i];
				start[i]=v;
			}
		}
		min_cost=min_Cost+cost[u][v];
	}
	return min_cost;
}