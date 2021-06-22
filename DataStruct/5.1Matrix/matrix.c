#include <stdio.h>
#include "matrix.h"
#include <windows.h>
//稀疏矩阵表示方式
//（0，2，1）在0行2列元素为1
void creatMat(TSMatrix *t,ElemType A[M][N]){
    int i,j;
    t->rows = M;
    t->cols = N;
    t->nums = 0;
    for(int i = 0;i<M;i++){
        for(int j =0;j<N;j++){
            if(A[i][j]!=0){
                t->data[t->nums].c = j;
                t->data[t->nums].r = i;
                t->data[t->nums].d = A[i][j];
                t->nums++;
            }
        }
    }
}
//赋值
bool value(TSMatrix *t,ElemType x,int i,int j){
    int k = 0;
    int k1;
    if(i>=t->rows||j>=t->cols)
        return false;
    while(k<t->nums&&i> t->data[k].r)
        k++;//先找行
    while(k<t->nums&&i==t->data[k].r&&j>t->data[k].c)
        k++;//查找列
    if(t->data[k].r==i&&t->data[k].c==j)//存在这样的元素
    {
        t->data[k].d=x;
    }
    else{
        for(k1 = t->nums-1;k1>=k;k1--){
            t->data[k1+1].r = t->data[k1].r;
            t->data[k1+1].c = t->data[k1].c;
            t->data[k1+1].d = t->data[k1].d;
        }
        t->data[k].r = i;
        t->data[k].c = j;
        t->data[k].d = x;
        t->nums++;
    }
    return true;

}
//将指定位置的元素赋值给x
bool Assign(TSMatrix *t,ElemType *x,int i,int j){
    int k = 0;
    if(i>=t->rows||j>=t->cols)
        return false;
    while(k<t->nums&&i> t->data[k].r)
        k++;//先找行
    while(k<t->nums&&i==t->data[k].r&&j>t->data[k].c)
        k++;//查找列
    if(t->data[k].r==i&&t->data[k].c==j)//存在这样的元素
    {
        *x = t->data[k].d;
    }
    else
        *x = 0;
    return true;
}

void displayMat(TSMatrix t){
    int i;
    if(t.nums<=0)
        return;
    printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
    printf("\t-------------------------------\n");
    for(i = 0;i<t.nums;i++){
        printf("(%d, %d, %d)\n",t.data[i].r,t.data[i].c,t.data[i].d);
    }
}
//转置
void tranMat(TSMatrix t,TSMatrix *tb){
    int p,q = 0;
    int v;
    tb->rows = t.cols;
    tb->cols = t.rows;
    tb->nums = t.nums;
    if(t.nums!=0){
         //for(v = 0;v<t.cols;v++){
            for(p = 0;p<t.nums;p++){
                //if(t.data[p].c == v){
                    tb->data[q].r = t.data[p].c;
                    tb->data[q].c = t.data[p].r;
                    tb->data[q].d = t.data[p].d;
                    q++;
                }
            //}
        //}
    }
}

int main(){
    int a[3][3]={
        {1,0,0},
        {0,2,0},
        {0,0,3}
    };
    TSMatrix t1,t2;
    creatMat(&t1,a);
    displayMat(t1);
    tranMat(t1,&t2);
    displayMat(t2);
    
    system("pause");
    return 0;
    
}