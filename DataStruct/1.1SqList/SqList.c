#include "SqList.h"
#include <stdio.h>
#include <windows.h>

void InitList(SqList *L){
    ElemType e;
    int len;
    L->length=0;
    int i = 0;
    printf("please Enter Len(if len>MAXSIZE,len=MAXSIZE): \n");
    scanf("%d",&len);//如果大于MAX,则默认max
    printf("please Enter Data: \n");
    while(L->length<MAXSIZE&&L->length<len){
        scanf("%d",&e);
        L->data[L->length++]=e;
    }
}
bool ListEmpty(SqList L){
    return (L.length == 0);
}
void ClearList(SqList *L){
    L->length=0;
}
//获取第i个元素
bool GetElem(SqList L,int i,ElemType *e){
    if(L.length==0||i<1||i>L.length){
        return false;
    }
    *e = L.data[i-1];
    return true;
}
//是否存在查找元素
bool LocateElem(SqList L,ElemType e){
    bool flag = false;
    for(int i=0;i<L.length;i++){
        if(L.data[i] == e){
            flag = true;
            printf("exist!\n");
            break;
            }

    }
    return flag;
}

bool ListInsert(SqList *L,int i,ElemType e){
    int k;
    if(i<1||i>L->length+1||L->length>=MAXSIZE){
        return false;
    }
    if(i<L->length){
        for(k = L->length-1;k>=i-1;k--){
            L->data[k+1]=L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return true;
}
//删除第第i个元素，并返回删除的值e
bool ListDelet(SqList *L,int i,ElemType *e){
    int k;
    if(i<1||i>L->length+1||L->length==0){
        return false;
    }
    *e = L->data[i-1];
    if(i<L->length){
        for(k =i;k<L->length;k++){
            L->data[k-1]=L->data[k];
        }
    }
    L->length--;
    return true;
}
int ListLength(SqList L){
    return L.length;
}

//线性表合并,Lb中与La不同的数据插入La中，实现L=AUB
void unioL(SqList *La,SqList Lb){
    int La_len,Lb_len;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for(int i = 1;i<=Lb_len;i++){
        GetElem(Lb,i,&e);
        if(!LocateElem(*La,e)){
            ListInsert(La,++La_len,e);
        }
    }
}

void display(SqList L){
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
}

int main(){
    SqList La,Lb;
    ElemType e;
    bool flag;
    InitList(&La);   
    InitList(&Lb); 
    display(La);
    display(Lb); 
    flag = ListEmpty(La);
    if(flag == false){
        printf("La is not empty!\n");
    }
//void ClearList(SqList *L);
    GetElem(La,1,&e);
    printf("the first data of La is :%d \n",e);
    LocateElem(La,1);//exist!

    ListInsert(&La,3,10);
    display(La);
    ListDelet(&Lb,1,&e);
    printf("%d \n",e);
    display(Lb);
    e = ListLength(Lb);
    printf("Lb's length is %d\n",e);
    unioL(&La,Lb);//线性表AUB
    display(La); 
    ClearList(&Lb);true;
    flag = ListEmpty(Lb);
    if(flag == true){
        printf("Lb is empty!\n");
    }

    system("pause");
    return 0;


}
