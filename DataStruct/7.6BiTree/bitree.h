#ifndef BITREE_H
#define BITREE_H
typedef int ElemType;
#define MaxSize 100
#include <stdbool.h>
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

bool SearchBST(BiTree T,ElemType key,BiTree f,Bitree *p);
bool InsertBST(BiTree *T,ElemType key);
bool DeleteBST(BiTree *T,ElemType key);
bool Delete(BiTree *p);
#endif
