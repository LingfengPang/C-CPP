#include <iostream>
typedef struct Tnode
{
	char data;
	struct Tnode *lnode;
	struct Tnode *rnode;
}Tnode;
typedef  Tnode* type;
Tnode *norecur_createtree6(char a[], int alen, char b[])
{//此算法经过最终测试，对于大多数的实例都有完美的准确度，不过是非平衡树的时候就会出错。
//改进思路：在判断出其左孩子和右孩子为空后记录个数，并将其补为完全二叉树，根据下标对应关系赋值
	Tnode *root[7];
	for (int i = 0; i < alen; i++)
	{
		root[i] = (Tnode *)malloc(sizeof(Tnode));
		if (root[i])//分配动态空间成功
		{
			root[i]->data = a[i];
			root[i]->lnode = root[i]->rnode=NULL;
		}
		else
			exit(-1);
	}
	int i = 0;
	while (i<alen-1)
	{
		int k = 0;
		int j = 0;
		int m = 0;
		int  save;
		int tem;
		for (; b[k] != a[i + 1]; k++);
			for (; b[j] != a[i]; j++);
			if (i == 0)
				save = j;
			//给根节点创建左子树
			int flag = 0;
			if (j>k)
			{
				root[i]->lnode = root[i+1];

			}
			else
			{
				root[i]->lnode = NULL;
				flag = 1;//说明其左子树为空
			}
			//给根节点创建右子树			
			for (tem = (i > save ? j+1: j + 1 + i); b[m] != a[tem]; m++);
			if (m > j&&!flag&&m<alen)
			{
				root[i]->rnode = root[tem];
			}
			else if (flag&&a[i+1]==b[j+1])//如果左子树为空再判断中序和前序序列中当前节点的下一个节点是否一致，如果是，说明下一个节点就是其右孩子，如果不是则说明其没有右孩子
				root[i]->rnode = root[1 + i];
			else
				root[i]->rnode = NULL;
			i++;
		}
	return root[0];
}

Tnode *createtree6(char a[], int n1,int m1,char b[],int n2,int m2)
{
	Tnode *root = (Tnode *)malloc(sizeof(Tnode));
	if (root)//分配动态空间成功
		root->data = a[n1];
	else
		exit(-1);
	int i,llen,rlen;
	i = llen = rlen = 0;
	for (; b[i] != a[n1]; i++);//找到根节点在中序序列的下标i;
	llen = i - n2;//说明要以当前root为根节点对需要建树的序列b左子树长
	rlen = m2 - i;//说明要以当前root为根节点对需要建树的序列b右子树长
	if (llen&&(root->lnode = createtree6(a, n1+1, n1+llen, b, n2, n2+llen-1) ));//当左子树长不为零时建左子树
	else  root->lnode = NULL;//新的建树序列（新的中序序列）对应b的起始下标n2，结束下标n2+len-1;新的参考序列(新的先序序列)对应a的起始坐标n1+1,结束坐标n1+len;
		if(rlen  && (root->rnode = createtree6(a,m1-rlen+1, m1, b, m2-rlen+1, m2)));//当右子树长不为零时建右子树
    else  root->rnode = NULL;//新的建树序列（新的中序序列）对应b的起始下标m2-rlrn+1，结束下标m2;新的参考序（新的先序序列）列对应a的起始坐标m1-rlen+1,结束坐标m1;
		return root;
}


