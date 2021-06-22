#ifndef LINKMAT_H
#define LINKMAT_H
#define M 3
#define N 4
#define Max ((M>N)?(M):(N))

typedef int ElemType;
typedef struct mtxn
{
    /* data */
    int row;//行号
    int col;//列号
    struct mtxn* right,*down;//向右和向下的指针
    union
    {
        /* data */
        ElemType value;
        struct mtxn *link;//指向下一个头节点
    }tag;
}MatNode;

void CreatMat(MatNode **mh,ElemType a[M][N]);
void Display(MatNode *mh);
#endif