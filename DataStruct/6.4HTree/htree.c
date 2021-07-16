#include <stdio.h>
#include "htree.h"
#include <windows.h>
#include <stdbool.h>

//n个叶子节点  -》 2n-1个节点
void createHT(HTNode ht[],int n){
    int i,j,k,lnode,rnode;
    double min1,min2;
    for(i = 0;i<2*n-1;i++){
        //都初始化为-1
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }
    for(i = n;i<2*n-1;i++){//从叶子节点开始找
        min1 = min2 =32767;
        lnode = rnode = -1;//lnode和rnode为权重最小的节点
        for(k = 0;k<=i-1;k++){
            //选择排序找到权重最小的节点
            if(ht[k].parent == -1){
                if(ht[k].weight<min1){
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                }
                //第二小的数
                else if(ht[k].weight<min2){
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
            ht[i].weight = ht[lnode].weight+ht[rnode].weight;
            ht[i].lchild = lnode;
            ht[i].rchild = rnode;
            ht[lnode].parent = i;
            ht[rnode].parent = i;
        }
    }
}

void createHCode(HTNode ht[],HCode hcd[],int n){
    int i,f,c;
    HCode hc;
    //把叶子节点编码
    for(i = 0;i<n;i++){
        hc.start = n;
        c = i;
        f = ht[i].parent;
        while(f!= -1){//循环直到无双亲节点
            if(ht[f].lchild == c)//如果是左节点
                hc.cd[hc.start--] = '0';
            else//如果是右节点
                hc.cd[hc.start--] = '1';
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
}