#ifndef BTREE_H
#define BTREE_H
typedef char ElemType;
#define MaxSize 100
typedef struct node
{
    ElemType data;
    struct node* lchild;
    struct node* rchild;
}BTNode,*BTree;
void createBtree(BTree *b,char *str);
BTNode *findNode(BTNode *b,ElemType x);
BTNode *lchidlNode(BTNode *b);
BTNode *rchidlNode(BTNode *b);
int btNodeDepth(BTNode *b);
void display(BTNode *b);
void preOrder(BTNode *b);
void inOrder(BTNode *b);
void postOrder(BTNode *b);

void preOrder1(BTNode *b);
void inOrder1(BTNode *b);
void postOrder1(BTNode *b);

void levelOrder(BTNode *b);

BTNode *createBT1(char *pre,char *in,int n);
BTNode *createBT2(char *in,char* post,int n);
#endif