#include <stdio.h>
#include "graph.h"
#include <windows.h>
#include <stdbool.h>
//邻接矩阵表示法
void createMGrapg(MGraph *G){
    int i,j,k,w;
    printf("Enter vexs and edges:");
    scanf("%d %d",G->numVertexes,G->numEdges);
    for(i = 0;i<G->numVertexes;i++){//读入顶点信息
        scanf(&G->vexs[i]);
    }
    for(i = 0;i < G->numVertexes;i++){
        for(j = 0;j<G->numVertexes;j++){
            G->arc[i][j] = INFINITY;//初始化
        }
    }
    //读入边
    for(k = 0;k<G->numEdges;k++){
        //(vi,vj),和权
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}
//深度优先递归方法
void DFS(MGraph G,int i){
    int j;
    visited[i] = true;
    printf("%c ",G.vexs[i]);//打印节点
    for(j = 0;j<G.numVertexes;j++){
        if(G.arc[i][j] == 1 &&!visited[j])//这里权为1后期可以修改
            DFS(G,j);
    }
}
//非递归DFS???我咋感觉
void DFSTraverse(MGraph G){
    int i = 0;
    for(i = 0;i<G.numVertexes;i++)
        visited[i] = false;
    for(i = 0;i<G.numVertexes;i++)
        if(!visited[i]){
            DFS(G,1);
        }
    
}
//普里姆最小生成树
void MiniSpanTree(MGraph G){
    int min,i,j,k;
    int adjvex[MAXVEX];//保存相关坐标
    int lowcost[MAXVEX];//保存相关顶点边权值
    lowcost[0] = 0;
    adjvex[0] = 0;

    for(i = 1;i<G.numVertexes;i++){
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }

    for(i = 1;i<G.numVertexes;i++){
        min = INFINITY;
        j = 1;
        k = 0;
        //寻找最小权值
        while(j<G.numVertexes){
            if(lowcost[j] != 0 && lowcost[j]<min){
                min = lowcost[i];
                k = j;
            }
            j++;
        }

        //连接顶点和这条边
        printf("(%d,%d)",adjvex[k],k);
        //到k已经有路了，记为0






        
        lowcost[k] = 0;

        for(j = 1;j<G.numVertexes;j++){
            if(lowcost[j]!=0 && G.arc[k][j]< lowcost[j]){
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}
int Find(int *parent,int f){
    while(parent[f]>0){
        f = parent[f];
    }
    return f;
}
//以边创建st
void MiniSpanTree2(MGraph G){
    int i,n,m;
    Edge edges[100];//定义边数组
    int parents[MAXVEX];//定义一数组判断边与边是否形成回路
    //此处省略边集数组权值由大到小的算法
    //edges最后由大到小排序
    for(i = 0;i<G.numVertexes;i++){
        parents[i] = 0;
    }
    for(i = 0;i<G.numEdges;i++){
        n = Find(parents,edges[i].begin);
        m = Find(parents,edges[i].end);
        if(n!=m){
            parents[n] = m;
            printf("(%d,%d) %d",edges[i].begin,
            edges[i].end,edges[i].weight);
        }
    }
}

void ShortestPath_Dijkstra(MGraph G,int v0,Patharc *P,ShortPathTable *D){
    int v,w,k,min;
    int final[MAXVEX];//final[w]=1表示v0至vw的最短路径
    for(v = 0;v<G.numVertexes;v++){
        final[v] = 0;
        (*D)[v] = G.arc[v0][v];
        (*P)[v] = 0;
    }
    (*D)[v0] = 0;//v0至v0路径位0
    final[v0] = 1;//v0至v0不需要路径
    for(v = 1;v<G.numVertexes;v++){
        min = INFINITY;
        //寻找离v0最近的点vk
        for(w = 0;w<G.numVertexes;w++){
            if(!final[w]&&(*D)[w]<min){
                k = w;
                min = (*D)[w];
            }
        }
        final[k] = 1;//将此点set 1
        //进行修正
        for(w = 0;w<G.numVertexes;w++){
            if(!final[w]&&(min+G.arc[k][w])<(*D)[w]){
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
}

//求所有点的最短路径
void ShortestPath_Floyd(MGraph G,Pathmatirx *P,ShortPathTable *D){
    int v,w,k;
    for(v = 0;v<G.numVertexes;++w){
        for(w = 0;w<G.numVertexes;++w){
            (*D)[v][w] = G.arc[v][w];//记录权值
            (*P)[v][w] = w;//初始化P矩阵
        }
        for(k = 0;k<G.numVertexes;++k){
            for(v = 0;v<G.numVertexes;++v){
                for(w = 0;w<G.numVertexes;++w){
                    if((*D)[v][w]>(*D)[v][w]+(*D)[k][w]){
                        (*D)[v][w] = (*D)[v][w]+(*D)[k][w];
                        (*P)[v][w] = (*P)[v][k];
                    }
                }
            }
        }
    }
}

//基于Floyd寻找最短路径
/*
int v,w;
for(v = 0;v<G.numVertexes;++v){
    for(w = v+1;w<G.numVertexes;++w){
        printf("v%d-v%d weight: %d",v,w,D[v][w]);
        k = P[v][w];
        printf("path : %d",v);
        while(k!=w){
            printf("-> %d",k);
            k = P[k][w];
        }
        printf("->%d\n",w);

    }
    printf("\n")
}
*/
//广度优先遍历
//里面队列自己看着办吧
// void BFSTraverse(MGraph G){
//     int i,j;
//     Queue Q;
//     for(i = 0;i<G.numVertexes;i++){
//         visited[i] = false;
//     }
//     InitQueue(&Q);
//     for(i = 0;i<G.numVertexes;i++){
//         if(!visited[i]){
//             visited[i] = true;
//             printf("%c ",G.vexs[i]);
//             Enqueue(&Q,i);
//             while(!QueueEmpty(Q)){//当前队列不为空
//                 DeQueue(&Q,&i);
//                 for(j = 0;j<G.numVertexes;j++){
//                     if(G.arc[i][j] == 1 && !visited[j]){
//                         visited[j] = true;
//                         printf("%c",G.vexs[j]);
//                         Enqueue(&Q,j);
//                     }
//                 }
//             }
//         }
//     }
// }