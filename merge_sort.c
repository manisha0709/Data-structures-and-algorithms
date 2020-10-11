#include <stdio.h>
#include<stdlib.h>
#define MAX 100
void merge(int a[], int l, int m, int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1], R[n2];
	for(i=0;i<n1;i++)
		L[i] = a[l+i];

	for(j=0;j<n2;j++)
		R[j]=a[m+1+j];

	i=0;j=0;k=l;

	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i++];
		}
		else
			a[k]=R[j++];
		k++;
	}

	while(i<n1)
		a[k++]=L[i++];
	while(j<n2)
		a[k++]=R[j++];
}
void Merge(int arr2[],int l,int mid,int h)
{
	int i=l,j=mid+1,k=l,arr3[MAX];
	while(i<=mid && j<=h)
	{
		if(arr2[i]<arr2[j])
			arr3[k++]=arr2[i++];
		else
			arr3[k++]=arr2[j++];
	}
	while(i<=mid)
		arr3[k++]=arr2[i++];
	while(j<=h)
		arr3[k++]=arr2[j++];
	for(i=l;i<=h;i++)
		arr2[i]=arr3[i];
}
void mergeSort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}	
}
int main()
{
	int i,n,A[100];
	printf("Enter the elements needed:\n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<=n;i++)
	{
		scanf("%d",&A[i]);
	}
	mergeSort(A,0,n);
	for(i=0;i<=n;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
