//
//  main.c
//  DSProject
//
//  Created by yxyyxy on 02/11/2018.
//  Copyright © 2018 yxy. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 100
// 插入
int sq_insert(int *list ,int * count,int pos ,int value) {
    if( pos < 0 || pos > *count ) return 1; // 1 判断插入位置是否合法
    if( *count == MAX_SIZE ) return 2; // 2 判断顺序表是已满
    for( int j =*count; j>pos ; j--  ) { // 生成[*conut ~ pos+1]的下标
        // 3.后移挪出位置
        list[j] = list[j-1];
    }
    list[pos] = value; // 4 插入
    (*count)++; // 5 长度+1
    return 0;
}
// 删除
int sq_delete(int *list ,int *count,int pos ) {
    if( pos <0 || pos >=*count ) return 1 ; // 1 合法性判断 (删除的时候下标对应的元素必须存在，所以这里 pos >=*p_n)
    for( int j = pos+1;j <*count ; j ++) { // 生成[pos+1,*count)的下标
        list[j-1] = list[j]; // 2 覆盖
    }
    (*count)--; // 3总数减少
    return 0;
}

// 容易发现，插入和删除的主循环都是生成[pos+1,*count]范围内的坐标，删除的pos对应的元素必须存在，所以循环的范围是 [pos+1,*count)

int main(int argc, const char * argv[]) {
    // insert code here...
    int list[MAX_SIZE] = {1,2,3,4,5,6};
    int pn = 6;
    
    int res = sq_insert(list, &pn, 1, 99);
    int res1 = sq_insert(list, &pn, 3, 88);
    int res2 = sq_delete(list, &pn, 1);
    int res3 = sq_delete(list, &pn, 3);
    
    printf("Hello, World!\n");
    
    return 0;
}


