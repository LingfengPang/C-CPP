# 树

[本文参考](https://blog.csdn.net/qq_44864262/article/details/107208455)
## 双亲表示法
找双亲容易，找孩子难
```cpp
typedef struct PTNode
{
	TElemType data;
	int parent;//双亲位置域
}PTNode;

#define MAX_TREE_SIZE 100
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;//根结点的位置和结点个数
}PTree;

```

## 孩子链表
把每个结点的孩子结点排列起来，看成是一个线性表，用单链表存储。n个结点有n个孩子链表（叶子的孩子链表为空表）。而n个头指针又组成了一个线性表，用顺序表（含n个元素的结构数组）存储。
```cpp
typedef struct CTNode//孩子结点结构
{
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct CTBox//双亲结点结构
{
	TElemType data;
	ChildPtr firstchild;//孩子链表头指针
}CTBox;
typedef struct CTree
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;//结点数和根结点的位置
}CTree;
```

## 孩子兄弟表示法
```cpp
typedef struct CSNode
{
	ElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;
```

