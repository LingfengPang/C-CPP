#include <stdio.h>
#include "adjlist.h"
#include <windows.h>
#include <stdbool.h>

void createALGrapg(GraphAdjList *G){
    int i,j,k;
    EdgeNode *e;
    printf("Enter vexs and edges\n");
    scanf("%d,%d",&G->numVertexes,&G->numsEdges);
    for(i = 0;i<G->numVertexes;i++){
        scanf(&G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }
    for(k = 0;k<G->numsEdges;k++){
        print("Enter(Vi,Vj):\n");
        scanf("%d %d",&i,&j);
        //采用头插法
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next=G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

void DFS(GraphAdjList G,int i){
    EdgeNode *p;
    visited[i] = true;
    printf("%c",G.adjList[i].data);
    p = G.adjList[i].firstedge;
    while(p){
        if(!visited[p->adjvex])
            DFS(G,p->adjvex);
        p = p->next;
    }
}

void DFSTraverse(GraphAdjList G){
    int i;
    for(i = 0;i<G.numVertexes;i++){
        visited[i] = false;
    }

    for(i = 0;i<G.numVertexes;i++){
        if(!visited[i]){
            DFS(G,i);//如果是连通图，则调用1次    
        }
    }
}

