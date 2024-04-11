/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack
{
	char* base;
	char* top;
	int maxsize;
}stack;
void InStack(stack* S, char a)
{
	*(S->top) = a;
	(S->top)++;
}
char OutStack(stack* S)
{
	char a;
	(S->top)--;
	a = *(S->top);
	
	return a;
}
bool judge(stack* S, char a)
{
	if (a == '(' || a == '{' || a == '[')
	{
		InStack(S, a);
	}
	else if(a == ')' || a == '}' || a == ']')
	{
		char b = OutStack(S);
		if ((a == ')' && b == '(') || (a == ']' && b == '[') || (a == '}' && b == '{'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	stack S;
	S.maxsize = 10;
	S.base = (char*)malloc(sizeof(char) * S.maxsize);
	S.top = S.base;
	stack S1;
	S1.maxsize = 10;
	S1.base = (char*)malloc(sizeof(char) * S1.maxsize);
	S1.top = S1.base;
	char arr1[8] = { "{([][])}" };
	char arr2[4] = { "[{})" };
	for (int i = 0; i < 8; i++)
	{
		if (!judge(&S, arr1[i]))
		{
			printf("匹配错误！\n");
			break;
		}
		if (S.base == S.top)
		{
			printf("匹配成功！\n");
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!judge(&S1, arr2[i]))
		{
			printf("匹配错误！\n");
			break;
		}
		if (S1.base == S1.top)
		{
			printf("匹配成功！\n");
		}
	}
	return 0;
}