#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class invalidindexException
{
	const char* message;
public:
	invalidindexException() :message("无效下标异常！") {}
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
	void add(T data)//添加元素，头插法
	{
			Node<T>* node = new Node<T>(data);
			node->next = head;
			head = node;
			count++;
	}
	void insert(T data, int index)//插入元素
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
	void remove(int index)//删除元素
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
	int getSize()//返回节点数
	{
		return count;
	}
	T get(int index)//返回节点中的数据
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
		cout << "插入元素前：" << endl;
		Link.ToseeLink();
		Link.insert(10, 10);
		cout<<  "插入元素后：" << endl;
		Link.ToseeLink();
		cout << "删除元素前：" << endl;
		Link.ToseeLink();
		Link.remove(1);
		cout << "删除元素后：" << endl;
		Link.ToseeLink();
		cout << "第六个元素是：" << Link.get(6) << endl;
		cout << "链表的元素个数为：" << Link.getSize() << endl;
		Link.get(20);
	}
	catch (invalidindexException err)
	{
		cout << err.what() << endl;
	}
}