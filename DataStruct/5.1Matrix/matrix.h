#ifndef MATRIX_H
#define MATRIX_H
#include <stdbool.h>
#define M 3
#define N 3
#define MAXSIZE M*N
typedef int ElemType;
typedef struct{
    int r;//行号
    int c;//列号
    ElemType d;//元素值
}TupNode;
typedef struct
{
    int rows;//行号
    int cols;//列号
    int nums;//非零个数
    TupNode data[MAXSIZE];//元素值
}TSMatrix;

void creatMat(TSMatrix *t,ElemType A[M][N]);
bool value(TSMatrix *t,ElemType x,int i,int j);
bool Assign(TSMatrix *t,ElemType *x,int i,int j);
void displayMat(TSMatrix t);
void tranMat(TSMatrix t,TSMatrix *tb);
#endif