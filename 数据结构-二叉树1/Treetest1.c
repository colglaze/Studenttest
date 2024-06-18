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
	Tree* root = (Tree*)malloc(sizeof(Tree));
	int num = 0;
	scanf_s("%d", &num);
	if (num == 0)
	{
		root = NULL;
	}
	else
	{
		root->data = num;
		printf("������%d��������:", root->data);
		root->lchild = Creat_Tree();
		printf("������%d��������:", root->data);
		root->rchild = Creat_Tree();
	}
	return root;
}
void FVisit_Tree(Tree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", root->data);
		FVisit_Tree(root->lchild);
		FVisit_Tree(root->rchild);
	}
}
void MVisit_Tree(Tree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		FVisit_Tree(root->lchild);
		printf("%d ", root->data);
		FVisit_Tree(root->rchild);
	}
}
void LVisit_Tree(Tree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		FVisit_Tree(root->lchild);
		FVisit_Tree(root->rchild);
		printf("%d ", root->data);
	}
}
int main()
{
	Tree* root;
	root = Creat_Tree();
	printf("���������\n");
	FVisit_Tree(root);
	printf("\n");
	printf("���������\n");
	MVisit_Tree(root);
	printf("\n");
	printf("���������\n");
	LVisit_Tree(root);
}