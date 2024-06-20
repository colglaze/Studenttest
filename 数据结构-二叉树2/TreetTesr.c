#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Tree
{
	struct Tree* lchild;
	struct Tree* rchild;
	int data;
}Tree;
typedef struct stack
{
	Tree* arr[100];
	int length;
}stack;
void pop(stack* s)
{
	if (s->arr[s->length] == NULL)
	{
		return;
	}
	printf("%d ", s->arr[s->length]->data);
	s->length--;
}
void push(stack* s,Tree* r)
{
	s->length++;
	s->arr[s->length] = r;
}
Tree* Creat_Tree()
{
	Tree* root = (Tree*)malloc(sizeof(Tree*));
	int num = 0;
	scanf_s("%d", &num);
	if (num == 0)
	{
		root = NULL;
		//return;
	}
	else
	{
		root->data = num;
		printf("请输入%d的左子树：", root->data);
		root->lchild = Creat_Tree();
		printf("请输入%d的右子树：", root->data);
		root->rchild = Creat_Tree();

	}
	return root;
}
void Mid_Visit(Tree* root)
{
	stack* s = (stack*)malloc(sizeof(stack*));
	s->length = -1;
	Tree* temp = root;
	while (temp != NULL || s->length != -1)
	{
		if (temp != NULL)
		{
			push(s, temp);
			temp = temp->lchild;
		}
		else
		{
			pop(s);
			//temp = s->top ->rchild;
			temp = s->arr[s->length+1]->rchild;
		}
	}
}
int main()
{
	Tree* root = Creat_Tree();
	//非递归中序遍历
	Mid_Visit(root);
}
