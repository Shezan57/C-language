#include<stdio.h>
int main(){
    int i = 0;
    int sum = 0;
    while (i<=100)
    {
        if(i%2==0){
            continue;
        }
        sum+=i;
        i++;
    }
    printf("The sum of all even number between 0 and 100 is= %d",sum);
    


    return 0;
}