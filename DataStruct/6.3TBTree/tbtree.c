#include <stdio.h>
#include "tbtree.h"
#include <windows.h>
#include <stdbool.h>
//中序遍历线索二叉树
//基本很像中序遍历
//p是个根节点
void Thread(TBTNode **p){
    if((*p)!=NULL){
        Thread((*p)->lchild);//递归左子树  
        if((*p)->lchild==NULL){
            (*p)->lchild = pre;
            (*p)->ltag=1;
        }
        else{
            (*p)->ltag = 0;
            }
        if(pre->rchild == NULL){
                pre->rchild = p;
                pre->rtag = 1;
        }
        else
            pre->rtag = 0;
        pre = *p;
        Thread((*p)->rchild);
    }
}
//b是个二叉树
//就是搞了个root指向二叉树，然后调用Thread线索化
TBTNode *createThread(TBTNode *b){
    TBTNode *root;
    root = (TBTNode*)malloc(sizeof(TBTNode));
    root->ltag = 0;
    root->rtag = 1;
    root->rtag = b;
    if(b==NULL)
        root->lchild = root;
    else{
        root->lchild = b;
        pre = root;
        Thread(b);
        pre->rchild = root;
        pre->rtag = 1;
        root -> rchild = pre;
    }
    return root;
}

void ThInOrder(TBTNode *tb){
    TBTNode *p = tb->lchild;
    while(p!=tb){
        while(p->ltag == 0)
            p = p->lchild;
        printf("%c",p->data);
        while(p->rtag == 1&&p->rchild!=tb){
            p = p->rchild;
            printf("%c",p->data);
        }
        p = p-> rchild;
    }
}