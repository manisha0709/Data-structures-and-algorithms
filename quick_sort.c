#include <stdio.h>
#include <stdlib.h>


void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}


int part(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    int j;
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }

    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quick(int arr[],int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot = part(arr,low,high);
        quick(arr,low,pivot-1);
        quick(arr,pivot+1,high);
    }


}
int main()
{   printf("PROGRAM FOR QUICK SORT\n");
   int n;
   printf("Enter The Size Of Array\n");
   scanf("%d",&n);
   int i;
   int arr[100];
   printf("Enter the array to be sorted\n");
   for(i=0;i<n;i++)
   {
    scanf("%d",&arr[i]);
    }
    quick(arr,0,n-1);
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
    printf("%d  ",arr[i]);
    return 0;
}
