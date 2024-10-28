#include<stdio.h>
#include<stdlib.h>

void rev_elements(int k, int array[], int n);

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9};
    int k = 4;
    int n = sizeof(array)/sizeof(array[0]);
    int j = sizeof(array);

    printf("Main Elements:\n");
    int a = 0;
    while(array[a] < j){
        printf("%d ",array[a]);
        a++;
    }

    printf("\nAfter Reverse Elements:\n");
    rev_elements(k, array, n);

    int i=0;
    while(i<n){
       printf("%d ", array[i]);
       i++;
    }
    return 0;
}

void rev_elements(int k, int array[], int n){
    int head = n-k;
    int last = n-1;
    while (head < last)
    {
        int temp = array[head];
        array[head] = array[last];
        array[last] = temp;
        head++;
        last--;
    }
}
