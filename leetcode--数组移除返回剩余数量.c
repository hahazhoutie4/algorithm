#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int *p=(int*)malloc(sizeof(nums));
    int count = 0;    
    for(int a = 0 ;a<numsSize ;a++){
        if(*nums==val){
            count++;
        }else{
        *p=*nums;
        p++;
        }
        nums++;
    }
    // p=p-(numsSize-count);
    p--;
    int sum = numsSize-count;
    for(int c = sum ;c>0;c--){
        printf("res:%d\n",*p--);
    }
    return sum;
}

int main(){
        int nums[] ={6,5,4,2,3,4,3,2,2,3};
        int numsSize = 9;
        int val = 3;
        int result = removeElement(nums,4,3);
        printf("%d",result);
}

