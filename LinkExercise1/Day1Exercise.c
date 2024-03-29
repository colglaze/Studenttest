#include<stdio.h>
#include<stdlib.h>
typedef struct Link
{
	int date;
	struct Link* next;
}Link;
void Print(Link* head)
{	//打印链表的函数
	Link* temp = head->next;
	while (temp != NULL)
	{
		printf("%d ", temp->date);
		temp = temp->next;
	}
	printf("\n");
}
Link* Link_Judge(Link* head1, Link* head2)
{	//将两个链表连接起来的函数
	Link* temp1 = head1->next ;
	Link* temp2 = head2->next ;
	Link* head3 ,*temp3;
	head3= temp3 = head1;//新建一个节点，将两个链表中较小的数连接到c中
	while (temp1  && temp2 )
	{
		//以下是判断较小值
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
		{	//如若两个表中的数相等，则将head1中的节点连接到head3上，在将head2中的该节点删除
			temp3->next = temp1;
			temp3 = temp1;
			temp1 = temp1->next;
			Link* p = temp2->next;
			free(temp2);
			temp2 = p;
		}
	}
	//将剩余的元素全部接到head3上
	temp3->next = temp1 ? temp1 : temp2;
	//释放head2头结点的空间
	free(head2);
	return head3;
}
int main()
{
	//1:将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来的空间
	Link* head1 = (Link*)malloc(sizeof(Link));
	Link* head2 = (Link*)malloc(sizeof(Link));
	Link* end1 = (Link*)malloc(sizeof(Link));
	Link* end2 = (Link*)malloc(sizeof(Link));
	head1->next = NULL;
	head2->next = NULL;
	end1 = head1;
	end2 = head2;
	//使用尾插法初始化两个链表
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
	printf("两个未连接的链表\n");
	Print(head1);
	Print(head2);
	head1=Link_Judge(head1, head2);
	printf("将两个链表按照递增排序后连接到一起\n");
	Print(head1);
	return 0;
}
