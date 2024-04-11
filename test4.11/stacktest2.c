/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
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
			printf("ƥ�����\n");
			break;
		}
		if (S.base == S.top)
		{
			printf("ƥ��ɹ���\n");
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!judge(&S1, arr2[i]))
		{
			printf("ƥ�����\n");
			break;
		}
		if (S1.base == S1.top)
		{
			printf("ƥ��ɹ���\n");
		}
	}
	return 0;
}