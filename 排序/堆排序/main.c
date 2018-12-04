
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100
/*
    yxy 2018
 */
void siftdown(int a[],int i,int n){
    int t = a[i];
    int j = 0 ;
    while (  (j= 2*i+1) <n ) {
        if( j<n-1 && a[j]<a[j+1] ) j++;// 选择较大的子树, 前提是 j《n-1 j+1存在
        if( t<a[j] ) {
            a[ (j-1)/2 ] = a[j];
            i = j;
        }else{
            break;// 已经是堆
        }
    }
    // 退出循环两种情况：t>=a[j] 或 （ j=2*i+1>=n 左子树不存在，即叶子节点）
    a[(j-1)/2] = t;
}
void heap_sort( int a[],int n ){
    int t ;
    // 初始化堆
    for( int i = (n-2)/2 ; i>=0; i--){
        siftdown(a, i, n);
    }
    for( int i = n-1;i>=0;i-- ){
        t = a[0];
        a[0] = a[i];
        a[i] = t ;
        // 把大的末尾
        siftdown(a, 0, i);
        // 逐渐缩小堆的大小，
    }
}

int main(int argc, const char * argv[]) {

    int a[9]= {2,0,9,5,56,1,200,88};
    heap_sort(a, 8);
    for( int i =0;i<8;i++)
        printf("%d ",a[i]);
    //0 1 2 5 9 56 88 200
    return 0;
}
