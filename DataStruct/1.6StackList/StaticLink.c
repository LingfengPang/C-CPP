#include <stdio.h>
#include <windows.h>
#include "StaticLink.h"


//静态链表用于没有指针操作的语言，主要学习思路
//用数组实现指针
bool InitList(StaticLinkList L){
    int i;
    for(i = 0;i<MAXSIZE-1;i++)
        L[i].cur = i+1;//L[0]指向第一个空
    L[MAXSIZE-1].cur=0;//最后一个相当于头指针，指向第一个数据
    return true;   
}
bool ListEmpty(StaticLinkList L){
    return (L[MAXSIZE-1].cur==0);
}

void ClearList(StaticLinkList L){
    int i;
    for(i = 0;i<MAXSIZE-1;i++)
        L[i].cur = i+1;//L[0]指向第一个空
    L[MAXSIZE-1].cur=0;//最后一个相当于头指针，指向第一个数据
}

bool GetElem(StaticLinkList L,int i,ElemType *e){
    int j,k,l;
    k = MAXSIZE-1;
    if(i<1||i>ListLength(L)+1)
        return false;
    for(l = 1;l<=i;l++)
        k = L[k].cur;
    *e = L[k].data;
    return true;;
}

bool LocateElem(StaticLinkList L,ElemType e){
    int k,l;
    bool flag = false;
    k = MAXSIZE-1;

    for(l = 1;l<=ListLength(L);l++){
        k = L[k].cur;
        if(L[k].data == e){
            flag = true;
            break;
        }
    }
        
    return flag;
}
bool ListInsert(StaticLinkList L,int i,ElemType e){
    int j,k,l;
    k = MAXSIZE-1;
    if(i<1||i>ListLength(L)+1)
        return false;
    j = Malloc_SLL(L);
    if(j){
        L[j].data = e;//先将数据放置在最后
        for(l = 1;l<=i-1;l++)
            k = L[k].cur;
        L[j].cur =L[k].cur;
        L[k].cur = j;
        return true;
    }    
    return true;
}
bool ListDelet(StaticLinkList L,int i){
    int j,k;
    if(i<1||i>ListLength(L)+1)
        return false;
    k = MAXSIZE-1;
    for(j = 1;j<=i-1;j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur=L[j].cur;
    Free_SLL(L,j);
    return true;
}

int ListLength(StaticLinkList L){
    int j =0;
    int i=L[MAXSIZE-1].cur;
    while(i){
        i = L[i].cur;
        j++;
    }
    return j;
}

void display(StaticLinkList L){
    int j,k,l;
    k = MAXSIZE-1;
    for(l = 1;l<=ListLength(L);l++){
        k = L[k].cur;
        printf("%d ",L[k].data);
    }
    printf("\n");
}

int Malloc_SLL(StaticLinkList L){//分配空间
    int i = L[0].cur;//下一个数据位
    if(L[0].cur)
        L[0].cur=L[i].cur;
    return i;
}

void Free_SLL(StaticLinkList L,int k){
    L[k].cur = L[0].cur;
    L[0].cur = k;
}


int main(){
    StaticLinkList L;
    ElemType e;
    int k = MAXSIZE-1;
    bool flag;
    InitList(L);   
    for(int i = 1;i<=5;i++){
        ListInsert(L,i,i);
    }
    display(L);
     e = ListLength(L);
    printf("La's length is %d\n",e);
    flag = ListEmpty(L);
    if(flag == false){
        printf("La is not empty!\n");
    }
//void ClearList(SqList *L);
    GetElem(L,1,&e);
    printf("the first data of La is :%d \n",e);
    flag = LocateElem(L,5);//exist!
        if(flag == true){
        printf("5 is exist!\n");
    }
    ListInsert(L,3,10);
    display(L);
    ListDelet(L,5);

    display(L);
    e = ListLength(L);
    printf("La's length is %d\n",e);
    ClearList(L);
    flag = ListEmpty(L);
    if(flag == true){
        printf("La is empty!\n");
    }
    system("pause");
    return 0;
}