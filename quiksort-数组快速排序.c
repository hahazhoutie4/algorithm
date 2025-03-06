#include <stdio.h>
#include <stdlib.h>
#define pp(p,r) printf("指针地址:%p  %p 指针空间: %d\r\n",p,r,r-p)
#define pf(a,b,c) printf("打印内容:%d  %d  %d\r\n",a,b,c);
void sort(int* left,int*right,int size);
void sort(int* left,int*right,int size){
    if(size<=1){
 //       printf("退出循环\r\n");
        return;
    }
    int* left_region =left;
    int* right_region = right;
//    pp(left,right); //打印原始指针位置，相差7个字节，空间为8个字节
    int index = *left;  //基准左值23
    int flag=0;  //0为右比较，1为左比较
    for(int a =0;a<size;a++){
        if(left==right){
            *left =index;
            break;}
        if(!flag){
            if(*right<index){
                *left=*right;
                left++;
                flag=1;
            }else{
                right--;
            }
        }else{
        if(*left>index){
            *right = *left;
            right--;
            flag = 0;
        }else{
                left++;
        }
        }
    }
    int l_siz = left -left_region;      //1
    int r_size = right_region - left;  //3
    // pf(l_siz,r_size,0);
    // pp(left_region,left);
    // pp(left,right_region);
//    printf("l_siz:%d,r_size:%d\r\n",l_siz,r_size);
    sort(left_region,left-1,l_siz);
    sort(left+1,right_region,r_size);
}

int main(){
    int af[] ={100,95,75,48,36,52,98,42,3,5,447,52,1598,464,13,46,79,46,13,46,749,16,18};
    int size = sizeof(af)/sizeof(int);
    printf("数组个数:%d\r\n",size);
    printf("排序前:\r\n");
    for(int a = 0 ;a<size ; a++){
        printf("%d ",af[a]);
    }
     printf("\r\n");
    sort(af,&af[size-1],size);
    printf("排序后:\r\n");
    for(int a = 0 ;a<size ; a++){
        printf("%d ",af[a]);
    }
    printf("\r\n");
    return 0;
}