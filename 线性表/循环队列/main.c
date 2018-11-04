//
//  main.c
//  DSProject
//
//  Created by yxyyxy on 02/11/2018.
//  Copyright © 2018 yxy. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 7
int queue[MAX_SIZE];
int head = 0 ,tail = 0 ;
// 对head tail 的定义
// head 为最近一次已出队元素的下标
// head +1 为当前队头 （若有）
// tail 队尾元素的下标

//入队时：
//先将tail+1
// 此时若head=i ,则 元素i 已经出队，元素i 后面的一个元素i_next 尚未出队(此时为队头) (i_next = (i+1) % MAX_SIZE )
// (tail == head == i)  -->tail 即将追上当前队头 i_next ，队满了
//出队时：
// (head == tail) --> 最近一次已出队元素的下标 是队尾元素的下标 --> 最近一次已出队元素是队尾的元素 --> 队空了
int en_queue(int value ) ;
int de_queue(int *resPtr ) ;

int main(int argc, const char * argv[]) {

    for(int i = 0 ;i <10;i++) {
        if( !en_queue(i) ){
            printf(" %d 失败，队满了\n",i);
        }
        
    }
    int res ;
    de_queue(&res);
    printf("%d\n",res);
    de_queue(&res);
    printf("%d\n",res);
    en_queue(10);
    
    return 0;
}

int en_queue(int value ){
    tail = ( tail+1 ) % MAX_SIZE; // 要入新元素，末尾元素下标+1
    if( tail == head ){
        // 队满了
        if( tail == 0  ) tail = MAX_SIZE-1;
            else
                tail--;
        return 0;
    }
    queue[tail] =value;
    return 1;
}

int de_queue(int *resPtr ) {
    if( head == tail ){
        return 0;
    }
    head = (head +1) % MAX_SIZE;
    *resPtr =  queue[head];
    return 1;
    
}
