#include<stdio.h>
#include<stdlib.h>
#define err -99999
#define inf 10000000
void disp(int *sd,int n,int k)
{
	int i;
	printf("\nRequired minimum distance with refernce %d:\n",k+1);
	for(i=0;i<n;i++)
		if (sd[i]==inf)
			printf("\t%d->can't be reached \n",i+1);
		else
			printf("\t%d->%d\n",i+1,sd[i]);
}
int * traverse(int (*ar)[100],int n,int k,int inft)
{
	int i,j;
	int *sd=(int *)malloc( sizeof(int)*n);
	for(i=0;i<n;i++)
		sd[i]=inft;
	sd[k]=0;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(sd[i]==inft)
				continue;
			for(j=0;j<n;j++)
			{
				if( sd[j]>ar[i][j]+sd[i] && ar[i][j]!=inft)
					sd[j]=ar[i][j]+sd[i];
			}	
		}
	}
	return sd;
}	
void disp_m(int (*ar)[100],int n)
{
	int i=0,j=0;
	printf("The Requered Ajency Matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if (ar[i][j]==inf)
				printf("\tinft");
			else
				printf("\t%d",ar[i][j]);
		}
		printf("\n");
	}
}
int input(int (*ar)[100],int n)
{
    int i=0,j=0,inft=0,k;
	printf("Enter the Number of Edge two pair with its weight (Seperated by space) : ");
	scanf("%d",&k);
	int edge[k][3];
	for(i=0;i<k;i++)
	{
		scanf("%d",&edge[i][0]);
		edge[i][0]--;
		scanf("%d",&edge[i][1]);
		edge[i][1]--;
		scanf("%d",&edge[i][2]);
		inft+=edge[i][2];
	}
	inft=inf;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ar[i][j]=inft;
	for(i=0;i<k;i++)
	{
		ar[edge[i][0]][edge[i][1]]=edge[i][2];
		//ar[edge[i][1]][edge[i][0]]=edge[i][2];
	}
	disp_m(ar,n);
	return inft;
}
int main()
{
    int grp[100][100],n,i,k,*sd;
    printf("Enter the order of Adjency Matrix : ");
    scanf("%d",&n);
    i=input(grp,n);
    printf("\nEnter The Refrence Vertex between 1 to %d : ",n);
    scanf("%d",&k);
	k--;
    sd=traverse(grp,n,k,i);
	disp(sd,n,k);
    return 0;
}







