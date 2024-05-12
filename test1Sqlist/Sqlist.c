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
//	//˳���ĳ�ʼ��
//	StartSqlist(s);
//	//˳����ɾ��
//	OutSqlist(s,5);
//	//˳���Ĳ���
//	InSqlist(10,s,4);
//	//˳���Ĳ���
//	int temp = IndexSqlist(s,4);
//	printf("%d\n", temp);
//	//�޸�Ԫ��
//	AlterSqlist(s, 4, 4);
//	//��ȡ���Ա���
//	temp = getLength(s);
//	printf("%d\n", temp);
//	// ����
//	AllseeSqlist(s);
//	// �������ϵĲ���
//	AllSqlist(s, q);
//	// �������ϵĽ���
//	SmallSqlist(s, q);
//	//˳��������
//	DeleteSqlist(s);
//}
#include <stdio.h>

#define MAX_SIZE 100

// ����˳���ṹ��
typedef struct {
    int data[MAX_SIZE];  // ������洢Ԫ��
    int length;          // ˳���ĳ���
} SeqList;

// ��ʼ��˳���
void initSeqList(SeqList* list) {
    list->length = 0;
}

// �������
int insert(SeqList* list, int position, int element) {
    if (position < 0 || position > list->length || list->length == MAX_SIZE) {
        return 0;  // ����λ�÷Ƿ���˳�������������ʧ��
    }

    // ������λ��֮���Ԫ�����κ���һλ
    for (int i = list->length - 1; i >= position; i--) {
        list->data[i + 1] = list->data[i];
    }

    // �ڲ���λ�÷�����Ԫ��
    list->data[position] = element;
    list->length++;

    return 1;  // ����ɹ�
}

// ɾ������
int delete(SeqList* list, int position) {
    if (position < 0 || position >= list->length) {
        return 0;  // ɾ��λ�÷Ƿ���ɾ��ʧ��
    }

    // ��ɾ��λ��֮���Ԫ������ǰ��һλ
    for (int i = position + 1; i < list->length; i++) {
        list->data[i - 1] = list->data[i];
    }

    list->length--;

    return 1;  // ɾ���ɹ�
}

// ���Ҳ�������ֵ���ң�
int search(SeqList* list, int element) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == element) {
            return i;  // �ҵ�Ԫ�أ���������
        }
    }

    return -1;  // δ�ҵ�Ԫ��
}

// �޸Ĳ���
int modify(SeqList* list, int position, int newElement) {
    if (position < 0 || position >= list->length) {
        return 0;  // �޸�λ�÷Ƿ����޸�ʧ��
    }

    list->data[position] = newElement;

    return 1;  // �޸ĳɹ�
}

int main() {
    SeqList list;
    initSeqList(&list);

    // ��˳����в���Ԫ��
    insert(&list, 0, 10);
    insert(&list, 1, 20);
    insert(&list, 2, 30);

    // ɾ��˳����е�Ԫ��
    delete(&list, 1);

    // ����˳����е�Ԫ��
    int index = search(&list, 30);
    if (index != -1) {
        printf("Ԫ��30������Ϊ��%d\n", index);
    }
    else {
        printf("δ�ҵ�Ԫ��30\n");
    }

    // �޸�˳����е�Ԫ��
    modify(&list, 0, 40);

    return 0;
}