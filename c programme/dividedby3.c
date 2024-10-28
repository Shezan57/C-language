#include<stdio.h>


int main(){
    int i , j;
    int sum = 0;
    for(i = 1; i <= 20; i++){
        sum = 0;
        for(j = 1; j <= 10; j++){
           sum = sum + i;
            printf("%d X %d = %d\n",i,j,sum);
        } 
        printf("\n");
    }

    return 0;
}