#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdbool.h>
typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prev;
    struct DNode *next;
}DNode, *DLinkList;

void CreatDlistHead(DLinkList *l,int n);//头插法
void CreatDlistTail(DLinkList *l,int n);//尾插法
void DlistInsert(DLinkList *l,int i,ElemType e);//插入数据
void DlistDel(DLinkList *l,int i,ElemType *e);//插入数据

#endif