#include<stdio.h>
#include<stdlib.h>
typedef struct Static
{
	int maxsize;
	int length;
	int* base;
	int* top;
}Static;
Static* Creat_Static()
{
	Static* s = (Static*)malloc(sizeof(Static));
	s->maxsize = 15;
	s->length = 0;
	s->base = (int*)malloc(sizeof(int) * s->maxsize);
	s->top = s->base;
	for (int i = 0; i < 10; i++)
	{
		*(s->top) = i + 1;
		s->top++;
		s->length++;
	}
	return s;
}
void Instatic(Static* s, int num)
{
	if (s->length >= s->maxsize)
	{
		int* temp = (int*)realloc(s->base, s->maxsize * 2);
		s->base = temp;
		s->top = s->base + s->length + 1;
	}
	*(s->top) = num;
	s->top++;
	s->length++;
}
void Popstatic(Static* s)
{
	s->top--;
	s->length--;
}
int Topele(Static* s)
{
	return *(s->top - 1);
}
void Visit_Static(Static* s)
{
	for (int i = 0; i < s->length; i++)
	{
		printf("%d ", *(s->base + i));
	}
	printf("\n");
}
typedef struct Link
{
	int data;
	struct Link* next;
}Link;
typedef struct LinkStatic
{
	Link* node;
	Link* top;
	Link* base;
	int length;
}LStatic;
LStatic* Creat_LStatic()
{
	LStatic* ls = (LStatic*)malloc(sizeof(LStatic));
	ls->base= (LStatic*)malloc(sizeof(LStatic));
	ls->base->next = NULL;
	ls->length = 0;
	for (int i = 0; i < 10; i++)
	{
		ls->node= (LStatic*)malloc(sizeof(LStatic));
		ls->node->data = i + 1;
		ls->node->next = ls->base->next;
		ls->base->next = ls->node;
	}
	ls->top = ls->base + 10;
	return ls;
}
void Visit_LS(LStatic* ls)
{
	Link* temp = ls->base->next;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void DeleteS(Static* s)
{
	s->top = s->base;
}
int main()
{
	Static* s;
	//初始化
	s=Creat_Static();
	//入栈
	printf("入栈前：");
	Visit_Static(s);
	Instatic(s,11);
	printf("入栈后");
	Visit_Static(s);
	//出栈
	printf("出栈前：");
	Visit_Static(s);
	Popstatic(s);
	printf("出栈后：");
	Visit_Static(s);
	//取栈顶元素
	printf("栈顶元素为：%d\n", Topele(s));
	//遍历
	printf("顺序表创建遍历：");
	Visit_Static(s);
	//顺序表表示

	//链表表示
	LStatic* ls;
	printf("链表创建遍历：");
	ls = Creat_LStatic();
	Visit_LS(ls);
	//销毁
	DeleteS(s);
	//
}