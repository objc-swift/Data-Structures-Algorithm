

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100

int pow_cur_char (char c)
{
    switch (c) {
        case '^':
            return 4;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
    return -2;
}

int pow_stack_char (char c)
{
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        case '$':
            return -1;
    }
    return -2;
}

int main(int argc, const char * argv[]) {
    // 中缀 后缀数字的顺序不变
    char res[100];
    mid_to_pre("a*b+c*q*(d+c)", res);
    printf("%s\n",res);
    
    return 0;
}

int mid_to_pre( char mid[],char res[] ) {
    char stack[MAX_SIZE];
    int top = -1 ;
    stack[++top] = '$' ;
    int mi = 0 ;
    int ri = 0 ;
    while ( mid[mi] !='\0' ) {
        if( islower( mid[mi]) ) {
            res[ri++] = mid[mi];
        }else
        {
            switch ( mid[mi] ) {
                case '+':
                case '-':
                case '*':
                case '/':
                {
                    while ( pow_cur_char( mid[mi] ) <= pow_stack_char( stack[top] ) ) {
                    // 优先级高的先出（优先级高的先计算）
                        res[ri++] = stack[top--];
                    }
                // 此时 mid[mi] > stack[top],元素越靠近栈顶越先出栈，入
                    stack[++top] = mid[mi];
                    break;
                }
                case '(':
                    // 遇到左括号无条件先算
                    stack[++top] = mid[mi];
                    break;
                case ')':
                {
                    // 弹出（ 后的所有符号
                    while (stack[top] !='(' ) {
                        res[ri++]=stack[top--];
                    }
                    top--;
                    break;
                }
            }
        }
        mi++;
    }
    // 上面 while 结束 说明遇到 /0 （类似右括号）
    while (top>0) {
        res[ri++] = stack[top--];
    }
    res[ri]='\0';
    return 1;
}


