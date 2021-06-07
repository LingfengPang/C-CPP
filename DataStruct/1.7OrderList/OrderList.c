#include "OrderList.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>


//尾插法创建链表（常用）//按升序排列
void CreatListTail(OrderList *L,int n){
    OrderList p,r;
    int i;
    *L=(OrderList)malloc(sizeof(Node));
    r=*L;
    for(i = 0;i<n;i++){
        p=(Node*)malloc(sizeof(Node));
        p->data=i;
        r->next=p;
        r=p;//r指向下一个节点
    }
    r->next = NULL;
}
bool ListEmpty(OrderList L){
    bool flag = true;
    if(L->next!=NULL){
        flag = false;
        printf("exist!\n");
    }
    return false;
    //return (L->data==NULL);

}
void ClearList(OrderList *L){
    OrderList p,q;
    p=(*L)->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
}
//读取第i位置的元素
bool GetElem(OrderList L,int i,ElemType *e){
    int j;
    OrderList p;
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
bool LocateElem(OrderList L,ElemType e){
    int j;
    OrderList p;
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
//插入元素e
bool ListInsert(OrderList *L,ElemType e){
    int j;
    OrderList p,s;
    p = *L;//p指向L的第一个节点
    while(p&&p->next->data <= e){
        p = p->next;
    }

    if(!p)//p
        return false;
    s =(OrderList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next = s;
    return true;
}
//删除第i个位置
bool ListDelet(OrderList *L,int i,ElemType *e){
    int j;
    OrderList p,s;
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
int ListLength(OrderList L){
    OrderList p;
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
void display(OrderList L){
    OrderList p;
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
    OrderList La;
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

    ListInsert(&La,3);
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
