#include<stdio.h>

void swap(int *a,int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify(int arr[],int n,int i)
{
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;
  
  if(l < n && arr[l] > arr[largest])
    largest = l;

  if(r < n && arr[r] > arr[largest])
    largest = r;

  if( largest != i)
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n , largest);
  }
}

void heap_sort(int arr[], int n)
{
  int i;

  for(i = n/2 - 1;i >= 0;i--)
    heapify(arr,n,i);

  for(i = n-1;i>=0;i--)
  {
    swap(&arr[0],&arr[i]);
    heapify(arr,i,0);
  }
    
}

int main(){
  int n;
  printf("Enetr the size of array:\n");
  scanf("%d",&n);
  int i,arr[n];
  printf("Enter the element of the array:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

  heap_sort(arr, n);
  printf("HEAP SORT\n");
  printf("The sorted array is:\n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  
}