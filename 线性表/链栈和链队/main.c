
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100
/*
 
 更改某块内存的方法
 node *p_new = (node *)malloc(sizeof(node));
 node k;
 k.data = 'p';
 *p_new = k;
 printf("%c", (*p_new).data);
 
 */
typedef struct node{
    char data;
    struct node * next;
}node;
node *head,*tail; // 偷懒直接这样写了，不写链栈那么复杂

void push (node* *out,char data) {
    node *p_new = (node *)malloc(sizeof(node));
    p_new->data = data;
    if( *(out) == NULL){
        *out = p_new;
        return;
    }
    node *top = *out;
    p_new ->next = top; // 前插法
    *out = p_new;
}
int  pop(node* *out_top ,char *data) {
    
    if( *out_top == NULL ) return 0;
    node* top = *out_top; //  备份顶
    *data = top->data; // 取出顶部数据
    *out_top = top->next; // 外部top前移
    free(top);// 释放头
    return 1;
}

void en_queue(char data) {
    node *p_new = (node *)malloc(sizeof(node));
    p_new->data =data;
    p_new->next = NULL ;
    if( head == NULL ) {
        head = p_new;
    }else {
        tail->next = p_new;
    }
    tail = p_new;
}

int de_queque( char *data ){
    if( head == NULL ) {
        return 0 ;
    }
    *data = head->data;
    node * p = head;
    head = head->next;
    free(p);
    return 1;
    
}
int main(int argc, const char * argv[]) {

    // 栈操作
    node *top = NULL ;
    push(&top, 'a');
    push(&top, 'b');
    push(&top, 'c');
    char x ;
    pop(&top, &x);
    printf("%c\n",x); // c
    pop(&top, &x);
    printf("%c\n",x); //b
    push(&top, 'f');
    push(&top, 'd');
    pop(&top, &x);
    printf("%c\n",x);//d
    pop(&top, &x);
    printf("%c\n",x);//f
    
    printf("queue\n");
    
    head = NULL;
    en_queue('a');
    en_queue('b');
    en_queue('c');
    de_queque(&x);
    printf("%c\n",x);//a
    de_queque(&x);
    printf("%c\n",x);//b
    en_queue('g');
    de_queque(&x);
    printf("%c\n",x);//c
    de_queque(&x);
    printf("%c\n",x);//g
    
    return 0;
}
