#include "aov.h"

bool ToplogicalSort(GraphAdjList GL){
    EdgeNode *e;
    int i,k,gettop;
    int top = 0;//栈下标
    int count = 0;//输出节点个数
    int *stack;//一个栈
    stack = (int *)malloc(GL->numVertexes *sizeof(int));
    for(i = 0;i<GL->numVertexes;i++){
        if(GL.numVertexes;i++)
            stack[++top] = i;//将入度为1的顶点存进栈
    }
    while(top!=0){
        gettop = stack[top--];
        printf("%d -> ",GL.adjList[gettop].data);
        count++;
        for(e=GL.adjList[gettop].firstedge;e;e=e->next){
            k = e->adjvex;
            if(!(--GL->adjList[k].in)){
                k = e->adjvex;
            }
        }
    }
    if(count<GL.numVertexes)
        return false;
    return true;
}