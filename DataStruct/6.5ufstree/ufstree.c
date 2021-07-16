#include <stdio.h>
#include "ufstree.h"
#include <windows.h>
#include <stdbool.h>

//并查集初始化
void makeSet(UFSTree t[]){
    int i;
    for(i = 0;i<N;i++){
        t[i].data = i;//编号
        t[i].rank = 0;//秩
        t[i].parent = i;//双亲初始化为自己
    }
}
//查早一个元素所属的集合
int findSet(UFSTree t[],int x){
    if(x!=t[x].parent)
        return(findSet(t,t[x].parent));
    else
        return x;
}
//两个元素各自所属的集合合并
void Union(UFSTree t[],int x,int y){
    x = findSet(t,x);
    y = findSet(t,y);
    if(t[x].rank>t[y].rank)
        t[y].parent = x;
    else{
        t[x].parent = y;
        if(t[x].rank == t[y].rank)
            t[y].rank++;
    }
}