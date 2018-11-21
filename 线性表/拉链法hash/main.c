
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 5
typedef struct node{
    struct node * link;
    int value ;
    int key
}node;

/*
 t[i] == 0 -> 空位置
 t[i] == -1 -->被删除
 */
int hash( int k  ) {
    return k % MAX_SIZE;
}
node *table[MAX_SIZE];
void search( node* t[],int k ,node* *pre ,node* *cur) {
    int pos = hash(k);
    /*
        前驱是指针还是节点？
     */
    *pre = NULL;
    *cur = t[pos];
    while ( *cur !=NULL ) {
        if( (*cur)->key == k ) return ; // 找到了
        else {
            *pre = *cur;
            *cur = (*cur)->link;
        }
    }
}
int insert( node *t[] , int k ,int value  ) {
    int pos = hash(k);
    node *pre,*cur ;
    search(t, k, &pre, &cur);
    if( cur == NULL ) {
        // 尚未找到，说明表里没这个键
        node * new_n =  (node *) malloc(sizeof(node));
        new_n->key = k;
        new_n->value = value;
        new_n->link = NULL;
        if( pre == NULL ) //
            t[pos] = new_n;
        else
            pre->link = new_n;
        return 0 ;
    }
    return 1; // 找到了，不需要插入
}
int delete(node *t[],int k ){
    node *pre,*cur ;
    int pos = hash(k);
    search(t, k, &pre, &cur);
    if( cur == NULL ) return 1; // 没有这个节点
    if( pre == NULL ) {
        t[pos] = cur->link;
    }else{
        pre->link = cur->link;
    }
    free(cur);
    return 0;
}
int main(int argc, const char * argv[]) {
  
    insert(table, 1, 1000);
    insert(table, 1, 200);
    insert(table, 5, 200);
    insert(table, 10, 300);
    insert(table, 6, 23);
    node *pre ,*cur ;
    search(table, 1, &pre, &cur);
    printf("key:%d value:%d\n",cur->key,cur->value);
    search(table, 5, &pre, &cur);
    printf("key:%d value:%d\n",cur->key,cur->value);
    search(table, 10, &pre, &cur);
    printf("key:%d value:%d\n",cur->key,cur->value);
    search(table, 6, &pre, &cur);
    printf("key:%d value:%d\n",cur->key,cur->value);
    insert(table, 1000, 10087);
    search(table, 1000, &pre, &cur);
    printf("key:%d value:%d\n",cur->key,cur->value);
    /*
     输出
     key:1 value:1000
     key:5 value:200
     key:10 value:300
     key:6 value:23
     key:1000 value:10087
     */
    return 0;
}
