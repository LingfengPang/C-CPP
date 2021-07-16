#ifndef ADJLIST_H
#define ADJLIST_H
#include <stdbool.h>
typedef char VertexType;//顶点类型
typedef int EdgeType;//边的权值
bool visited[100];
//边表节点
typedef struct EdgeNode{
    int adjvex;//顶点对应的坐标
    EdgeType weight;//存储权值
    struct EdgeNode *next;//邻域
}EdgeNode;
//顶点表节点
typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[100];
typedef struct{
    AdjList adjList;
    int numVertexes,numsEdges;//图当中的顶点数和边数
}GraphAdjList;

void creasteALGrapg(GraphAdjList *G);
void DFS(GraphAdjList G,int i);

// void BFSTraverse(GraphAdjList G){
//     int i,j;
//     EdgeNode *p;

//     Queue Q;
//     for(i = 0;i<G.numVertexes;i++){
//         visited[i] = false;
//     }
//     InitQueue(&Q);
//     for(i = 0;i<G.numVertexes;i++){
//         if(!visited[i]){
//             visited[i] = true;
//             printf("%c ",G.adjList[i].data);
//             Enqueue(&Q,i);
//             while(!QueueEmpty(Q)){//当前队列不为空
//                 DeQueue(&Q,&i);
//                 p = G.adjList[i].firstedge;
//                 while(p){
//                     if(!visited[p->adjvex]){
//                         visited[p->adjvex] = TRUE;
//                         printf("%c",G.adjList[p->adjvex].data);
//                         EnQueue(&Q,p->adjvex);
//                     }
//                     p = p->next;
//                 }
//             }
//         }
//     }
// }
#endif