#ifndef _SQLIST_H
#define _SQLIST_H
#include <stdbool.h>

#define MAXSIZE 20


typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

void InitList(SqList *L);
bool ListEmpty(SqList L);
void ClearList(SqList *L);
bool GetElem(SqList L,int i,ElemType *e);
bool LocateElem(SqList L,ElemType e);
bool ListInsert(SqList *L,int i,ElemType e);
bool ListDelet(SqList *L,int i,ElemType *e);
int ListLength(SqList L);
void unioL(SqList *La,SqList Lb);//线性表AUB
void display(SqList L);




#endif