#include<stdio.h>
int main(void){
    int a,b,profit,loss;
    printf("Please Enter the cost price: ");
    scanf("%d",&a);
    printf("Please Enter the selling price: ");
    scanf("%d",&b);
    if(b>a)
    {
        profit=b-a;
        printf("%d will be profit",profit);
    }
    else if (b<a)
    {
        loss=a-b;
        printf("%d will be loss",loss);
    }
    else
    {
        printf("we dont get any loss and profit selling item");
    }
}