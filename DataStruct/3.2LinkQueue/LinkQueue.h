#ifndef LINKQUEUE_H
#define LINKQUEUE_H
//这个队列木有头节点

typedef int ElemType;

typedef struct QNode
{
    /* data */
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct 
{
    /* data */
    QueuePtr front,rear;
    int length;
}LinkQueue;



void init_LinkQueue(LinkQueue *q);


int length_LinkQueue(LinkQueue *q);
void make_empty(LinkQueue *q);           

bool is_empty(LinkQueue *q);
//进入队列
bool enQueue(ElemType e,LinkQueue *q);
//出栈
bool GetHead(ElemType *e,LinkQueue *q);

//出队列
bool deQueue(ElemType *e,LinkQueue *q);
bool enQueueTail(ElemType e,LinkQueue *q);
bool deQueueHead(ElemType *e,LinkQueue *q);
#endif