#include<stdio.h>
int main(){
   int i,j,x;
   printf("Enter a positive number between 1 to 9: ");
   scanf("%d",&x);
   for ( i = 1; i <= x; i++)
   {
    for ( j = 1; j <= i; j++)
    {
        printf("%d*%d=%d\t",j,i,(i*j));
    }
    printf("\n");
   }
   
    return 0;
}