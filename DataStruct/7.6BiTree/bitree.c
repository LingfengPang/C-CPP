#include "bitree.h"
#include "stdio.h"
//二叉排序树查找 T中查找key
//f指向T的双亲
//p指向寻找的元素节点
//失败返回双亲
bool SearchBST(BiTree T,ElemType key,BiTree f,BiTree *p){
    if(!T){
        *p = f;
        return false;
    }
    else if(key == T->data){
        *p = T;
        return true;
    }
    else if(key<T->data)
        return SearchBST(T->lchild,key,T,p);
    else
        return SearchBST(T->rchild,key,T,p);
}

bool InsertBST(BiTree *T,ElemType key){
    BiTree p,s;
    if(!SearchBST(*T,key,NULL,&p)){
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild =NULL;
        if(!p){
            *T = s;
        }
        else if(key<p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return true;
    }
    else
        return false;
}
//删除key对应的节点
bool DeleteBST(BiTree *T,ElemType key){
    if(！(*T))
        return false;
    else{
        if(key == (*T)->data)
            return Delete(T);
        else if(key<(*T)->data){
            return DeleteBST(&(*T)->lchild,key);
        }
        else{
            return DeleteBST(&(*T)->rchild,key);
        }
    }
}
//删除节点
bool Delete(BiTree *p){
    BiTree q,s;
    if((*p)->lchild == NULL){
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if((*p)->rchild == NULL){
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else{
        q = *p;
        s = (*p)->lchild;
        while(s->rchild){
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if(q!=*p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        free(s);
    }
    return true;
}