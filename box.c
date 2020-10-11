#include<stdio.h>

int main(){
    int a[100],b[50];
    int d,s;
    printf("Enter the no of house: ");
    scanf("%d",&s);
    printf("Enter the distance d: ");
    scanf("%d",&d);
    printf("Enter the location of house: ");
    for(int i=0;i<s;i++){
        scanf("%d",&a[i]);
    }
    b[0]=a[0]+d;
    int j=0;
    for(int i=1;i<s;i++){
        if(a[i]-b[j] < 0 && b[j]-a[i] <= d)
            continue;
        if(a[i]-b[j] > 0 && a[i]-b[j] <= d)  
            continue;
        if(a[i]+d >= a[s-1]){
            b[++j]=a[s-1];
            break;
        }
        b[++j]=a[i]+d;     
    }
    printf("The location of Super Box is: ");
    for(int i=0;i<=j;i++)
        printf("%d ",b[i]);
        return 0;
}
