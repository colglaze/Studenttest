//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Sqlist
//{
//	int* base;
//	int length;
//	int maxsize;
//}Sqlist;
//void StartSqlist(Sqlist s)
//{
//	for (int i = 0; i <s.maxsize ; i++)
//	{
//		*(s.base + i) = i;
//		s.length++;
//	}
//}
//void OutSqlist(Sqlist s,int i)
//{
//	for (int j = i; j < s.length - 2; j++)
//	{
//		*(s.base + j) = *(s.base + j + 1);
//	}
//	s.length--;
//}
//void InSqlist(int elme, Sqlist s, int place)
//{
//	if (s.length >= s.maxsize)
//	{
//		int* ss = (int*)realloc(s.base, 10 * sizeof(int));
//		s.base = ss;
//	}
//	for (int i = s.length - 1; i >= place; i--)
//	{
//		*(s.base + i + 1) = *(s.base + i);
//	}
//	*(s.base + place) = elme;
//	s.length++;
//}
//int IndexSqlist(Sqlist s ,int elme)
//{
//	for (int i = 0; i < s.length; i++)
//	{
//		if (elme == *(s.base + i))
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//DeleteSqlist(Sqlist s)
//{
//	free(s.base);
//	s.base = NULL;
//}
//AlterSqlist(Sqlist s, int num, int index)
//{
//	*(s.base + index) = num;
//}
//int getLength(Sqlist s)
//{
//	return s.length;
//}
//void AllseeSqlist(Sqlist s)
//{
//	for (int i = 0; i < s.length; i++)
//	{
//		printf("%d ", *(s.base + i));
//	}
//	printf("\n");
//}
//void SmallSqlist(Sqlist s, Sqlist q)
//{
//	for (int i = 0; i < s.length; i++)
//	{
//		for (int j = 0; j < q.length; j++)
//		{
//			if (*(s.base + i) != *(q.base + j))
//			{
//				OutSqlist(s, i);
//			}
//		}
//	}
//	AllseeSqlist(s);
//}
//void AllSqlist(Sqlist s,Sqlist q)
//{
//	for (int i = 0; i < s.length; i++)
//	{
//		for (int j = 0; j < q.length; j++)
//		{
//			if (!IndexSqlist(s, *(q.base + j)))
//			{
//				IndexSqlist(s, *(q.base + j));
//			}
//		}
//	}
//	AllseeSqlist(s);
//}
//int main()
//{
//	Sqlist s;
//	s.maxsize = 10;
//	s.base = (int*)malloc(sizeof(int) * s.maxsize);
//	Sqlist q;
//	q.maxsize = 10;
//	q.base = (int*)malloc(sizeof(int) * q.maxsize);
//	StartSqlist(q);
//	//顺序表的初始化
//	StartSqlist(s);
//	//顺序表的删除
//	OutSqlist(s,5);
//	//顺序表的插入
//	InSqlist(10,s,4);
//	//顺序表的查找
//	int temp = IndexSqlist(s,4);
//	printf("%d\n", temp);
//	//修改元素
//	AlterSqlist(s, 4, 4);
//	//获取线性表长度
//	temp = getLength(s);
//	printf("%d\n", temp);
//	// 遍历
//	AllseeSqlist(s);
//	// 两个集合的并集
//	AllSqlist(s, q);
//	// 两个集合的交集
//	SmallSqlist(s, q);
//	//顺序表的销毁
//	DeleteSqlist(s);
//}
#include <stdio.h>

#define MAX_SIZE 100

// 定义顺序表结构体
typedef struct {
    int data[MAX_SIZE];  // 用数组存储元素
    int length;          // 顺序表的长度
} SeqList;

// 初始化顺序表
void initSeqList(SeqList* list) {
    list->length = 0;
}

// 插入操作
int insert(SeqList* list, int position, int element) {
    if (position < 0 || position > list->length || list->length == MAX_SIZE) {
        return 0;  // 插入位置非法或顺序表已满，插入失败
    }

    // 将插入位置之后的元素依次后移一位
    for (int i = list->length - 1; i >= position; i--) {
        list->data[i + 1] = list->data[i];
    }

    // 在插入位置放入新元素
    list->data[position] = element;
    list->length++;

    return 1;  // 插入成功
}

// 删除操作
int delete(SeqList* list, int position) {
    if (position < 0 || position >= list->length) {
        return 0;  // 删除位置非法，删除失败
    }

    // 将删除位置之后的元素依次前移一位
    for (int i = position + 1; i < list->length; i++) {
        list->data[i - 1] = list->data[i];
    }

    list->length--;

    return 1;  // 删除成功
}

// 查找操作（按值查找）
int search(SeqList* list, int element) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == element) {
            return i;  // 找到元素，返回索引
        }
    }

    return -1;  // 未找到元素
}

// 修改操作
int modify(SeqList* list, int position, int newElement) {
    if (position < 0 || position >= list->length) {
        return 0;  // 修改位置非法，修改失败
    }

    list->data[position] = newElement;

    return 1;  // 修改成功
}

int main() {
    SeqList list;
    initSeqList(&list);

    // 在顺序表中插入元素
    insert(&list, 0, 10);
    insert(&list, 1, 20);
    insert(&list, 2, 30);

    // 删除顺序表中的元素
    delete(&list, 1);

    // 查找顺序表中的元素
    int index = search(&list, 30);
    if (index != -1) {
        printf("元素30的索引为：%d\n", index);
    }
    else {
        printf("未找到元素30\n");
    }

    // 修改顺序表中的元素
    modify(&list, 0, 40);

    return 0;
}