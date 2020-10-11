#include<stdio.h>
#include<stdlib.h>
#define MAX 100
/*int merge(int a[],int l, int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int a1[n1],a2[n2];
	for(i=0;i<n1;i++)
		a1[i]=a[l+i];
	for(j=0;j<n2;j++)
		a2[j]=a[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			a[k]=a1[i];
			i++;
		}
		else
		{
			a[k]=a2[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=a1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
	a[k]=a2[j];
	j++;
	k++;
	}
}*/
void mergee(int ar2[],int l,int m,int h)
{
	int i=l,j=m+1;
	int k=l;
	int ar3[MAX];
	while(i<=m && j<=h)
	{
		if(ar2[i]<ar2[j])
		{
			ar3[k++]=ar2[i++];
		}
		else if(ar2[j]<ar2[i])
		{
			ar3[k++]=ar2[j++];
		}
	}
	while(i<=m)
	{
		ar3[k++]=ar2[i++];
	}
	while(j<=h)
	{
		ar3[k++]=ar2[j++];
	}
	for(i=l;i<=h;i++)
		ar2[i]=ar3[i];
}
	

int mergesort(int a[],int l,int r)
{
	if(l<r)
	{
	int mid=(l+r)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
	mergee(a,l,mid,r);
	}
	
}

void maxmin(int a[],int n,int min,int max)
{
	//max=a[0];
	//min=a[0];
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]<min)
		{
		min=a[i];
		}
		else if(a[i]>=max)
		{
		max=a[i];
		}
	
	}
	printf("max %d\n min %d\n",max,min);
	
}	
int main()
{
	int a[100],n,i,j,max,min;
	printf("enter size of array\n");
	scanf("%d",&n );
	printf("enter element\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	//max=findMax(a,0,n-1);   
	//min=findMin(a,0,n-1);
	printf("1 for dynamic method \n 2 for divide and conquer\n");
	scanf("%d",&j);
	switch(j)
	{
	case 1:mergesort(a,0,n);
		printf("minimum element :%d\n maximum element: %d\n",a[0],a[n-1]);
		break;
	case 2:maxmin(a,n,a[0],a[0]);
		break;
	}
	return 0;
}


