#ifndef LINKSTACK_H
#define LINKSTACK_H

#define STACK_SIZE 100
//typedef int ElemType;
typedef char ElemType;

typedef struct stacknode
{
    /* data */
    ElemType data;
    struct stacknode *next;
}StackNode,*LinkStackPtr;

// typedef struct LinkStack{
//     LinkStackPtr top;
//     int count;
// }LinkStack;

void init_Stack(LinkStackPtr *S);
//int length_Stack(LinkStack *S);
// void make_empty;             
bool is_empty(LinkStackPtr *S);
//入栈
bool push(ElemType e,LinkStackPtr *S);
//读取栈顶数据
bool GetTop(ElemType *e,LinkStackPtr *S);
//出栈
bool pop(ElemType *e,LinkStackPtr *S);
//void RPN(char *str, char *result);


#endif