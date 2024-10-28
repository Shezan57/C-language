#include<stdio.h>
int main(){
    int nums[ ]={3,5,999,2,12};
    int i;
    int maxx = 0;
    for(i=0; i<5; i++){
       if( nums[i] > maxx){
        maxx = nums[i];
        }
    }
    printf("max is %d\n",maxx);
    return 0;
}