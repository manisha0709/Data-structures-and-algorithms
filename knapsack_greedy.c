#include<stdio.h>
#include<stdlib.h>
typedef struct Knapsack_greedy
{
    int profit;
    int weight;
    float probywgt; 
}sack1;

void bsort(sack1 *A, int n)
{
    int i, j;
    sack1 temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < (n - 1 - i); j++){
            if (A[j].probywgt < A[j + 1].probywgt){
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            } 
        }
     }

}

double knapsack_greedy(sack1 *A, int n, int max_weight)
{
    bsort(A, n);
    int cur_weight = 0, i, left = 0; 
    double result = 0;
    for(i = 0; i < n; i++)
	{
        if(cur_weight + A[i].weight <= max_weight){
            cur_weight = cur_weight + A[i].weight;
            result = result + A[i].profit;
        }

        else{
            left = max_weight - cur_weight;
            result = result + (A[i].profit * ((1.0) * left / A[i].weight));
            break;
        }
    }
    return result;
}


int main()
{
    int n, max_weight;
    int p, w;
    printf("Enter the number of objects and maximum weight that can be filled in the sack:\n");
    scanf("%d %d",&n, &max_weight);
    int i;
    sack1 A[n];
    printf("Enter the profit value and weight value of the object:\n");
    for(i = 0; i < n; i++)
	{
        scanf("%d %d",&A[i].profit, &A[i].weight);
        //A[i].profit = p;
        //A[i].weight = w;
        //A[i].probywgt=((double)p / w);
		A[i].probywgt=((double)A[i].profit / A[i].weight);

    }
    double result;
    result = knapsack_greedy(A, n, max_weight);
    printf("The maximum profit by the given capacity of the sack is:\n");
    printf("%lf", result);
    return 0;
}
