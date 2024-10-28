#include<stdio.h>
int main(){
    int x;
    printf("Enter a number: ");
    scanf("%d",& x);
    printf("your number is %d", x % 2== 0 );
    return 0;
}