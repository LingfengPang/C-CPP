#ifndef _STATICLIST_H
#define _STATICLIST_H
#include <stdbool.h>
/*静态链表s*/
#define MAXSIZE 100

typedef int ElemType;

typedef struct{
    ElemType data;
    int cur;//游标   
}Component,StaticLinkList[MAXSIZE];


bool InitList(StaticLinkList L);
bool ListEmpty(StaticLinkList L);
void ClearList(StaticLinkList L);
bool GetElem(StaticLinkList L,int i,ElemType *e);
bool LocateElem(StaticLinkList L,ElemType e);
bool ListInsert(StaticLinkList L,int i,ElemType e);
bool ListDelet(StaticLinkList L,int i);
int ListLength(StaticLinkList L);
void display(StaticLinkList L);
int Malloc_SLL(StaticLinkList L);//分配空间
void Free_SLL(StaticLinkList L,int k);




#endif