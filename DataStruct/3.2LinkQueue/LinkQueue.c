#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "LinkQueue.h"
//这个队列木有头节点



void init_LinkQueue(LinkQueue *q){
    q->front = q->rear =NULL;
    q->length = 0;
}

// void destroy_LinkQueue(LinkQueue *q){
//     free(q);
// }

int length_LinkQueue(LinkQueue *q){
    return (q->length);
}
void make_empty(LinkQueue *q){
    q->front = q->rear =NULL;
    q->length = 0;
}                     

bool is_empty(LinkQueue *q){
    return (q->length == 0);
}

//进入队列
bool enQueue(ElemType e,LinkQueue *q){
    QueuePtr s =(QueuePtr)malloc(sizeof(QNode));
    //QueuePtr s;
    if(!s)//申请内存失败
        return false;
   
    s->data = e;
    s->next = NULL;
    if(q->rear == NULL){
        q->front = q->rear = s;
    }
    
        q->rear->next = s;
        q->rear = s;
        q->length++;
   
    return true;

}
//出栈
bool GetHead(ElemType *e,LinkQueue *q){
    if(is_empty(q)){
        return false;
    }
    else{
        QueuePtr s;
        s = q->front;
        (*e) = s->data;
        return true;
    }
}

//出队列
bool deQueue(ElemType *e,LinkQueue *q){
    if(is_empty(q)){
        return false;
    }
    else{
        QueuePtr s;
        s = q->front;
        (*e) = s->data;
        if(q->front == q->rear)
            q->front = q->rear =NULL;
        else
            q->front = s->next;
        free(s);
        q->length--;
        
        return true;
    }
}

int main(){
    LinkQueue q;
    ElemType e = 0;
    init_LinkQueue(&q);
    for(int i = 0;i<5;i++)
        enQueue(i+1,&q);
    GetHead(&e,&q);
    
    printf("%d\n",e);
    e = length_LinkQueue(&q);
    printf("%d\n",e);
    for(int i = 0;i<5;i++){
        deQueue(&e,&q);
        printf("%d ",e);
    }
    printf("\n");
       
    system("pause");
    return 0;
}