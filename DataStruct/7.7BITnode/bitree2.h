#ifndef BITREE2_H
#define BITREE2_H
typedef int ElemType;
#define MaxSize 100
#define LH +1 //左高
#define EH 0
#define RH -1
#include <stdbool.h>
typedef struct BiTNode
{
    ElemType data;
    int bf;//平衡因子
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


void R_Rotate(BiTree *P);
void L_Rotate(BiTree *P);
void LeftBalance(BiTree *T);
void RightBalance(BiTree *T);
bool InsertAVL(BiTree *T,int e,bool *taller);
// bool SearchBST(BiTree T,ElemType key,BiTree f,BiTree *p);
// bool InsertBST(BiTree *T,ElemType key);
// bool DeleteBST(BiTree *T,ElemType key);
// bool Delete(BiTree *p);
#endif
