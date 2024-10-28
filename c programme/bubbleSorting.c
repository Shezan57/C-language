#include<stdio.h>
int main(){
    int a[5]={5,3,6,7,9};
    int i,j,t,size=5,swap,count=0;
    for(i=0; i<size-1; i++){
        swap=0;
        for(j=0; j<size-1; j++){
            count++;
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                swap=1;
            }
        }
        if(swap==0){
            break;
        }
    }
    printf("\nAfter sorting:\n");
    for(i=0; i<size; i++){
        printf("%d \t",a[i]);
    }
    printf("\n Total loop: %d",count);
    return 0;
}