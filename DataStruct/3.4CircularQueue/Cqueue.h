#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct queue
{
    /* data */
    ElemType content[MAXSIZE];
    int front;
    int rear;//头指针和尾指针
    int length;
}SqQueue;


void init_SqQueue(SqQueue *q);
void destroy_SqQueue(SqQueue *q);
int length_SqQueue(SqQueue *q);
void make_empty(SqQueue *q);                  
bool is_empty(SqQueue *q);
bool is_full(SqQueue *q);
//进入队列
bool enQueue(ElemType e,SqQueue *q);
//出栈
bool GetHead(ElemType *e,SqQueue *q);
//出队列
bool deQueue(ElemType *e,SqQueue *q);


