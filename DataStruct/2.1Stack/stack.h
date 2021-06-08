#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#define STACK_SIZE 100
typedef int ElemType;

typedef struct stack
{
    /* data */
    int content[STACK_SIZE];
    int top;
}Stack;

void init_Stack(Stack *s);
int length_Stack(Stack *s);
void make_empty(Stack *s);              
bool is_empty(Stack *s);
bool is_full(Stack *s);
//入栈
bool push(int e,Stack *s);
//出栈
bool GetTop(ElemType *e,Stack *s);
//读取栈顶数据
bool pop(ElemType *e,Stack *s);
#endif