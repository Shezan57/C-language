#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter first number: ");
    scanf("%d",& a);
    printf("Enter secound number: ");
    scanf("%d",& b);
    printf("Enter third number: ");
    scanf("%d",& c);
    if (a>b && a>c)
    {
        printf("The largest number is %d",a);
    }else if (b>a && b>c)
    {
        printf("The largest number is %d",b);
    }else{
        printf("The largest number is %d",c);
    }
    return 0;
}