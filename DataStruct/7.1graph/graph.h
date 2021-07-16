#ifndef GRAPH_H
#define GRAPH_H
#include <stdbool.h>
typedef char VertexType;//顶点类型
typedef int EdgeType;//边的权值
#define MAXVEX 100 //最大顶点数
#define INFINITY 65536 //表示无穷

typedef struct{
    VertexType vexs[MAXVEX];//顶点表
    EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
    int numVertexes,numEdges;//当前顶点数和边数
}MGraph;

typedef struct{
    int begin;
    int end;
    int weight;
}Edge;

typedef int Patharc[MAXVEX];//用于存储最短路径下标的数组;
typedef int ShortPathTable[MAXVEX];//用于存储到各点最短路径的权值和
bool visited[MAXVEX];

typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void createMGrapg(MGraph *G);
void DFS(MGraph G,int i);
void DFSTraverse(MGraph G);
void BFSTraverse(MGraph G);
void MiniSpanTree(MGraph G);
void MiniSpanTree2(MGraph G);
void ShortestPath_Dijkstra(MGraph G,int v0,Patharc *P,
                            ShortPathTable *D);
void ShortestPath_Floyd(MGraph G,Pathmatirx *P,
                        ShortPathTable *D);
#endif