#include "LinkList.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>

//建立带头节点的链表L(头插法)L最后指向最后一个数据
//L ->  ai - >  ai-1 ->  ai-2 ......   a1
// void CreatListHead(LinkList *L,int n){
//     LinkList p;
//     int i;
//     srand(time(0));
//     *L=(LinkList)malloc(sizeof(Node));
//     (*L)->next=NULL;//*L是二级指针，*的运算顺序没有->高
//     for(i = 0;i<n;i++){
//         p=(LinkList)malloc(sizeof(Node));
//         p->data=rand()%100+1;
//         p->next=(*L)->next;
//         (*L)->next=p;
//     }
// }
//尾插法创建链表（常用）
void CreatListTail(LinkList *L,int n){
    LinkList p,r;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    r=*L;
    for(i = 0;i<5;i++){
        p=(Node*)malloc(sizeof(Node));
        p->data=i+1;
        r->next=p;
        r=p;//r指向下一个节点
    }
    r->next = *L;//最后一个指向头指针
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
    while(p != *L){//当P指向头指针时
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
    while(p!=L&&j<i){
        p = p->next;
        j++;
    }

    if(p==L||j>i)//p
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
    while(p!=L){
        if(p->data==e)
            flag = true;
        p = p->next;
        j++;
    }

    if(p==L)//p
        return false;

    return flag;
}
//在第i个位置i=6
bool ListInsert(LinkList *L,int i,ElemType e){
    int j;
    LinkList p,s;
    p = *L;//p指向L的第一个节点
    j = 1;
    while(p->next!=*L&&j<i&&p){
        p = p->next;
        j++;
    }

    if(p==*L||j>i)//p
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
    while(p->next!=*L&&j<i&&p){
        p = p->next;
        j++;
    }

    if(p==*L||j>i)//p
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
    while(p!=L){
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
    while(p!=L){
        printf("%d ",p->data);
        p = p->next;
        j++;
    }
    printf("\n");
    
}
//报数游戏
//i:第几个开始报
//报到 e的删除
bool game(int index,ElemType e,LinkList *L){
    int i;
    LinkList p;
    p = *L;
    int len,temp;
    len = ListLength(*L);
    bool flag = false;
    printf("Len is %d\n",len);
    if(!p||index>len)
        return false;
    
    for(i=0;i<index;i++){
        p = p->next;
    }

    for(i = 1;i<=len;i++){
        if(p->data == e){
            flag = true;
            ListDelet(L,(i+index)%len,&temp);
            break;
        }
        p = p->next;
        if(p == *L){
            p = (*L)->next;
        }
    }
    return flag;

}

// bool ListEmpty(LinkList L);
// void ClearList(LinkList *L);
// bool LocateElem(LinkList L,ElemType e);
// bool ListInsert(LinkList *L,int i,ElemType e);
// bool ListDelet(LinkList *L,int i,ElemType *e);
// int ListLength(LinkList L);
// void display(LinkList L);
/*圆桌报数程序*/
int main(){
    bool flag;
    LinkList L;
    int e = 2;
    CreatListTail(&L,5);
    ListEmpty(L);
    GetElem(L,3,&e);
    printf("e = %d\n",e);
    ListInsert(&L,6,6);
    display(L);
    flag = LocateElem(L,3);
    if(flag)
        printf("3 exist!\n");
    game(3,2,&L);
    display(L);

    system("pause");
    return 0;


}
