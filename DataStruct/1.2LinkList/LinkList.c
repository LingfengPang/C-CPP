#include "LinkList.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>

//建立带头节点的链表L(头插法)L最后指向最后一个数据
//L ->  ai - >  ai-1 ->  ai-2 ......   a1
void CreatListHead(LinkList *L,int n){
    LinkList p;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;//*L是二级指针，*的运算顺序没有->高
    for(i = 0;i<n;i++){
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->next=(*L)->next;
        (*L)->next=p;
    }
}
//尾插法创建链表（常用）
void CreatListTail(LinkList *L,int n){
    LinkList p,r;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    r=*L;
    for(i = 0;i<n;i++){
        p=(Node*)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->next=p;
        r=p;//r指向下一个节点
    }
    r->next = NULL;
}
bool ListEmpty(LinkList L){
    bool flag = true;
    if(L->next!=NULL){
        flag = false;
        printf("exist!\n");
    }
    return false;
    //return (L->data==NULL);

}
void ClearList(LinkList *L){
    LinkList p,q;
    p=(*L)->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
}
//读取第i位置的元素
bool GetElem(LinkList L,int i,ElemType *e){
    int j;
    LinkList p;
    p = L->next;//p指向L的第一个节点
    j = 1;
    while(p&&j<i){
        p = p->next;
        j++;
    }

    if(!p||j>i)//p
        return false;
    *e = p->data;
    return true;
    
}
//查找是否有元素e
bool LocateElem(LinkList L,ElemType e){
    int j;
    LinkList p;
    bool flag=false;
    p = L->next;//p指向L的第一个节点
    j = 1;
    while(p){
        if(p->data==e)
            flag = true;
        p = p->next;
        j++;
    }

    if(!p)//p
        return false;

    return flag;
}
//在第i个位置
bool ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p = *L;//p指向L的第一个节点
    j = 1;
    while(p&&j<i){
        p = p->next;
        j++;
    }

    if(!p||j>i)//p
        return false;
    s =(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next = s;
    return true;
}
//删除第i个位置
bool ListDelet(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,s;
    p = *L;//p指向L的第一个节点
    j = 1;
    while(p&&j<i){
        p = p->next;
        j++;
    }

    if(!p||j>i)//p
        return false;
    s=p->next;
    p->next=s->next;
    free(s);
    return true;
}
int ListLength(LinkList L){
    LinkList p;
    int j;
    if(!L)
        return 0;
    p = L->next;//p指向L的第一个节点
    j = 1;
    while(p){
        p = p->next;
        j++;
    }
    return j-1;

}
void display(LinkList L){
    LinkList p;
    int j;
    p = L->next;//p指向L的第一个节点
    j = 1;
    while(p){
        printf("%d ",p->data);
        p = p->next;
        j++;
    }
    printf("\n");
    
}

int main(){
    LinkList La;
    ElemType e;
    bool flag;
    CreatListTail(&La,5);   
    display(La);
     e = ListLength(La);
    printf("La's length is %d\n",e);
    flag = ListEmpty(La);
    if(flag == false){
        printf("La is not empty!\n");
    }
//void ClearList(SqList *L);
    GetElem(La,1,&e);
    printf("the first data of La is :%d \n",e);
    LocateElem(La,1);//exist!

    ListInsert(&La,6,10);
    display(La);
    ListDelet(&La,1,&e);
    printf("%d \n",e);
    display(La);
    e = ListLength(La);
    printf("La's length is %d\n",e);
    ClearList(&La);true;
    flag = ListEmpty(La);
    if(flag == true){
        printf("La is empty!\n");
    }

    system("pause");
    return 0;


}
