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
	//��ʼ��
	s=Creat_Static();
	//��ջ
	printf("��ջǰ��");
	Visit_Static(s);
	Instatic(s,11);
	printf("��ջ��");
	Visit_Static(s);
	//��ջ
	printf("��ջǰ��");
	Visit_Static(s);
	Popstatic(s);
	printf("��ջ��");
	Visit_Static(s);
	//ȡջ��Ԫ��
	printf("ջ��Ԫ��Ϊ��%d\n", Topele(s));
	//����
	printf("˳�����������");
	Visit_Static(s);
	//˳����ʾ

	//�����ʾ
	LStatic* ls;
	printf("������������");
	ls = Creat_LStatic();
	Visit_LS(ls);
	//����
	DeleteS(s);
	//
}