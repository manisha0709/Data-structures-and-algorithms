#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 8
typedef struct 
{

 int *C;

 int no_queen;

}BOARD;
void display_board(BOARD B, int n, int *a_sol_no)
{

  int i,j;

  printf("\n\n Solution %d ", ++(*a_sol_no));

  for(i=1;i<=n;i++)

  {

     printf("\n");

     for(j=1;j<=n;j++)

        if(B.C[i]==j)

          printf(" Q"); 

        else

          printf(" X");

   }  

}
int is_safe(BOARD B, int x, int y)

{

  int i;

  for(i=1;i<x;i++)

      if (B.C[i]==y || abs(x-i)==abs(y-B.C[i]))

            return 0;

  return 1; 

}



void n_queen(BOARD *B, int k, int n, int *a_sol_no)
{

  int j;

  for(j=1;j<=n;j++)

        if(is_safe(*B, k, j)) /* Is kth Queen at kth row is safe at jth column. */

          {

              B->C[k]=j; /* Place the kth Queen (at kth row) at jth column. */

             if(k==n) /* All the n Queens are safely placed.*/

                   display_board(*B, n, a_sol_no); /*Displaying the solution.*/

             else

                   n_queen(B,k+1,n, a_sol_no); /* Place the (k+1)th Queen. */

          } 

}
int main()
{
	int l;
printf("Enter no of Queen\n");
 scanf("%d",&l);
 if(l ==2 || l==3)
 {
	 printf("Not Possible Solution\n");
 }
 BOARD *p;
 int sol_no=0;
 p=(BOARD *)malloc(sizeof(BOARD));
 
 //initialisation(p,l);
 n_queen(p,1,l,&sol_no);
 printf("\nThank You!");
 return 0;
}