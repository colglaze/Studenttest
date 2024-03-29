#include<stdio.h>
#include<stdlib.h>
typedef struct Link
{
	int date;
	struct Link* next;
}Link;
void Print(Link* head)
{	//��ӡ����ĺ���
	Link* temp = head->next;
	while (temp != NULL)
	{
		printf("%d ", temp->date);
		temp = temp->next;
	}
	printf("\n");
}
Link* Link_Judge(Link* head1, Link* head2)
{	//�������������������ĺ���
	Link* temp1 = head1->next ;
	Link* temp2 = head2->next ;
	Link* head3 ,*temp3;
	head3= temp3 = head1;//�½�һ���ڵ㣬�����������н�С�������ӵ�c��
	while (temp1  && temp2 )
	{
		//�������жϽ�Сֵ
		if (temp1->date < temp2->date )
		{
			temp3->next = temp1;
			temp3 = temp1;
			temp1 = temp1->next;
		}
		else if(temp1->date > temp2->date)
		{
			temp3->next = temp2;
			temp3 = temp2;
			temp2 = temp2->next;
		}
		else
		{	//�����������е�����ȣ���head1�еĽڵ����ӵ�head3�ϣ��ڽ�head2�еĸýڵ�ɾ��
			temp3->next = temp1;
			temp3 = temp1;
			temp1 = temp1->next;
			Link* p = temp2->next;
			free(temp2);
			temp2 = p;
		}
	}
	//��ʣ���Ԫ��ȫ���ӵ�head3��
	temp3->next = temp1 ? temp1 : temp2;
	//�ͷ�head2ͷ���Ŀռ�
	free(head2);
	return head3;
}
int main()
{
	//1:��������������������ϲ�Ϊһ����������������Ҫ����������ʹ��ԭ���Ŀռ�
	Link* head1 = (Link*)malloc(sizeof(Link));
	Link* head2 = (Link*)malloc(sizeof(Link));
	Link* end1 = (Link*)malloc(sizeof(Link));
	Link* end2 = (Link*)malloc(sizeof(Link));
	head1->next = NULL;
	head2->next = NULL;
	end1 = head1;
	end2 = head2;
	//ʹ��β�巨��ʼ����������
	for (int i = 1; i <= 19; i += 2)
	{
		Link* node = (Link*)malloc(sizeof(Link));
		node->date = i;
		end1->next = node;
		end1 = node;
	}
	end1->next = NULL;
	for (int i = 2; i <= 19; i += 2)
	{
		Link* node = (Link*)malloc(sizeof(Link));
		node->date = i;
		end2->next = node;
		end2 = node;
	}
	end2->next = NULL;
	printf("����δ���ӵ�����\n");
	Print(head1);
	Print(head2);
	head1=Link_Judge(head1, head2);
	printf("�����������յ�����������ӵ�һ��\n");
	Print(head1);
	return 0;
}
