#include<iostream>
using namespace std;
class Student
{
private:
	string name;
	int age;
	int cscore;
	int mathscore;
public:
	static int count;
	string getname()
	{
		return name;
	}
	void setname(string name)
	{
		this->name = name;
	}
	int getage()
	{
		return age;
	}
	void setage(int age)
	{
		this->age = age;
	}
	int getcscore()
	{
		return cscore;
	}
	void setcscore(int cscore)
	{
		this->cscore = cscore;
	}
	int getmathscore()
	{
		return mathscore;
	}
	void setmathscore(int mathscore)
	{
		this->mathscore = mathscore;
	}
	Student(string name, int age, int cscore, int mathscore)
	{
		this->age = age;
		this->cscore = cscore;
		this->mathscore = mathscore;
		this->name = name;
		if (mathscore >= 90 && cscore >= 90)
		{
			count++;
		}
	}
	
};
int Student::count = 0;
class Onlyone
{
private:
	static Onlyone* a;
	~Onlyone(){}
	Onlyone(){}
public:
	static Onlyone* getOnlyone()
	{
		if (a == nullptr)
		{
			a = new Onlyone();
		}
		return a;
	}
	
};
Onlyone* Onlyone::a = nullptr;
/*
 将一个B类的函数声明为另一个A类的友元函数的操作顺序：
 1，声明A
 2,声明B并且定义B，但不对该函数进行定义
 3，定义A
 4，单独定义B中该函数

*/
class A;
class B
{
public:
	void showX(A& a);
	B(){}
};

class A
{
private:
	int x;
public:
	A(int x=0):x(x){}
	void setA(int x)
	{
		this->x = x;
	}
	friend void printx(A&);
	friend void B::showX(A&);
	friend class C;
};
void printx(A& a)
{
	cout << a.x << endl;
}
void B::showX(A& a)
{
	cout << a.x << endl;
}

class C
{
public:
	void printX(A& a)
	{
		cout << a.x << endl;
	}
	void showX(A& a)
	{
		cout << a.x << endl;
	}
};
int main()
{
	Student s1("王桑", 19, 99, 99);
	Student s2("撒天", 99, 9, 100);
	Student s3("CC", 19, 90, 90);
	cout << "优秀学生人数为：" << s1.count << endl;
	Onlyone* obj1 = Onlyone::getOnlyone();
	Onlyone* obj2 = Onlyone::getOnlyone();
	if (obj1 == obj2)
	{
		cout << "只创建了一个\n";
	}
	else
	{
		cout << "创建了两个\n";
	}
	A a(0);
	a.setA(100);
	printx(a);
	//声明时没有属性不加括号
	B b;
	b.showX(a);
	C c;
	c.printX(a);
	c.showX(a);
}