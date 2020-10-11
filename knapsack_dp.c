#include<stdio.h>
#include<stdlib.h>                             //dp reduce stack overflow 
typedef struct knapsackDp
{
	int profit;
	int weight;     //weight
	
}Dp;
int max(int a,int b)
{
	return (a>b)?a:b;
}
int knapsackDp(Dp *A,int n,int max_weight)
{
	int dp[n+1][max_weight+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=max_weight;j++)              //i =value j=weight  1 n+1
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(A[i].weight<=j)
				dp[i][j]=max((A[i-1].profit)+dp[i-1][j-(A[i-1].weight)],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][max_weight];
}
int main()
{
	int n,maxi;
	printf("Enter size and max weight of knapsack\n");
	scanf("%d %d",&n,&maxi);
	Dp A[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&A[i].profit,&A[i].weight);
	}
	int result=knapsackDp(A,n,maxi);
	printf("The maximum profit by the given capacity of the knapsack is:\n");
	printf("%d\n",result);
	return 0;
}

	
	
	