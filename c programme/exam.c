#include<stdio.h>
int main(){
    double  odd = 0;
    double  even = 0;
     int i,j;
     for ( i = 1; i <= 100; i = i+2)
     {
        odd = odd+(1.0/i);
     }
     for ( j = 2; j <= 100; j = j+2)
     {
        even = even+(1.0/j);
     } 
    printf("The value of series is: %lf\n",odd-even);
    return 0;
}