
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100

typedef struct node {
    struct node * next ;
    char data ;
} node ;


void echo_list( node * head  )
{
    node *p = head;
    while ( p!=NULL ) {
        printf("%c",p->data);
        p = p->next;
    }
    printf("\n");
}
node * create_list(int size ){
    if( size == 0 ) return NULL;
    node * head = (node *) malloc(sizeof(node));
    node *p = head;
    scanf("%c",&p->data);
    // 从缓冲区里读取字符，一次一个，注意：%d读到空格或回车
    for( int i = 1;i <size ;i++ ) {
        node *now = (node *) malloc(sizeof(node));
        p->next = now;
        p = now;
        scanf("%c",& (p->data));
    }
    p->next  = NULL;
    return head;
}
void insert( node* *head ,char after_this_data , char data ) {
    node *p = *head;
    node *new_data = (node *)malloc(sizeof(node));
    new_data->data = data;
    new_data->next = NULL;
    if( p == NULL ){
        *head = new_data;
        return;
    }
    while ( p->next !=NULL && p->data != after_this_data) {
        // 不为最后一个节点，且不为目标节点
        p = p->next;
    }
    new_data->next =p->next;
    p->next = new_data;
}

int delete(node* *head ,char data) {
    node *q,*p ;
    p = NULL;
    q = *head;
    if( q->data == data ){
        *head = q->next;
        free(q);
        return 0;
    }else {
        while ( q->data != data && q ->next !=NULL){
            p = q; // 移动前备份
            q = q->next;// 先走一步
        }
        // 走到这一步，说明q->data == data 或q是最后一个元素了
        if( q->data == data ) {
            p->next = q->next;
            free(q);
            return 0;
        }else {
            return 1;
        }
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    // 链表
    node *head =   create_list(6);
    echo_list(head);
    insert(&head, 'c','l');
    insert(&head, 'o','f');
    echo_list(head);
    delete(&head, 'c');
    echo_list(head);
    return 0;
}
