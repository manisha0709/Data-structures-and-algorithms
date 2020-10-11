#include<stdio.h>
#include<stdlib.h>
int Activity(int start[],int finish[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(finish[i]>finish[j])              //sort finish time
			{
				temp=finish[i];
				finish[i]=finish[j];
				finish[j]=temp;
				temp=start[i];
				start[i]=start[j];
				start[j]=temp;
			}
		}
	}
	printf("Time selected for Job is:");
	printf("\nstart time=%d end time=%d",start[0],finish[0]);
    for(i=1;i<n;i++)
   {
		if(start[i]>=finish[0])
		{
			printf("\nstart time=%d end time=%d",start[i],finish[i]);
			finish[0]=finish[i];
		}
   }
   return 0;
}


int main()
{
	int n,i,start[20],finish[20];
	printf("\n Enter the no. of Activities: ");
	scanf("%d",&n);
	printf("\nstart timings of all Actities: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&start[i]);
	}
	printf("\nEnd timings of all actities: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&finish[i]);
	}
	Activity(start,finish,n);
	return 0;
}
