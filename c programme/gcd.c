#include<stdio.h>
int main(){
    int a,b,x,t,gcd;
    scanf("%d %d",&a,&b);
    if(a==0) gcd = a;
    else if (b == 0) gcd = b;
    else{
        while(b!=0){
            t = b;
            b = a%b;
            a = t;
        }
        gcd = a;
    }
    printf("GCD is: %d\n",gcd);

    // int a = 5, b = 10;
    // printf("a percent b= %d\n",a%b);
    // printf("b percent a= %d",b%a);

    return 0;
}