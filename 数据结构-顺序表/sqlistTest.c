#include<stdio.h>
#include<stdlib.h>
typedef struct Sqlist
{
	int* base;
	int length;
}Sqlist;
Sqlist* Creat_Sqlist(int n)
{
	Sqlist* s = (Sqlist*)malloc(sizeof(Sqlist));
	s->base = (int*)malloc(sizeof(int) * 100);
	s->length = 0;
	for (int i = 0; i < n; i++)
	{
		*(s->base + i) = i + 1;
		s->length++;
	}
	return s;
}
int Find_ele(Sqlist* s,int num)
{
	return *(s->base + num - 1);
}
void In_Sqlist(int num, int index, Sqlist* s)
{
	for (int i = s->length - 1, j = 0; j < s->length - index + 1; j++, i--)
	{
		*(s->base + i + 1) = *(s->base + i);
	}
	*(s->base + index - 1) = num;
	s->length++;
}
void Alter_Sqlist(Sqlist* s, int num, int index)
{
	*(s->base + index - 1) = num;
}
void Delete_Sqlist(Sqlist* s, int index)
{
	for (int i = index - 1; i < s->length; i++)
	{
		*(s->base + i) = *(s->base + i + 1);
	}
	s->length--;
}
int Getlength(Sqlist* s)
{
	return s->length;
}
int Getpre(Sqlist* s, int num)
{
	if (num == *(s->base))
	{
		return -1;
	}
	int temp = 0;
	for (int i = 1; i < s->length; i++)
	{
		temp = *(s->base + i - 1);
		if (*(s->base + i) == num)
		{
			break;
		}
	}
	return temp;
}
int Getafter(Sqlist* s, int num)
{
	if (*(s->base + s->length - 1) == num)
	{
		return -1;
	}
	for (int i = 0; i < s->length; i++)
	{
		if (*(s->base + i) == num)
		{
			return *(s->base + i + 1);
		}
	}
}
void Visit_Sqlist(Sqlist* s)
{
	for (int i = 0; i < s->length; i++)
	{
		printf("%d ", *(s->base + i));
	}
	printf("\n");
}
void All_Sqlist(Sqlist* s, Sqlist* q)
{
	for (int i = 0; i < s->length; i++)
	{
		printf("%d ", *(s->base + i));
	}
	int max = s->length > q->length ? s->length : q->length;
	for (int i = 0; i < max; i++)
	{
		int isFlage = 1;
		for (int j = 0; j < max; j++)
		{
			if (*(s->base + j) == *(q->base + i))
			{
				isFlage = 0;
			}
		}
		if (isFlage)
		{
			printf("%d ", *(q->base + i));
		}
	}
	printf("\n");
}
void Same_Sqlist(Sqlist* s, Sqlist* q)
{
	for (int i = 0; i < q->length; i++)
	{
		for (int j = 0; j < s->length; j++)
		{
			if (*(s->base + j) == *(q->base + i))
			{
				printf("%d ", *(q->base + i));
			}
		}
	}
	printf("\n");
}
void Delete(Sqlist* s)
{
	free(s->base);
	free(s);
}
void Zero(Sqlist* s)
{
	for (int i = 0; i < s->length; i++)
	{
		*(s->base + i) = 0;
	}
}
int main()
{
	Sqlist* s;
	//初始化
	s = Creat_Sqlist(10);
	//查找元素
	int num = Find_ele(s,3);
	printf("第三个元素为：%d\n", num);
	//插入元素
	printf("插入前：");
	Visit_Sqlist(s);
	In_Sqlist(11, 6, s);
	printf("插入后：");
	Visit_Sqlist(s);
	//修改元素
	printf("修改前：");
	Visit_Sqlist(s);
	Alter_Sqlist(s, 0, 1);
	printf("修改后：");
	Visit_Sqlist(s);
	//删除元素
	printf("删除前：");
	Visit_Sqlist(s);
	Delete_Sqlist(s, 3);
	printf("删除后：");
	Visit_Sqlist(s);
	//获取长度
	printf("长度为：%d\n", Getlength(s));
	//获取前驱
	printf("5前驱为：%d\n", Getpre(s,5));
	//获取后继
	printf("5后继为：%d\n", Getafter(s, 5));
	//遍历
	printf("遍历：");
	Visit_Sqlist(s);
	//两个集合并集
	printf("并集：");
	Sqlist* q;
	q= Creat_Sqlist(10);
	All_Sqlist(s, q);
	//两个集合交集
	printf("交集：");
	Same_Sqlist(s, q);
	//清空
	printf("清零：");
	Zero(s);
	Visit_Sqlist(s);
	//销毁
	Delete(s);
	
}   
