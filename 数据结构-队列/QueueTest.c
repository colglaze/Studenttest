//循环队列
#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
	int* base;
	int front;
	int rear;
	int maxsize;
}Queue;
Queue* Creat_Queue(int size)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->base = (int*)malloc(sizeof(int) * (size + 1));
	q->maxsize = size + 1;
	q->rear = q->front = 0;
	for (int i = 0; i < q->maxsize-2; i++)
	{
		*(q->base + q->rear) = i + 1;
		q->rear++;
	}
	return q;
}
void In_Queue(Queue* q, int num)
{
	if (q->front == (q->rear + 1) % q->maxsize)
	{
		printf("队列已满！\n");
	}
	else
	{
		if (q->maxsize == q->rear)
		{
			q->rear = (q->rear + 1) % q->maxsize;
			*(q->base + q->rear) = num;
			
		}
		else
		{
			*(q->base + q->rear) = num;
			q->rear++;
		}
	}
}
int Out_Queue(Queue* q)
{
	int num = 0;
	if (q->front == q->rear)
	{
		printf("队空！\n");
	}
	else
	{
		num = *(q->base + q->front);
		q->front = (q->front + 1) % q->maxsize;
	}
	return num;
}
int Getlength(Queue* q)
{
	if (q->rear - q->front >= 0)
	{
		return q->rear - q->front;
	}
	else
	{
		return q->maxsize - (q->front - q->rear - 1);
	}
}
void Visit_Queue(Queue* q)
{
	int i = q->front;	while (i < q->rear)
	{
		printf("%d ", *(q->base + i));
		i = (i + 1) % q->maxsize;
	}
	printf("\n");
}
typedef struct Link
{
	int data;
	struct Link* next;
}Link;
typedef struct QueueLink
{
	Link* front;
	Link* rear;
	
}QueueL;
QueueL* Creat_QueueL(int size)
{
	QueueL* ql= (QueueL*)malloc(sizeof(QueueL));
	ql->front = (Link*)malloc(sizeof(Link));
	ql->rear = ql->front;
	for (int i = 0; i < size - 1; i++)
	{
		Link* node= (Link*)malloc(sizeof(Link));
		node->data = i + 1;
		ql->rear->next = node;
		ql->rear = node;
	}
	ql->rear->next = NULL;
	return ql;
	
}
void Visit_QueueL(QueueL* ql)
{
	Link* temp = ql->front->next;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void Delete(Queue* q)
{
	q->rear = q->front = 0;
}
int main()
{
	//初始化
	Queue* q;
	q = Creat_Queue(10);
	//出队
	printf("出队前：");
	Visit_Queue(q);
	printf("出队元素为：%d\n", Out_Queue(q));
	printf("出队后：");
	Visit_Queue(q);
	//入队
	printf("入队前：");
	Visit_Queue(q);
	printf("入队后：");
	In_Queue(q, 10);
	Visit_Queue(q);
	
	//返回队列长度
	printf("队列长度为：%d\n", Getlength(q));
	//遍历
	printf("遍历：");
	Visit_Queue(q);
	//链式表示
	QueueL* ql;
	ql = Creat_QueueL(10);
	printf("链表遍历：");
	Visit_QueueL(ql);
	//清空销毁
	Delete(q);
	/*for (int i = 0; i < 11; i++)
	{
		printf("%d ", *(q->base + i));
	}*/
}