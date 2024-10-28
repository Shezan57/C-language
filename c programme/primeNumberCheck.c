#include<stdio.h>
int main(){
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    if (x%1 == 0 && x%x == 0 && x%2 !=0)
    {
        printf("Prime Number");
    }else{
        printf("Not a prime number");
    }
    
    return 0;
}