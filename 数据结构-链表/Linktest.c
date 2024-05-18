#include<stdio.h>
#include<stdlib.h>
typedef struct Link
{
	int data;
	struct Link* next;
}Link;
Link* Creat_Link(int length)
{
	Link* head = (Link*)malloc(sizeof(Link));
	head->next = NULL;
	Link* end = head;
	for (int i = 0; i < length; i++)
	{
		Link* node= (Link*)malloc(sizeof(Link));
		node->data = i+1;
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}
int Find(Link* head, int num)
{
	int count = 0;
	Link* temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
		if (temp->data == num)
		{
			return count;
		}
	}
	return -1;
}
void InLink(Link* head, int num, int index)
{
	Link* temp = head;
	Link* node = (Link*)malloc(sizeof(Link));
	node->data = num;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	node->next = temp->next;
	temp->next = node;
}
void OutLink(Link* head, int index)
{
	Link* temp = head;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	Link* del = temp->next;
	temp->next = temp->next->next;
	free(del);
}
void Alterele(Link* head, int num, int index)
{
	Link* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	temp->data = num;
}
int Getlength(Link* head)
{
	Link* temp = head->next;
	int count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
int Getpre(Link* head, int num)
{
	Link* temp = head->next;
	if (num == temp->data)
	{
		return -1;
	}
	while (temp != NULL)
	{
		int pre = temp->data;
		if (num == temp->next->data)
		{
			return pre;
		}
		temp = temp->next;
	}
	return -1;
}
int Getnext(Link* head, int num)
{
	Link* temp = head->next;
	while (temp != NULL)
	{
		//int tmp = temp->data;
		if (temp->data == num)
		{
			temp = temp->next;
			//tmp = temp->data;
			return temp->data;
		}
		temp = temp->next;
	}
	return -1;
}
void Visit_Link(Link* head)
{
	Link* temp = head->next;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
Link* Alter_Link(Link* head)
{
	Link* phead = NULL;
	head = head->next;
	while (head != NULL)
	{
		Link* temp = head;
		head = head->next;
		temp->next = phead;
		phead = temp;
	}
	Link* Head = (Link*)malloc(sizeof(Link));
	Head->next = phead;
	return Head;
}
void Delete(Link* head)
{
	while (head != NULL)
	{
		Link* temp = head;
		head = head->next;
		free(temp);
	}
}
int main()
{
	Link* head = (Link*)malloc(sizeof(Link));
	//��ʼ��
	printf("β�巨��ʼ��\n");
	head = Creat_Link(10);
	//����
	printf("6��λ��Ϊ��%d\n", Find(head, 6));
	//����
	printf("����ǰ��");
	Visit_Link(head);
	InLink(head, 11, 11);
	printf("�����");
	Visit_Link(head);
	//ɾ��
	printf("ɾ��ǰ��");
	Visit_Link(head);
	OutLink(head, 1);
	printf("ɾ����");
	Visit_Link(head);
	//�޸�Ԫ��
	printf("�޸�ǰ��");
	Visit_Link(head);
	Alterele(head, 0, 1);
	printf("�޸ĺ�");
	Visit_Link(head);
	//��ȡ����
	printf("������Ϊ��%d\n", Getlength(head));
	//��ȡǰ��
	printf("4��ǰ��Ϊ��%d\n", Getpre(head, 4));
	//��ȡ���
	printf("4�ĺ��Ϊ��%d\n", Getnext(head, 4));
	//����
	printf("������");
	Visit_Link(head);
	//ͷ�巨
	printf("ʹ��ͷ�巨����������ת��\n");
	printf("��תǰ��");
	Visit_Link(head);
	printf("��ת��");
	Link* phead = Alter_Link(head);
	Visit_Link(phead);
	//β�巨

	//�������
	Delete(phead);
	

}