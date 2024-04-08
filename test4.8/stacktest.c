#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
	int* bottom;
	int* top;
	int stacksize;
}stack;
int main()
{
	stack S;
	S.stacksize = 10;
	S.bottom = (stack*)malloc(sizeof(stack) * S.stacksize);
	S.top = S.bottom;
	for (int i = 0; i < S.stacksize; i++)
	{
		if (S.top - S.bottom < S.stacksize)
		{
			*(S.top) = i;
			S.top++;
		}
		else
		{
			printf("´ËÕ»ÒÑÂú£¡\n");
		}
	}
	while (S.bottom != S.top)
	{
		S.top--;
		printf("%d ", *(S.top));
	}
	return 0;
}