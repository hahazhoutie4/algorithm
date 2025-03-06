#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int size = numsSize;
    int count=0;
    for(int a = 0 ;a<numsSize;a++){
        // nums[a]
        for(int b =numsSize-1;b>a;b--){
            if(nums[a]==nums[b]){
                nums[b]=nums[numsSize-1];
                numsSize--;
                count++;
            }
        }
    }
    return (size-count);
}

void main(){
    int nums[7]={1,2,3,4,3,5,3};
    int numsSize = 7;
    int res = removeDuplicates(nums,numsSize);
    printf("res:%d",res);
}