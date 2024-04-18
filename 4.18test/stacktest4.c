//leetcode 回文字符串
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct Stack
{
	char* base;
	char* top;
	int maxmize;
}stack;
void pushstack(stack* s, char p)
{
	*(s->top) = p;
	s->top++;
}
char popstack(stack* s)
{
	s->top--;
	return *(s->top);
}
void judge(char* p, int n, stack* s)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < n / 2; i++)
	{
		pushstack(s, *(p + i));
	}
	j = --i;
	if (n % 2 != 0)
	{
		i+=2;
		k = i;
	}
	else
	{
		k = i+1;
	}
	for (i = 0; i < n / 2; i++)
	{
		if (popstack(s) != *(p + k))
		{
			printf("%s 非回文\n",p);
			return;
		}
		k++;

	}
	printf("%s 回文\n",p);
}
int main()
{
	stack s1;
	s1.maxmize = 10;
	s1.base = (char*)malloc(sizeof(char) * s1.maxmize);
	s1.top = s1.base;
	char arr1[6] = "abcba";
	char arr2[5] = "abba";
	char arr3[5] = "abcd";
	judge(arr1, strlen(arr1),&s1);
	judge(arr2, strlen(arr2), &s1);
	judge(arr3, strlen(arr3), &s1);
	return 0;
}