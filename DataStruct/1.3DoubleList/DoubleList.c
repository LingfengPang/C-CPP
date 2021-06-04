#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include "DoubleList.h"

void CreatDlistHead(DLinkList *l,int n){
    DLinkList p;
    int i;
    *l = (DLinkList)malloc(sizeof(DNode));
    (*l) -> next = NULL;
    for(int i = 0;i<n;i++){
        p = (DLinkList)malloc(sizeof(DNode));
        p->data = i;
        p->next = (*l) ->next;
        if((*l)->next!=NULL)
            (*l)->next->prev = p; 
        (*l)->next = p;
        p->prev = *l;
        
    }
    
}
void CreatDlistTail(DLinkList *l,int n){
    DLinkList p,r;
    int i;
    *l = (DLinkList)malloc(sizeof(DNode));
    (*l) -> next = NULL;
    r = *l;
    for(int i = 0;i<n;i++){
        p = (DLinkList)malloc(sizeof(DNode));
        p->data = i;
        r->next = p;
        p->next = r;
        r = p;
    }
    r->next = NULL;

}
void DlistInsert(DLinkList *l,int i,ElemType e){
    DLinkList p,r;
    r = *l;
    int j = 0;
    while(j<i-1 && r!=NULL){
        r = r->next;
        j++;
    }
    if(r == NULL)
        return;
    p = p = (DLinkList)malloc(sizeof(DNode));
    p -> data = e;
    p -> next = r -> next;
    if(p->next!=NULL)
       p->next->prev = p; 
    p -> prev = r;
    r -> next = p;

}//在第i个位置插入数据

void DlistDel(DLinkList *l,int i,ElemType *e){
    DLinkList p,r;
    *e = 0;
    r = *l;
    int j = 0;
    while(j<i-1 && r!=NULL){
        r = r->next;
        j++;
    }
    if(r == NULL || r->next ==NULL || r->next->next == NULL)
        return;
    p = r->next;
    *e = p->data;
    r->next = p->next;
    r->next->prev = r;
    free(p); 

}//在第i个位置插入数据
void printlist(DLinkList l){
    DLinkList p;
    p = l->next;
    while (p)
    {
        /* code */
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    DLinkList l1,l2;
    int e;
    CreatDlistHead(&l1,5);
    CreatDlistTail(&l2,5);

    printlist(l1);
    printlist(l2);
    DlistInsert(&l2,3,6);
    printlist(l2);
    DlistDel(&l1,2,&e);
    printlist(l1);
    printf("%d\n",e);
    system("pause");
    return 0;
}
