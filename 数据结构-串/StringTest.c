#include<stdio.h>
#include<stdlib.h>
typedef struct String
{
	char* arr;
	int length;
}String;
String* Creat_String(int size)
{
	String* s = (String*)malloc(sizeof(String));
	s->length = 0;
	s->arr = (char*)malloc(sizeof(char) * size);
	return s;
}
void Addele(String* s, char x)
{
	*(s->arr+s->length) = x;
	s->length++;
}
int Getlength(String* s)
{
	return s->length;
}
void Delete(String* s, int index)
{
	for (int i = 0; i < s->length - index; i++)
	{
		*(s->arr + index - 1 + i) = *(s->arr + index + i);
	}
	s->length--;
}
char Getele(String* s, int index)
{
	return *(s->arr + index - 1);
}
void All_Visit(String* s)
{
	for (int i = 0; i < s->length; i++)
	{
		printf("%c ", *(s->arr + i));
	}
	printf("\n");
}
void Compter(char arr0[], char arr1[])
{
	int i = 0; 
	while (arr1[i])
	{
		int isFlage = 1;
		if (arr1[i] == arr0[0])
		{
			for (int j = 1; j < 4; j++)
			{
				if (arr1[i + j] != arr0[j])
				{
					isFlage = 0;
					break;
				}
			}
			if (isFlage == 1)
			{
				printf("%s �� %s �е���ʼλ��Ϊ��%d\n", arr0, arr1, i+1);
				return;
			}
		}
		i++;
		
	}
	printf("δ�ҵ����ַ���!\n");
}
int main()
{
	//��ʼ��
	String* s;
	s = Creat_String(20);
	//���Ԫ��
	char ele = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%c", &ele,1);
		Addele(s,ele);
	}
	

	//��ȡԪ��
	printf("������Ԫ��Ϊ��%c\n", Getele(s, 3));
	//ɾ��Ԫ��
	printf("ɾ��ǰ:\n"); All_Visit(s);
	Delete(s, 3);
	printf("ɾ����:\n"); All_Visit(s);
	//��ȡ����
	printf("�ô��ĳ���Ϊ��%d\n", Getlength(s));
	//����
	printf("������");
	All_Visit(s);
	//�����㷨
	char arr0[] = "abcdababedab";
	char arr1[] = "abab";
	Compter(arr1, arr0);
	
	//kmp�㷨

	//����
	return 0;
}