#include<stdio.h>
void assign(int (*grph)[100],int *color,int m)
{
   int i,j;
   color[m]=1;  
   for(i=0;i<m;i++)
   { 
     if(grph[i][m]!=0 && color[m]==color[i]) 
       color[m]=color[i]+1;  
   }
}

int main()
{
  int n,edge,i,j,k,grph[100][100],color[1000],max;
  printf("Enter no. of vertices present in graph: ");
  scanf("%d",&n);
  printf("Enter no. of edges present in graph : ");
  scanf("%d",&edge);  
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      grph[i][j]=0; 
  printf("Enter the two vertex number of connected vertices seprated by space in the following lines :\n");
  for(i=0;i<edge;i++)
  {
    scanf("%d %d",&j,&k);
    grph[j-1][k-1]=1;
    grph[k-1][j-1]=1;
  }
  for(i=0;i<n;i++)
    assign(grph,color,i); 
  printf("The vertex would have following color type: \n");
  max=color[0];
  for(i=0;i<n;i++)
  {  
    printf("Vertex %d  : type-%d\n",i+1,color[i]);
    if(color[i]>max)
      max=color[i];
  }
  printf("\nChromatic Number = %d",max);
  return 0;
} 