#include<stdio.h>
#include<stdlib.h>
#define inft -999999
char alpha[26];
int mem[100][100];
typedef struct node
{
	int wt,vtx;
	struct node *next;
}node;
typedef struct edge
{
	int wt,vtx1,vtx2;
}edge;
int min(int *ar,int *vis,int n)
{

	int ind=n+1,i;
	for(i=1;i<=n;i++)
	{
		if((ind==n+1||ar[i]<ar[ind]) && vis[i]==0)
			ind=i;
	}
	return ind;
}
void merge(edge *a,int l,int m,int r)
{
    int i,kr=0,kl=0,hr,hl;
	edge lft[100],rgt[100];
    for(i=l;i<=m;i++)
        lft[kl++]=a[i];
    for(i=m+1;i<=r;i++)
        rgt[kr++]=a[i];
    hr=kr;
    hl=kl;
    for(i=l,kr=0,kl=0;kl+kr<hr+hl;i++)
    {
        if(kr<hr && kl<hl)
        {
            if(lft[kl].wt<rgt[kr].wt)
            {
                a[i]=lft[kl];
                kl++;
            }
            else
            {
                a[i]=rgt[kr];
                kr++;
            }
        }
        else if(kr<hr && kl>=hl)
        {
            a[i]=rgt[kr];
            kr++;
        }
        else if(kr>=hr && kl<hl)
        {
            a[i]=lft[kl];
            kl++;
        }
    }
}
void merge_sort(edge *a,int l,int r)
{
    int m,i;
    if(l<r)
    {
        m=(l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
void ini(node **g,int ver)
{
	for(;ver>0;ver--)
		g[ver]=NULL;
}
void disp(node **g,int ver)
{
	int i=0;
	node *t;
	printf("\nAdjancy List :\n"); 
	for(i=1;i<=ver;i++)
	{
		t=g[i];
		printf("Ver %d : ",i);
		while(t)
		{
			printf("|ver=%d wt=%d|->",t->vtx,t->wt);
			t=t->next;
		}
		printf("NULL\n");
	}
}
int input(node **g,edge *e,int *n)
{
	int type,from,to,wgt,ver,i;
	node *t,*prv;
	while(1)
	{
		printf("Choose the type of Graph To Consruct :\n1)Di-Graph\n2)Non-digraph\n Your Choice : ");
		scanf("%d",&type);
		if(type!=1 && type!=2)
			printf("Enter Valid Choice Lets try this again ");
		else
			break;
	}
	printf("\nEnter Number of Edges : ");
	scanf("%d",n);
	printf("\nEnter Number of Vertex : ");
	scanf("%d",&ver);
	ini(g,ver);
	printf("\nProvide Input in following %d lines each containing Two vertex and Weight each Seprated by space \n",*n);
	for(i=0;i<*n;i++)
	{
		scanf("%d",&from);
		scanf("%d",&to);
		scanf("%d",&wgt);
		t=g[from];
		e[i].wt=wgt;
		e[i].vtx1=to;
		e[i].vtx2=from;
		prv=NULL;
		while(t)
		{
			prv=t;
			t=t->next;
		}
		t=(node *)malloc(sizeof(node));
		if(prv)
			prv->next=t;
		else 
			g[from]=t;
		t->vtx=to;
		t->wt=wgt;
		t->next=NULL;
		if(type==2)
		{
			t=g[to];
			prv=NULL;
			while(t)
			{
				prv=t;
				t=t->next;
			}
			t=(node *)malloc(sizeof(node));
			if(prv)
				prv->next=t;
			else 
				g[to]=t;
			t->vtx=from;
			t->wt=wgt;
			t->next=NULL;
			//printf("type=%d\n",type);
		}
	}
	disp(g,ver);
	return ver;
}
void add(int *comp,int vtx1,int vtx2,int *size)
{
	int i,j,sc=mem[0][vtx1],n=size[vtx1],tr=mem[0][vtx2],n2=size[vtx2];
	for(i=1;i<=n;i++)
	{
		mem[i+size[vtx2]][tr]=mem[i][sc];
		comp[mem[i][sc]]=comp[vtx2];
		mem[0][mem[i][sc]]=vtx2;
		size[mem[i][sc]]=n+n2;
	}
	for(i=1;i<=size[vtx2];i++)
	{
		size[mem[i][tr]]=n+n2;
	}
	size[vtx2]=n+n2;
	size[tr]=n+n2;
}
	
void kruskal(node **g,edge *e,int ver,int n)
{
	int i,k,comp[100],size[100],j;
	node *t;
	edge res[100];
	merge_sort(e,0,n-1);
	for(i=1;i<=ver;i++)
	{
		comp[i]=i;
		mem[0][i]=i;
		mem[1][i]=i;
		size[i]=1;	
	}/*
	printf("\nSorted Edge : ");
	for(i=0;i<n;i++)
	{
		printf("|wt:%d,vtx1:%d,vtx2:%d|\t",e[i].wt,e[i].vtx1,e[i].vtx2);
	}*/
	for(i=0,k=0;i<n;i++)
	{
		if(comp[e[i].vtx1]!=comp[e[i].vtx2])
		{
			if(size[e[i].vtx1]<size[e[i].vtx2])
				add(comp,e[i].vtx1,e[i].vtx2,size);
			else 
				add(comp,e[i].vtx2,e[i].vtx1,size);
			res[k++]=e[i];
		}
	}	
	printf("\nEdge present in Spanning tree(Calculated Using Kruskal's Algo) : ");
	for(i=0;i<k;i++)
	{
		printf("%c%c\t",alpha[res[i].vtx1-1],alpha[res[i].vtx2-1]);
	}
}
void prims(node **g,int ver,int n,int inf)
{
	int i,nbr[ver+1],vis[ver+1],dis[ver+1],s,ij;
	node *t;
	for(i=1;i<=ver;i++)
	{
		nbr[i]=-1;
		dis[i]=inf;
		vis[i]=0;
	}
	s=1;
	vis[s]=1;
	dis[s]=0;
	t=g[s];
	nbr[s]=s;
	while(t)
	{
		nbr[t->vtx]=s;
		dis[t->vtx]=t->wt;
		t=t->next;
	}
	for (i=1;i<=ver;i++)
	{
		s=min(dis,vis,ver);
		if(s==ver+1)
			break;
		vis[s]=1;
		t=g[s];
		while(t)
		{
			if(vis[t->vtx]==0 && dis[t->vtx]>t->wt)
			{
				dis[t->vtx]=t->wt;
				nbr[t->vtx]=s;
			}
			t=t->next;
		}


	}
	printf("\nEdge present in Spanning tree(Calculated Using Prim's Algo) : ");
	for (i=1;i<=ver;i++)
	{
		if(nbr[i]!=i)
			printf("%c%c\t",alpha[nbr[i]-1],alpha[i-1]);
	}

}
	
int main()
{
	int n,ver,inf,i,type;	//n:number of Edge
	edge e[100];
	node *g[100];
	int mem[100][100];
	ver=input(g,e,&n);
	for(i=0;i<ver;i++)
		alpha[i]=65+i;
	while(1)
	{
		printf("Choose One option from below :\n1)kruskal Algorithm \n2)Prims Algorithm \n Your Choice : ");
		scanf("%d",&type);
		if(type!=1 && type!=2)
			printf("Enter Valid Choice Lets try this again ");
		else
			break;
	}
	if(type ==1)
		kruskal(g,e,ver,n);
	else
	{
		for(i=1;i<=ver;i++)
			inf+=e[i].wt;
		inf++;
		prims(g,ver,n,inf);
	}
	return 0;
}
	
/*
1 3 5
1 7 10
2 3 10
3 7 12
2 4 15
7 6 9
3 8 4
7 8 6
4 9 11
4 5 12
5 6 3
6 9 5
1 2 5
*/