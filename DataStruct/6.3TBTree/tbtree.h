#ifndef TBTREE_H
#define TBTREE_H
typedef char ElemType;
#define MaxSize 100
typedef struct node
{
    ElemType data;
    int ltag,rtag;
    struct node* lchild;
    struct node* rchild;
}TBTNode;
TBTNode *pre;//始终指向刚刚访问过的节点
void Thread(TBTNode **p);
TBTNode *createThread(TBTNode *p);
void ThInOrder(TBTNode *tb);
#endif