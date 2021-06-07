#ifndef _ORDERLIST_H
#define _ORDERLIST_H
#include <stdbool.h>



typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;   
}Node;
typedef struct Node *OrderList;



void CreatListTail(OrderList *L,int n);
bool ListEmpty(OrderList L);
void ClearList(OrderList *L);
bool GetElem(OrderList L,int i,ElemType *e);
bool LocateElem(OrderList L,ElemType e);
bool ListInsert(OrderList *L,ElemType e);
bool ListDelet(OrderList *L,int i,ElemType *e);
int ListLength(OrderList L);
void display(OrderList L);




#endif