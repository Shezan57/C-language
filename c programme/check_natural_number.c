#include<stdio.h>
int main(){
    int x;
    printf("Enter a number: ");
    scanf("%d", & x);
    if (x>=0)
    {
        printf("Natural Number");
    }else{
        printf("Not a Natural Number");
    }
    

    return 0;

}