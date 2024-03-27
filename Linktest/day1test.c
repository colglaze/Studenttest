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
			printf("超出长度\n");
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
			printf("超出长度\n");
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
	head->next = NULL;//此处可以保证尾结点一定是NULL指针
	//以下将写头插法创建单链表
	printf("头插法创建单链表\n");
	for (i = 0; i < 10; i++)
	{
		Link* node= (Link*)malloc(sizeof(Link));
		scanf_s("%d", &x);
		node->date = x;
		node->next = head->next;
		head->next = node;
	}
	//对单链表的遍历
	Link* temp = head->next;
	PRINT(temp);
	//插入一个元素
	
	Link* node = (Link*)malloc(sizeof(Link));
	node->date = 566;
	scanf_s("%d", &x);
	printf("在%d处插入一个元素\n",x);
	Link_in(node, head,x);
	 temp = head->next;
	PRINT(temp);
	//删除节点
	printf("删除节点%d\n", x);
	Link_out(head, x);
	temp = head->next;
	PRINT(temp);
	//清空链表
	Link_del(head);
	/*PRINT(head);*/
	//接下来是尾插法创建链表
	printf("尾插法创建链表\n");
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
	end->next = NULL;//保证结尾指针指向NULL
	temp = head1->next;
	PRINT(temp);
	//接下来将上述链表逆转
	printf("逆转链表\n");
	Link* head2 = (Link*)malloc(sizeof(Link));
	head2->next =Link_backspin(head1);
	temp = head2->next;
	PRINT(temp);
	return 0;
}