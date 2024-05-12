#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class invalidindexException
{
	const char* message;
public:
	invalidindexException() :message("��Ч�±��쳣��") {}
	const char* what()
	{
		return message;
	}
};

template<class A>
class Node
{
public:
	A data;
	Node<A>* next;
	Node():next(nullptr){}
	Node(A data):data(data),next(nullptr){}
	
};
template<class T>
class LinkedList 
{
private:
	int count;
	Node<T>* head;
public:
	LinkedList():count(0),head(nullptr){}
	void add(T data)//���Ԫ�أ�ͷ�巨
	{
			Node<T>* node = new Node<T>(data);
			node->next = head;
			head = node;
			count++;
	}
	void insert(T data, int index)//����Ԫ��
	{
		if (index > count || index < 0)
		{
			throw invalidindexException();
		}
		Node<T>* temp = head;
		for (int i = 1; i < index; i++)
		{
			temp = temp->next;
		}
		Node<T>* node = new Node<T>;
		node->data = data;
		if (index == count)
		{
			node->next = nullptr;
			temp->next = node;
			count++;
		}
		else if (index == 1)
		{
			node->next = head;
			head = node;
		}
		//node->setData(data);
		else
		{
			node->next = temp;
			temp->next = node;
			count++;
		}
	}
	void remove(int index)//ɾ��Ԫ��
	{
		if (index > count)
		{
			throw invalidindexException();
		}
		Node<T>* temp = head;
		if (index == 1)
		{
			head = head->next;
			count--;
			delete temp;
		}
		else
		{
			for (int i = 1; i < index-1; i++)
			{
				temp = temp->next;
			}
			Node<T>* tmp = new Node<T>;
			tmp = temp->next;
			temp->next = temp->next->next;
			delete tmp;
			count--;
		}
	}
	int getSize()//���ؽڵ���
	{
		return count;
	}
	T get(int index)//���ؽڵ��е�����
	{
		if (index > count)
		{
			throw invalidindexException();
		}
		Node<T>* temp = head;
		for (int i = 1; i < index; i++)
		{
			temp = temp->next;
		}
		//return temp->getData();
		return temp->data;
	}
	void ToseeLink()
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		/*for (int i = 0; i < 10; i++)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}*/
		cout << endl;
	}
};

int main()
{
	try
	{
		LinkedList<int> Link;
		for (int i = 0; i < 10; i++)
		{
			Link.add(i);
		}
		cout << "����Ԫ��ǰ��" << endl;
		Link.ToseeLink();
		Link.insert(10, 10);
		cout<<  "����Ԫ�غ�" << endl;
		Link.ToseeLink();
		cout << "ɾ��Ԫ��ǰ��" << endl;
		Link.ToseeLink();
		Link.remove(1);
		cout << "ɾ��Ԫ�غ�" << endl;
		Link.ToseeLink();
		cout << "������Ԫ���ǣ�" << Link.get(6) << endl;
		cout << "�����Ԫ�ظ���Ϊ��" << Link.getSize() << endl;
		Link.get(20);
	}
	catch (invalidindexException err)
	{
		cout << err.what() << endl;
	}
}