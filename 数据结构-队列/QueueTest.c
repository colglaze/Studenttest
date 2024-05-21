//ѭ������
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
		printf("����������\n");
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
		printf("�ӿգ�\n");
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
	//��ʼ��
	Queue* q;
	q = Creat_Queue(10);
	//����
	printf("����ǰ��");
	Visit_Queue(q);
	printf("����Ԫ��Ϊ��%d\n", Out_Queue(q));
	printf("���Ӻ�");
	Visit_Queue(q);
	//���
	printf("���ǰ��");
	Visit_Queue(q);
	printf("��Ӻ�");
	In_Queue(q, 10);
	Visit_Queue(q);
	
	//���ض��г���
	printf("���г���Ϊ��%d\n", Getlength(q));
	//����
	printf("������");
	Visit_Queue(q);
	//��ʽ��ʾ
	QueueL* ql;
	ql = Creat_QueueL(10);
	printf("���������");
	Visit_QueueL(ql);
	//�������
	Delete(q);
	/*for (int i = 0; i < 11; i++)
	{
		printf("%d ", *(q->base + i));
	}*/
}