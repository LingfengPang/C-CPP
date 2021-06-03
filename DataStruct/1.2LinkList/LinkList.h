#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <stdbool.h>



typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;   
}Node;
typedef struct Node *LinkList;



void CreatListHead(LinkList *L,int n);
void CreatListTail(LinkList *L,int n);
bool ListEmpty(LinkList L);
void ClearList(LinkList *L);
bool GetElem(LinkList L,int i,ElemType *e);
bool LocateElem(LinkList L,ElemType e);
bool ListInsert(LinkList *L,int i,ElemType e);
bool ListDelet(LinkList *L,int i,ElemType *e);
int ListLength(LinkList L);
void display(LinkList L);




#endif