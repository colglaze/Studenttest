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
	//初始化
	printf("尾插法初始化\n");
	head = Creat_Link(10);
	//查找
	printf("6的位置为：%d\n", Find(head, 6));
	//插入
	printf("插入前：");
	Visit_Link(head);
	InLink(head, 11, 11);
	printf("插入后：");
	Visit_Link(head);
	//删除
	printf("删除前：");
	Visit_Link(head);
	OutLink(head, 1);
	printf("删除后：");
	Visit_Link(head);
	//修改元素
	printf("修改前：");
	Visit_Link(head);
	Alterele(head, 0, 1);
	printf("修改后：");
	Visit_Link(head);
	//获取长度
	printf("链表长度为：%d\n", Getlength(head));
	//获取前驱
	printf("4的前驱为：%d\n", Getpre(head, 4));
	//获取后继
	printf("4的后继为：%d\n", Getnext(head, 4));
	//遍历
	printf("遍历：");
	Visit_Link(head);
	//头插法
	printf("使用头插法将上述链表反转：\n");
	printf("反转前：");
	Visit_Link(head);
	printf("反转后：");
	Link* phead = Alter_Link(head);
	Visit_Link(phead);
	//尾插法

	//清空销毁
	Delete(phead);
	

}