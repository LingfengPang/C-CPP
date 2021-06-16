#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "queue.h"
//这个队列有缺陷



void init_SqQueue(SqQueue *q){
    //q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = -1;
    q->rear = -1;
}

void destroy_SqQueue(SqQueue *q){
    free(q);
}

// int length_SqQueue(SqQueue *q){
//     return (q->rear - q->front);
// }
void make_empty(SqQueue *q){
    q->front = q->rear = -1;
}                     

bool is_empty(SqQueue *q){
    return (q->front == q->rear);
}

bool is_full(SqQueue *q){
    return q->rear == MAXSIZE-1;
}
//进入队列
bool enQueue(ElemType e,SqQueue *q){
    if(is_full(q)){
        return false;
    }
    else{ 
        q->rear++;
        q->content[q->rear] = e;
        return true;
    }
}
//获取队列头元素
bool GetHead(ElemType *e,SqQueue *q){
    if(is_empty(q)){
        return false;
    }
    else{
        (*e) = q->content[q->front+1];
        return true;
    }
}

//出队列
bool deQueue(ElemType *e,SqQueue *q){
    if(is_empty(q)){
        return false;
    }
    else{
        q->front++;
        (*e) = q->content[q->front];
        return true;
    }
}

int main(){
    SqQueue q;
    ElemType e = 0;
    init_SqQueue(&q);
    for(int i = 0;i<5;i++)
        enQueue(i+1,&q);
    GetHead(&e,&q);
    
    printf("%d\n",e);
    for(int i = 0;i<5;i++){
        deQueue(&e,&q);
        printf("%d ",e);
    }
    printf("\n");
       
    system("pause");
    return 0;
}