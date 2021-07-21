#include "aoe.h"

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
    top2 = 0;
    etv = (int*)malloc(GL.numVertexes*sizeof(int));
    for(i = 0;i<GL.numVertexes;i++){
        etv[i] = 0;
    }
    stack2 = (int *)malloc(GL.numVertexes*sizeof(int));
    while(top!=0){
        gettop = stack[top--];
        printf("%d -> ",GL.adjList[gettop].data);
        count++;
        stack2[++top] = gettop;
        for(e=GL.adjList[gettop].firstedge;e;e=e->next){
            k = e->adjvex;
            if(!(--GL->adjList[k].in)){
                k = e->adjvex;
            }
            if((etv[gettop]+e->weight)>etv[k]){
                etv[k] = etv[gettop] + e->weight;
            }
        }
    }
    if(count<GL.numVertexes)
        return false;
    return true;
}

//求关键路径，GL为有向往
void CriticalPath(GraphAdjList GL){
    EdgeNode *e;
    int i,gettop,k,j;
    int etc,lte;
    ToplogicalSort(GL);
    ltv = (int *)malloc(GL.numVertexes*sizeof(int));
    for(i = 0;i<GL.numVertexes;i++){
        ltv[i] = etv[GL.numVertexes-1];
    }
    while(top2!=0){
        gettop = stack[top2--];
        for(e = GL.adjList[gettop].firstedge;e;e->next){
            k = e->adjvex;
            if(ltv[k]->e->weight < lvt[gettop])
                    ltv[gettop] = ltv[k]-e->weight;
        }
    }
    for(j = 0;j<GL.numVertexes;j++){
        for(e = GL.adjList[j].firstedge;e;e = e->next){
            
        }
    }
}