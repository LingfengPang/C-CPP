#ifndef AOV_H
#define AOV_H
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
    int in;//顶点入度
    int data;//顶点域
    EdgeNode *firstedge;//链值域
    
}VertexNode,AdjList[100];

typedef struct{
    AdjList adjList;
    int numVertexes,numsEdges;//图当中的顶点数和边数
}GraphAdjList;

void creasteALGrapg(GraphAdjList *G);
void DFS(GraphAdjList G,int i);

#endif