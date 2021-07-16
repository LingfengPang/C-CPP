#ifndef UFSTREE_H
#define UFSTREE_H
//并查集树
#define N 30
typedef struct{
    int data;
    int rank;
    int parent;
}UFSTree;


void makeSet(UFSTree t[]);
int findSet(UFSTree t[],int x);
void Union(UFSTree t[],int x,int y);
#endif