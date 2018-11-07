

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100


int evaluate(char *exp );

int main(int argc, const char * argv[]) {
    //简单9以内后缀表达式求解例子
    evaluate("123^+42/6*-");
    return 0;
}
char m_tolower( char c ){
    if( c >= 'A' && c <='Z' ) return 'a'+(c-'A');
    return c;
}
int int_abs(int v) {
    return  v>0?v:-v;
    
}
int evaluate( char *exp ) {
    float n_stack[MAX_SIZE];
    int top = -1;
    int op0,op1 ;
    for( int pos = 0 ; exp[pos] != '\0' ; pos++ ) {
        char op = exp[pos];
        if( isnumber(op) ) {
            n_stack[++top] = op - '0';
        }else {
            switch ( exp[pos] ) {
                case '+':
                {
                     op0 = n_stack[top--]; // 退
                     op1 = n_stack[top--];
                     n_stack[++top] = op1 + op0; // 相加后重新入的操作
                    break;
                }
                case '-':
                {
                    op0 = n_stack[top--]; // 退
                    op1 = n_stack[top--];
                    n_stack[++top] = op1 - op0; // 相加后重新入的操作
                    break;
                }
                case '*':
                {
                    op0 = n_stack[top--]; // 退
                    op1 = n_stack[top--];
                    n_stack[++top] = op1 * op0; // 相加后重新入的操作
                    break;
                }
                case '/':
                {
                    op0 = n_stack[top--]; // 退
                    op1 = n_stack[top--];
                    n_stack[++top] = op1 / (float)op0; // 相加后重新入的操作
                    break;
                }
                case '^':
                {
                    op0 = n_stack[top--];
                    op1 = n_stack[top--];
                    // res = op1^op0
                    float res = 1 ; //default 0 .比如op=0时
                    if( op1 == 0 ) return 0; //error
                    if( op0 != 0 ){
                        // 作乘方运算
                        for( int j = 0 ; j<int_abs(op0)   ; j++ ) {
                            res *= op1;
                        }
//                        if( op0 < 0  ) {
//                            // 指数为负数 ，本例子都是10以内的数字故先不考虑
//                            res = 1 / res;
//                        }
                    }
                    n_stack[++top] = res;  // 将结果压回
                    break;
                }
                default:
                {
                    return 0 ; //error
                    
                }
            }
        }
    }
    printf("res:%.2f\n",n_stack[top]);
    return 1;
    
}


