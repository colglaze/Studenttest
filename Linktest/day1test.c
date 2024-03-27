#include<stdio.h>
#include<stdlib.h>
typedef struct Link
{
	int date;
	struct Link* next;
}Link;
void PRINT(Link* temp)
{
	while (temp != NULL)
	{
		printf("%d ", temp->date);
		temp = temp->next;
	}
	printf("\n");
}
void Link_in(Link* node, Link* head,int n)
{
	Link* tmp = head;
	for (int i = 0; i < n-1; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL)
		{
			printf("��������\n");
			break;
		}
	}
	node->next = tmp->next;
	tmp->next = node;
}
void Link_out(Link* head, int n)
{
	Link* tmp = head;
	for (int i = 0; i < n - 1; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL)
		{
			printf("��������\n");
			break;
		}
	}
	tmp->next = tmp->next->next;
	tmp = tmp->next;
}
void Link_del(Link* head)
{
	Link* head1 = head;
	Link* temp = head;
	while (head1)
	{
		temp = head1->next;
		free(head1);
		head1 = temp;
	}
}
 Link* Link_backspin(Link* head1)
{
	Link* temp = NULL;
	Link* phead = NULL;
	head1 = head1->next;
	while (head1 != NULL)
	{
		temp = head1;
		head1 = head1->next;
		temp->next = phead;
		phead = temp;
	}
	return phead;
}
int main()
{
	int i, x = 0;
	Link* head = (Link*)malloc(sizeof(Link));
	head->next = NULL;//�˴����Ա�֤β���һ����NULLָ��
	//���½�дͷ�巨����������
	printf("ͷ�巨����������\n");
	for (i = 0; i < 10; i++)
	{
		Link* node= (Link*)malloc(sizeof(Link));
		scanf_s("%d", &x);
		node->date = x;
		node->next = head->next;
		head->next = node;
	}
	//�Ե�����ı���
	Link* temp = head->next;
	PRINT(temp);
	//����һ��Ԫ��
	
	Link* node = (Link*)malloc(sizeof(Link));
	node->date = 566;
	scanf_s("%d", &x);
	printf("��%d������һ��Ԫ��\n",x);
	Link_in(node, head,x);
	 temp = head->next;
	PRINT(temp);
	//ɾ���ڵ�
	printf("ɾ���ڵ�%d\n", x);
	Link_out(head, x);
	temp = head->next;
	PRINT(temp);
	//�������
	Link_del(head);
	/*PRINT(head);*/
	//��������β�巨��������
	printf("β�巨��������\n");
	Link* end = (Link*)malloc(sizeof(Link));
	Link* head1 = (Link*)malloc(sizeof(Link));
	head1->next = NULL;
	end = head1;
	for (i = 0; i < 10; i++)
	{
		Link* node = (Link*)malloc(sizeof(Link));
		scanf_s("%d", &x);
		node->date = x;
		end->next = node;
		end = node;
	}
	end->next = NULL;//��֤��βָ��ָ��NULL
	temp = head1->next;
	PRINT(temp);
	//������������������ת
	printf("��ת����\n");
	Link* head2 = (Link*)malloc(sizeof(Link));
	head2->next =Link_backspin(head1);
	temp = head2->next;
	PRINT(temp);
	return 0;
}