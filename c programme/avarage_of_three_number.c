#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("Enter first number: ");
    scanf("%d",& a);
    printf("Enter secound number: ");
    scanf("%d",& b);
    printf("Enter third number: ");
    scanf("%d",& c);
    d = (a+b+c)/3;
    printf("The avarege of three number is %d",d);
    return 0;
}