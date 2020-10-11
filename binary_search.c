#include<stdio.h>
#define MAX 100
void merge(int arr2[],int l,int mid,int h)
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
void display(int arr[],int n)
{
	int i=0;
	printf("Array is: ");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
		
	puts("");
}
void mergeSort(int arr1[],int l, int h)
{
	int mid=0;
	if(l<h)
	{
		mid=(l+h)/2;
		mergeSort(arr1,l,mid);
		mergeSort(arr1,mid+1,h);
		merge(arr1,l,mid,h);
	}
}
int binarySearch(int arr[],int n,int search)
{

	int l=0,h=n-1;
	while(l<=h)
	{
		//int mid=(l+h)/2;
		int mid=l+(h-l)/2;
		if(arr[mid]==search)
			return mid;
		else if(arr[mid]>search)
			h=mid-1;
		else if(arr[mid]<search)
			l=mid+1;
			
		//printf("l=%d mid=%d h=%d\n",l,mid,h);
		
	}
	return -1;
}
int checkSortedAscending(int arr[],int n)
{
	int i=0,flag=1;
	for(i=0;i<n-1;i++)
		if(arr[i]<arr[i+1])
		{
			flag=0;
			return flag;
		}
	return flag;
}
int checkSortedDescending(int arr[],int n)
{
	int i=0,flag=1;
	for(i=0;i<n-1;i++)
		if(arr[i]>arr[i+1])
		{
			flag=0;
			return flag;
		}
	return flag;
}
int main()
{
	int arr[MAX];
	int n,i,search=0,search_result=0,sorted=0,choice=1;
	printf("Enter The length of the array ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the elements: ");
		scanf("%d",&arr[i]);
	}
	if(!checkSortedAscending(arr,n) && !checkSortedDescending(arr,n))
	{
		printf("Found unsorted Array.\nSorting..\n");
		mergeSort(arr,0,n-1);
		printf("Sorted Array ");
	}
	display(arr,n);
	while(choice)
	{
		printf("Enter value to be Searched: ");
		scanf("%d" ,&search);
		search_result=binarySearch(arr,n,search);
		if(search_result!=-1)
			printf("Found at position: %d\n",search_result+1);
		else
			printf("Not Found\n");
		printf("Want to search another value? ([1]/0): ");
		scanf("%d",&choice);
	}
	printf("program terminated\n");
	return 0;
}
		
