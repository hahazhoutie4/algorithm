#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p1;
    int nums1[]= {4, 5, 6, 0, 0, 0};
    int nums1Size = 3;
    int m = 3;
    int nums2[] = {1, 2, 3};
    int *p2;
    int nums2Size = 3;
    int n = 3;
    p1=nums1;
    p2=nums2;
    int *num_r = (int *)malloc(sizeof(nums1)/sizeof(nums1[0]) + sizeof(nums2)/sizeof(nums2[0]));
    p1 +=m;
    int s;
    for (s = 0; s < n; s++)
    {
        *(p1 + s) = *(p2 + s);
    }
    p1-=m;
    num_r = p1;
    int size = m + n;
    for(int c =0;c<size;c++){
        printf("输出%d\n",*(num_r++));
        
    }
    printf("输出%d\n",*(num_r-=size));
    for (int a = 0; a < size; a++)
    {
        for (int b = 0; b < size - a -1; b++)
        {
            int temp;
            printf("num_r :%d, num_r+1:%d\n",*num_r,*(num_r+1));
            if ((*num_r) > *(num_r + 1))
            {
                temp = *num_r;
                *num_r = *(num_r + 1);
                *(num_r + 1) = temp;
            }
            num_r++;
            
        }
        printf("----\n");
        num_r = num_r - (size -a-1);
    }
}