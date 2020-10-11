#include<stdio.h>
#include<stdlib.h>
typedef struct Edge
{
	int source;
	int dest;
	int weight;
}tree;
void sort(tree *edge ,int E)    //edge array and no of edge
{
	int i,j;
	tree temp;
	for(i=0;i<E-1;i++)
	{
		for(j=0;j<(E-1-i);j++)
		{
			if(edge[j].weight>edge[j+1].weight)
			{
				temp=edge[j];
				edge[j]=edge[j+1];
				edge[j+1]=temp;
			}
		}
	}
}//weight sorted

int find_parent(int n,int *parent)
{
	if(parent[n]==n)
		return n;
	return find_parent(parent[n],parent);
}

void kruskal(tree *edge,int E,int v)
{
	sort(edge,E);
	tree output_array[v-1];
	int parent[v],i;
	for(int i=0;i<v;i++) 
		parent[i]=i;    //parent array
	
	int count=0,j=0;
	tree cur_edge;
	while(count!=v-1)
	{
	
		cur_edge=edge[j];
		int source_parent=find_parent(cur_edge.source, parent);
		int dest_parent=find_parent(cur_edge.dest,parent);
		if(source_parent!=dest_parent)
		{
			output_array[count]=cur_edge;
			count++;
			parent[source_parent]=dest_parent;
		}
		j++;
	}
	    printf("The final array for the MST is:\n");
	        for(i = 0; i < v-1; i++){
            if(output_array[i].source < output_array[i].dest){
                printf("%d-->%d : %d", output_array[i].source, output_array[i].dest, output_array[i].weight);
                printf("\n");
            }
            else
            {
                printf("%d-->%d : %d", output_array[i].dest, output_array[i].source, output_array[i].weight);
                printf("\n");
            }      
        }
    int sum = 0;
    printf("The total cost is: ");
    for(i = 0; i < v - 1 ; i++){
        sum = sum + output_array[i].weight;
    }
    printf("%d", sum);
	
}
int main()
{
		int E,V,s,i,d,w;
		printf("Enter number of vertices and edges:\n");
		scanf("%d %d",&V,&E);
		tree edge[E];
		printf("Enter the Source Vertix, Destination Vertex and Weight:\n"); 
		for(i = 0; i< E; i++){
        scanf("%d %d %d", &s, &d, &w);
        edge[i].source = s;
        edge[i].dest = d;
        edge[i].weight = w;  
    }
    kruskal(edge, E, V);
    return 0;
		
}		
	
	
	
	
	
	
	
	
	
	
	
	
	













	
	