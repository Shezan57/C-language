#include<stdio.h>
int main(){
    int nums1[3]={1,2,3};
    int nums2[3]={1,2,3};
    int nums3[3];
    int size_nums1 = sizeof(nums1)/sizeof(nums1[0]);
    int size_nums2 = sizeof(nums2)/sizeof(nums2[0]);
    int size_nums3 = sizeof(nums3)/sizeof(nums3[0]);
    if(size_nums1 != size_nums2 || size_nums1 != size_nums3){
        return 0;
    }
    int i;
    for(i=0; i<size_nums1; i++){
        nums3[i] = nums1[i] + nums2[i];
    }
    for(i=0; i<size_nums1; i++){
            printf("%d\t",nums3[i]);

    }
    return 0;

}