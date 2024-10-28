#include<stdio.h>
int main(){
    int nums[ ]={3,5,999,-2,-12};
    int i;
    int maxx = 0;
    for(i=0; i<5; i++){
       if( nums[i] > maxx){
        maxx = nums[i];
        }
    }
    int maxsum=0;
    for(int i=0; i<5; i++){
        maxsum = maxsum + nums[i];
        if(maxsum<0){
            maxsum=0;
        }
    }
    if(maxsum<0){
        printf("The sum is 0");
    } 
    printf("The maximum value is %d\n",maxx);
    printf("The Sum is %d",maxsum);
    return 0;
}