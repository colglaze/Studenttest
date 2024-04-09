#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
	int* base;
	int rear;
	int front;
	int maxsize;
}queue;
int main()
{
	queue Q;
	Q.maxsize = 10;
	Q.base = (int*)malloc(sizeof(int) * Q.maxsize);
	Q.front = Q.rear = 0;
	for (int i = 0; i < Q.maxsize; i++)
	{
		*(Q.base + Q.rear) = i;
		Q.rear++;
	}
	while (Q.front != Q.rear )
	{
		int x = *(Q.base + Q.front);
		Q.front++;
		printf("%d ", x);
	}
}