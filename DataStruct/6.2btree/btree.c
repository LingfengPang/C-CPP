#include <stdio.h>
#include "btree.h"
#include <windows.h>
#include <stdbool.h>
void createBtree(BTree *b,char *str){
    BTNode *St[MaxSize],*p;
    int top = -1,k,j = 0;
    char ch;
    *b = NULL;
    ch = str[j];
    while(ch!='\0'){
        switch (ch)
        {
        case '(':top++;St[top] = p;k = 1;break;
        case ')':top--;break;
        case ',':k = 2;break;
        default:p=(BTree)malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p ->rchild = NULL;
                if(*b == NULL)
                    *b = p;
                else{
                    switch (k)
                    {
                    case 1:St[top]->lchild = p;break;
                    case 2:St[top]->rchild = p;break;
                    }
                }
        }
        j++;
        ch = str[j];
    }

}

BTNode *findNode(BTNode *b,ElemType x){
    BTNode *p;
    if(b == NULL){
        return NULL;
    }
    else if(b->data == x)
        return b;
    else{
        p = findNode(b->lchild,x);
        if(p!=NULL)
            return p;
        else
            return findNode(b->rchild,x);
    }
}

BTNode *lchidlNode(BTNode *b){
    return b->lchild;
}

BTNode *rchidlNode(BTNode *b){
    return b->rchild;
}

int btNodeDepth(BTNode *b){
    int lchild,rchild;
    if(b == NULL)
        return 0;
    lchild = btNodeDepth(b->lchild);
    rchild = btNodeDepth(b->rchild);
    return (lchild>rchild)?(lchild+1):(rchild+1);
}

void display(BTNode *b){
    if(b!=NULL){
        printf("%c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL){
            printf("(");
            display(b->lchild);
            if(b->rchild!=NULL){
                printf(",");
            }
            display(b->rchild);
            printf(")");
        }
    }
}
//先序遍历递归方式
//先访问根节点
//然后左节点树
//然后右节点树
void preOrder(BTNode *b){
    if(b!=NULL){
        printf("%c",b->data);
        preOrder(b->lchild);
        preOrder(b->rchild);
    }
}

//中序遍历递归
//先左子树
//访问根节点
//中序遍历右子树
void inOrder(BTNode *b){
    if(b!=NULL){
        inOrder(b->lchild);
        printf("%c",b->data);
        inOrder(b->rchild);
    }
}
//后序遍历递归
//先左树
//然后右树
//最后根
void postOrder(BTNode *b){
    if(b!=NULL){
        postOrder(b->lchild);
        postOrder(b->rchild);
        printf("%c",b->data);
    }
}

void preOrder1(BTNode *b){
    BTNode *St[MaxSize],*p;
    int top = -1;
    if(b!= NULL){
        top++;
        St[top] = b;
        while(top>-1){
            p = St[top];
            top--;
            printf("%c",p->data);
            if(p->rchild!=NULL){
                top++;
                St[top] = p ->rchild;
            }
            if(p->lchild!=NULL){
                top++;
                St[top] = p->lchild;
            }
        }
    }
}
void inOrder1(BTNode *b){
    BTNode *St[MaxSize],*p;
    int top = -1;
    if(b!= NULL){
        p = b;
        while(top>-1 || p!=NULL){
            while(p!=NULL){
                top++;
                St[top] = p;
                p = p->lchild;
            }
            if(top>-1){
                p = St[top];
                top--;
                printf("%c",p->data);
                p = p->rchild;
            }
        }
    }
}


void postOrder1(BTNode *b){
    BTNode *St[MaxSize],*p;
    int top = -1;
    int flag;
    if(b!= NULL){
        do{
            while(b!=NULL){
                top++;
                St[top] = b;
                b = b->lchild;
            }
            p = NULL;
            flag = 1;
            while(top!=-1&&flag){
                b = St[top];
                if(b->rchild == p){
                    printf("%c",p->data);
                    top--;
                    p = b;       
                } 
                else{
                    b = b ->rchild;
                    flag = 0;
                }
            }
        }while(top!=-1);
    }
}

void levelOrder(BTNode *b){
    BTNode *p;
    BTNode *qu[MaxSize];
    int front,rear;
    front = rear = -1;
    rear++;
    qu[rear]=b;
    while(front!=rear){
        front = (front+1)%MaxSize;
        p = qu[front];
        printf("%c",p->data);
        if(p->lchild!=NULL){
            rear = (rear+1)%MaxSize;
            qu[rear] = p->lchild;
        }
        if(p->rchild!=NULL){
            rear=(rear+1)%MaxSize;
            qu[rear]=p->rchild; 
        }
    }
}
//先序与中序构建二叉树
BTNode *createBT1(char *pre,char *in,int n){
    BTNode *b;
    char *p;
    int k;
    if(n<=0)
        return NULL;
    b = (BTNode *)malloc(sizeof(BTNode));//创建二叉树节点
    b->data = *pre;
    for(p = in;p<in+n;p++){
        if(*p == *pre)
            break;
    }
    k = p - in;
    b->lchild = createBT1(pre+1,in,k);
    b->rchild = createBT1(pre+k+1,p+1,n-k-1);
    return b;
}

//中序和后序构建二叉树
BTNode *createBT2(char *in,char* post,int n){
    BTNode *b;
    char *p,r;
    int k;
    if(n<=0)
        return NULL;
    r = *(post+n-1);
    b = (BTNode *)malloc(sizeof(BTNode));//创建二叉树节点
    b->data = r;
    for(p = in;p<in+n;p++){
        if(*p == r)
            break;
    }
    k = p - in;
    b->lchild = createBT2(in,post,k);
    b->rchild = createBT2(p+1,post+k,n-k-1);    
    return b;
}
int main(){
    BTNode **b;
    char *str = "A(B(D(,G)),C(E,F))";
    createBtree(b,str);
    //display(*b);
    preOrder(*b);
    printf("\n");
    inOrder(*b);
    printf("\n");
    postOrder(*b);
    printf("\n");


    preOrder1(*b);
    printf("\n");
    inOrder1(*b);
    printf("\n");
    postOrder(*b);
    printf("\n");

    levelOrder(*b);
    printf("\n");
    system("pause");
    return 0;

}