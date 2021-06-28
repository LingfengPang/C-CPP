#ifndef GL_H
#define GL_H
//广义表
typedef char Elemtype;
typedef struct lnode
{
    /* data */
    int tag;//节点标识类型
    union{
        Elemtype data;//原子值
        struct lnode *sublist;//指向子表的指针
    }val;
    struct lnode *link;//指向下一个元素
}GLNode;
GLNode * CreateGl(char *&s);
int GLLength(GLNode *g);
#endif