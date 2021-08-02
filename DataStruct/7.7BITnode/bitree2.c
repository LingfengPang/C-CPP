#include "bitree2.h"
#include "stdio.h"

//右旋操作
void R_Rotate(BiTree *P){
    BiTree L;
    L = (*P)->lchild;
    (*P)->lchild = L->rchild;
    L->rchild = (*P);
    *P = L;//
}

void L_Rotate(BiTree *P){
    BiTree L;
    L = (*P)->rchild;
    (*P)->rchild = L->lchild;
    L->lchild = (*P);
    *P = L;//
}
//左平衡旋转处理
//T指向某个子树的根
//前提已知不平衡
void LeftBalance(BiTree *T){
    BiTree L,Lr;
    L = (*T)->lchild;
    switch(L->bf)
    {
        //检查平衡度
        case LH:
        //新节点就在左孩子树上的左子树上
            (*T)->bf = L->bf = EH;
            R_Rotate(T);
            break;
        //新节点就在左孩子树上的右子树上
        case RH:
            Lr = L->rchild;
            switch (Lr->bf)
            {
            case LH:
                (*T)->bf = RH;
                L->bf = EH;
                break;
            case EH:(*T)->bf = L->bf = EH;
                break;
            
            case RH: (*T)->bf = EH;
                L->bf = LH;
                break;
            }
    }
    Lr->bf = (&(*T)->lchild);
    R_Rotate(T);
}
//如果在T中不存在val为e的，则插入
//taller表示是否变长
bool InsertAVL(BiTree *T,int e,bool *taller){
    //树不存在则创造
    if(!*T){
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = true;
    }
    else{
        //有这个数据
        if(e == (*T)->data){
            *taller = false;
            return false;
        }
        if(e<(*T)->data){
            //小于往左子树构造
            if(!InsertAVL(&(*T)->lchild,e,taller))
                return false;
            if(*taller){
                switch ((*T)->bf)
                {
                case LH:
                    LeftBalance(T);
                    *taller = false;
                    break;
                
                case EH:
                    (*T)->bf = LH;
                    *taller = true;
                    break;
                case RH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                }
            }
        }
        else{
            //往右子树寻找
            if(!InsertAVL(&(*T)->rchild,e,taller))
                return false;
            if(*taller){
                switch ((*T)->bf)
                {
                case LH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                
                case EH:
                    (*T)->bf = RH;
                    *taller = true;
                    break;
                case RH:
                    RightBalance(T);
                    *taller = false;
                    break;
                }
            }

        }
    }
}