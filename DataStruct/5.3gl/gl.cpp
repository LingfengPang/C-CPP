#include <stdio.h>
#include "gl.h"
#include <windows.h>
GLNode * CreateGl(char *&s){
    GLNode *g;
    char ch =*s++;//取第一个字符
    if(ch!='\0'){
        g = (GLNode*)malloc(sizeof(GLNode));
        if(ch == '('){
            g->tag = 1;//新节点作为表头节点
            g->val.sublist = CreateGl(s);//创建一个新节点 
        }
        else if(ch == ')'){
            g = NULL;
        }
        else if(ch == '#'){
            g = NULL;
        }//表示空表
        else{//原子字符
            g->tag = 0;
            g->val.data = ch;
        }
    }
    else
        g = NULL;
    ch =*s++;
    if(g!=NULL){
        if(ch==','){
            g->link = CreateGl(s);//递归构造兄弟节点
        }
        else 
            g->link = NULL;
    }
    return g;
}

int GLLength(GLNode *g){
    int n = 0;
    GLNode *gl;
    gl = g->val.sublist;
    while(gl!=NULL){
        n++;
        gl = gl->link;
    }
    return n;
}
int GLDepth(GLNode *g){
    GLNode *gl;
    int max = 0;
    int dep;
    if(g->tag == 0){
        return 0;
    }
    gl = g->val.sublist;
    if(gl == NULL)
        return 1;
    while(gl!=NULL){
        if(gl->tag == 1){
            dep = GLDepth(gl);
            if(dep > max)
                max = dep;
        }
        gl = gl->link;
    }
    return (max+1);
}