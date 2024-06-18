#include<stdio.h>
#include<stdlib.h>
typedef struct String
{
	char* arr;
	int length;
}String;
String* Creat_String(int size)
{
	String* s = (String*)malloc(sizeof(String));
	s->length = 0;
	s->arr = (char*)malloc(sizeof(char) * size);
	return s;
}
void Addele(String* s, char x)
{
	*(s->arr+s->length) = x;
	s->length++;
}
int Getlength(String* s)
{
	return s->length;
}
void Delete(String* s, int index)
{
	for (int i = 0; i < s->length - index; i++)
	{
		*(s->arr + index - 1 + i) = *(s->arr + index + i);
	}
	s->length--;
}
char Getele(String* s, int index)
{
	return *(s->arr + index - 1);
}
void All_Visit(String* s)
{
	for (int i = 0; i < s->length; i++)
	{
		printf("%c ", *(s->arr + i));
	}
	printf("\n");
}
void Compter(char arr0[], char arr1[])
{
	int i = 0; 
	while (arr1[i])
	{
		int isFlage = 1;
		if (arr1[i] == arr0[0])
		{
			for (int j = 1; j < 4; j++)
			{
				if (arr1[i + j] != arr0[j])
				{
					isFlage = 0;
					break;
				}
			}
			if (isFlage == 1)
			{
				printf("%s 在 %s 中的起始位置为：%d\n", arr0, arr1, i+1);
				return;
			}
		}
		i++;
		
	}
	printf("未找到该字符串!\n");
}
int main()
{
	//初始化
	String* s;
	s = Creat_String(20);
	//添加元素
	char ele = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%c", &ele,1);
		Addele(s,ele);
	}
	

	//获取元素
	printf("第三个元素为：%c\n", Getele(s, 3));
	//删除元素
	printf("删除前:\n"); All_Visit(s);
	Delete(s, 3);
	printf("删除后:\n"); All_Visit(s);
	//获取长度
	printf("该串的长度为：%d\n", Getlength(s));
	//遍历
	printf("遍历：");
	All_Visit(s);
	//暴力算法
	char arr0[] = "abcdababedab";
	char arr1[] = "abab";
	Compter(arr1, arr0);
	
	//kmp算法

	//销毁
	return 0;
}