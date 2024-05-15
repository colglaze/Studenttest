#include<stdio.h>
#include<stdlib.h>
typedef struct Tree
{
	int data;
	struct Tree* lchild;
	struct Tree* rchild;
}Tree;
Tree* Creat_Tree()
{
	Tree* r = (Tree*)malloc(sizeof(Tree));
	int num = 0;
	scanf_s("%d", &num);
	if (num == 0)
	{
		r = NULL;
	}
	else
	{
		r->data = num;
		printf("输入%d左子树\n",r->data);
		r->lchild = Creat_Tree();
		printf("输入%d右子树\n",r->data);
		r->rchild = Creat_Tree();
	}
	return r;
}
void VisitTree(Tree* r)
{
	if (r == NULL)
	{
		return;
	}
	printf("%d ", r->data);
	VisitTree(r->lchild);
	VisitTree(r->rchild);
}
int main()
{
	Tree* root;
	root = Creat_Tree();
	VisitTree(root);
	return 0;
}
