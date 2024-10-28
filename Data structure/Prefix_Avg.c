#include<stdio.h>
#define SIZE 10

void prefix_avg(int*,int*);
int main(){
    int arr[] = {11,12,13,14,15,16,17,18,19,20};
    int preArr[SIZE],i,j,k;
    prefix_avg(arr,preArr);
    printf("Araay Elements                Average\n");
    printf("=====================================\n");
    for (i=0; i<10; i++){

        for(j=0; j<=i; j++){
            printf("%d ", arr[j]);
        }
        for(k=10; k>j; k--){
            printf("   ");
        }
        printf(" : %d\n",preArr[i]);
    }
    return 0;
}

void prefix_avg(int* arr, int* preArr){
    int sum = 0;
    for(int i=0; i<SIZE; i++){
        sum += arr[i];
        preArr[i] = sum / (i+1);
    }
}