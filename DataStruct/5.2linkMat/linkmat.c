#include "linkmat.h"
#include <windows.h>
#include <stdio.h>
void CreatMat(MatNode **mh,ElemType a[M][N]){
    int i,j;
    MatNode *h[Max],*p,*q,*r;
    (*mh) = (MatNode *)malloc(sizeof(MatNode));//创建头节点
    (*mh)->row = M;
    (*mh)->col = N;
    r = *mh;//r指向尾节点

    for(i = 0;i<Max;i++){//采用尾插法创建头节点
        h[i] = (MatNode *)malloc(sizeof(MatNode));
        h[i]->down = h[i]->right = h[i];
        r->tag.link = h[i];
        r = h[i];
    }
    r->tag.link = *mh;
    for(i = 0;i<M;i++){
        for(j = 0;j<N;j++){
            if(a[i][j]!=0){
                p = (MatNode *)malloc(sizeof(MatNode));//创建一个新节点
                p->row = i;
                p->col = j;
                p->tag.value=a[i][j];
                q = h[i];//指向对应的行
                while(q->right!=h[i]&&q->right->col<j){
                    q = q->right;
                }
                p->right = q->right;
                q->right = p;
                q = h[j];
                while(q->down!=h[j]&&q->down->row<i){
                    q = q->down;
                }
                p->down=q->down;
                q->down = p;
            }
        }
    }
}

void Display(MatNode *mh){
    MatNode *p,*q;
    printf("row = %d,col = %d\n",mh->row,mh->col);
    p = mh->tag.link;
    while(p!=mh){
        q = p->right;
        while(p!=q){
            printf("(%d,%d,%d)\n",q->row,q->col,q->tag.value);
            q = q->right;
        }
        p = p->tag.link;
    }

}
typedef MatNode* Mat;
int main(){
    int a[M][N]={
        {1,0,0,2},
        {0,0,3,0},
        {0,0,0,4}
    };
    Mat mat;
    CreatMat(&mat,a);
    Display(mat);
    system("pause");
    return 0;
}