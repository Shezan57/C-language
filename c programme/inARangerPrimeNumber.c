#include<stdio.h>
int main(){
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    for (int i = 1; i <= x; i++)
    {
       if(x%1 == 0 && x%x == 0 && x%2 !=0){
        printf("prime numbers are %d",x);
       } else{
        printf(" Error");
       }
    }
    
    return 0;
}