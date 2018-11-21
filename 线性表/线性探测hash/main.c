
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 4
/*
 t[i] == 0 -> 空位置
 t[i] == -1 -->被删除
 */
int table[MAX_SIZE];
void init(){
    for( int i = 0 ; i<MAX_SIZE ; i++ ){
        table[i] = 0;
    }
}
int hash(int x) {
    return x % MAX_SIZE;
}
int search(int t[],int k ){
    int pos = hash(k);// 基础坐标
    int i =0 ;// 偏移坐标
    for( i=0;i<MAX_SIZE && table[ (pos+i) % MAX_SIZE ]!=k && table[ (pos+i) % MAX_SIZE ]!=0  ;i++);
    int findi =(pos+i) % MAX_SIZE;
    if( table[findi] == k ){
        return findi;
    }
    return -1;
}
int insert(int t[] ,int k )  {
    int pos = hash(k);
    int i = 0;
    for(  i = 0 ; i<MAX_SIZE && table[(pos+i) % MAX_SIZE ] >0 && table[(pos+i) % MAX_SIZE]!=k;i++ );
    // 没到末尾。 不是空位，不是本键值 就一直找
    if( table[(pos+i) % MAX_SIZE] <=0 ) {
        t[(pos+i) % MAX_SIZE] = k;
        return 0;
    }
    return 1;
}
int delete(int t[],int k ) {
  
    int i = search(t, k);
    if( i >=0 ) {
        t[i] = -1;
        return 0 ;
    }
    return 1;
}
void print(){
    for( int i = 0 ;i< MAX_SIZE;i++){
        printf("%d",table[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    init();
    
    insert(table, 1);

    print();
    
    insert(table, 5);
    print();
    int i = search(table, 1);
    int j =search(table, 5);
    printf("%d %d\n",i,j);
    
    
    
    return 0;
}
