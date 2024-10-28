#include<stdio.h>
int main(){
    int r,row;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    row =r;
    for(int i =1; i<=r; i++){
        for(int j=1; j<=row-1; j++){
            printf(" ");
        }
        for(int k=1; k<= 2*i-1; k++){
        printf("*");
    }
    row--;

    printf("\n");
    }
    
    return 0;
}