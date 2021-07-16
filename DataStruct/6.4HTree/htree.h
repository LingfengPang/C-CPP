#ifndef BTREE_H
#define BTREE_H
#define N 30
typedef struct{
    char data;
    double weight;//权重
    int parent;//双亲节点
    int lchild;
    int rchild;
}HTNode;
typedef struct{
    char cd[N];//存放当前哈夫曼编码
    int start;//cd[star]~cd[n]存放哈夫曼编码
}HCode;

void createHT(HTNode ht[],int n);
void createHCode(HTNode ht[],HCode hcd[],int n);
#endif