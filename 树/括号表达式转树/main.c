
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100
typedef struct node {
    struct node *child[MAX_SIZE];
    char data;
}node ;
node * bracketToTree( char *ch_str  ) {
    int i = 0 ;
    node *p = NULL ;
    node *q = NULL;
    node *stack[MAX_SIZE];
    int top = 0;
    char ch;
    while (  (ch = ch_str[i] ) !='\0' ) {
        if( isalpha(ch) ){
            p  = (node *)malloc(sizeof(node));
            p->data = ch;
            for(int i = 0 ;i<MAX_SIZE ;i++){
                p->child[i] = NULL;
            }
        }else {
            switch (ch) {
                case '(':
                {
                    stack[top++]=p;
                    break;
                }
                case ',':
                {
                    int i = -1 ;
                    q = stack[top-1]; // 不退
                    while (q->child[++i]!=NULL);
                    q->child[i] = p;
                    break;
                }
                case ')':
                {
                    int i = -1 ;
                    q=stack[--top]; // 退
                    while (q->child[++i]!=NULL);
                    q->child[i] = p; // 新的p
                    p=q;
                    break;
                }
            }
        }
        i++;
    }
    return p;
}


void bfs_tree(node * t){
    node* queue[MAX_SIZE];
    int head =0 ,tail=0;
    queue[tail++] = t;
    while (head < tail) {
        node *h = queue[head++];
        printf("%c ",h->data);
        for(int i =0 ; i < MAX_SIZE;i++){
            if( h->child[i]!=NULL ) {
                queue[tail++] = h->child[i];
            }
        }
    }
    printf("\n");
    
    
}
int main(int argc, const char * argv[]) {
    node *t = bracketToTree("C(D(G,B,H(Z)),E(F,C))");
    bfs_tree(t); // output: C D E G B H F C Z
    
   
    return 0;
}
