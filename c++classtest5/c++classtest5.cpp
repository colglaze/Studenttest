#include<iostream>
#include<cmath>
using namespace std;
class Point
{
private:
	int x;
	int y;
public:
	void setx(int x)
	{
		this->x = x;
	}
	int getx()
	{
		return x;
	}
	void sety(int y)
	{
		this->y = y;
	}
	int gety()
	{
		return y;
	}
	Point(int x, int y) :x(x), y(y){}
	Point operator + (Point & p1)
	{
		x += p1.getx();
		y += p1.gety();
		return *(this);
	}
	double operator-(Point& p2)
	{
		return sqrt((y - p2.gety()) * (y - p2.gety()) + (x - p2.getx()) * (x - p2.getx()));
	}
};
template<class T>
void sort(T t[], int length, bool isRise)
{
	if (isRise)
	{
		for (int i = 0; i < length - 1; i++)
		{
			for (int j = 0; j < length - i - 1; j++)
			{
				if (t[j] > t[j + 1])
				{
					T tem = t[j + 1];
					t[j + 1] = t[j];
					t[j] = tem;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < length - 1; i++)
		{
			for (int j = 0; j < length - i; j++)
			{
				if (t[j] < t[j + 1])
				{
					T tem = t[j + 1];
					t[j + 1] = t[j];
					t[j] = tem;
				}
			}
		}
	}
}
class Books
{
private:
	string name;
	int price;
	int paginate;
public:
	Books(const string& name,int price,int paginate):name(name),price(price),paginate(paginate){}
	void setname(const string& name)
	{
		this->name = name;
	}
	string getname()const
	{
		return name;
	}
	void setprice(int price)
	{
		this->price = price;
	}
	int getprice()
	{
		return price;
	}
	void setpaginate(int paginate)
	{
		this->paginate = paginate;
	}
	int getpaginate()
	{
		return paginate;
	}
	bool operator<(Books b)
	{
		if (price < b.getprice())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(Books b)
	{
		if (price > b.getprice())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
template<class T>
void Print(T* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(p + i) <<" ";
	}
}

template<class T>
class Array {
private:
	T* arry;//记录集合中的一组数据
	int maxsize;// 最大长度
	int length;// 实际长度
public:
	Array(int length = 3) 
	{
		this->maxsize = length;
		length = 0;
		arry = new T[maxsize];
	}

	// 添加元素
	void add(T temp) 
	{
		// 判断线性表是否已经满了
		if (length >= maxsize) 
		{
			T* arr = new T[maxsize * 2];
			for (int i = 0; i < maxsize; i++) 
			{
				arr[i] = arry[i];
			}
			arry = arr;
			maxsize *= 2;
		}
		arry[length] = temp;
		length++;
	}

	T getElement(int index) 
	{
		return arry[index];
	}

	int getLength() 
	{
		return length;
	}
	int getMaxsize()
	{
		return maxsize;
	}
};

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double arr2[10] = { 10.43,9.54,8.57,7.856,6.978,5.45,4.32,3.23,2.78,1.56 };
	cout << "arr2排序前：" << endl;
	Print(arr2, 10);
	cout << endl;
	sort(arr2, sizeof(arr2) / sizeof(arr2[0]), true);
	cout << "arr2排序后：" << endl;
	Print(arr2,10);
	cout << endl;
	cout << "arr1排序前：" << endl;
	Print(arr1, 10);
	cout << endl;
	sort(arr1, sizeof(arr1) / sizeof(arr1[0]), false);
	cout << "arr1排序后：" << endl;
	Print(arr1, 10);
	cout << endl;
	Books b1("colglaze", 89, 300);
	Books b2("sfssas", 58, 900);
	Books b3("ccggll", 79, 1000);
	Books B[3] = { b1,b2,b3 };
	cout << "排序前：" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << B[i].getname() << ":" << B[i].getprice() << " ";
	}
	sort(B, 3, true);
	cout << endl << "排序后：" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << B[i].getname() << ":" << B[i].getprice() << " ";
	}
	Array<int> arr;
	int j = 0;
	arr.add(1); cout << endl << arr.getElement(0) << " ";
	arr.add(2); cout << arr.getElement(1) << " ";
	arr.add(3); cout << arr.getElement(2) << " ";
	cout << endl << "容量：" << arr.getMaxsize() << endl;
	arr.add(4);
	cout << "容量：" << arr.getMaxsize() << endl;
}