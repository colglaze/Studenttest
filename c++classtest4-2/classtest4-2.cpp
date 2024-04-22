#include<iostream>
#include<string>
#include<cmath>
#define _USE_MATH_DEFINES
using namespace std;
class Person
{
private:
	string name;
	char gender;
	int age;
public:
	Person(const string& name,char gender,int age):name(name),gender(gender),age(age){}
	string getname()const
	{
		return name;
	}
	void setname(const string& name)
	{
		this->name = name;
	}
	char getgender()
	{
		return gender;
	}
	void setgender(char gender)
	{
		this->gender = gender;
	}
	int getage()
	{
		return age;
	}
	void setage(int age)
	{
		this->age = age;
	}
	virtual void Eat() = 0;
	virtual void Sleep() = 0;
};
class Student:virtual public Person
{
private:
	int score;
public:
	void setscore()
	{
		this->score = score;
	}
	int getscore()
	{
		return score;
	}
	void study()
	{
		cout << "会学习" << endl;
	}
	void exam()
	{
		cout << "会考试" << endl;
	}
	void Eat()
	{
		cout << "准时吃饭" << endl;
	}
	void Sleep()
	{
		cout << "按时睡觉" << endl;
	}
	Student(const string& name, char gender, int age,int score):Person(name,gender,age),score(score){}

};
class Teacher :virtual public Person
{
private:
	int emolument;
public:
	int getemolument()
	{
		return emolument;
	}
	void setemolument(int emolument)
	{
		this->emolument = emolument;
	}
	void teach()
	{
		cout << "会讲课" << endl;
	}
	void Eat()
	{
		cout << "准时吃饭" << endl;
	}
	void Sleep()
	{
		cout << "按时睡觉" << endl;
	}
	Teacher(const string& name, char gender, int age,int emolument):Person(name,gender,age),emolument(emolument){}

};
class Assistant :public Student, public Teacher
{
public:
	Assistant(const string& name, char gender, int age,int emolument,int score):Student(name,gender,age,score),Teacher(name,gender,age,emolument),Person(name,gender,age){}
	void Eat()
	{
		Teacher::Eat();
	}
	void Sleep()
	{
		Teacher::Sleep();
	}
};
class Shape
{
private:
	double area;
	double volume;
public:
	virtual double ComArea() = 0;
	virtual double ComVolume() = 0;

};
class Box :virtual public Shape
{
private:
	double length;
	double wide;
	double height;
public:
	void setlength(double length)
	{
		this->length = length;
	}
	double getlength()
	{
		return length;
	}
	void setwide(double wide)
	{
		this->wide = wide;
	}
	double getwide()
	{
		return wide;
	}
	void setheight(double height)
	{
		this->height = height;
	}
	double getheight()
	{
		return height;
	}
	double ComArea()
	{
		return 2 * (wide * length + wide * height + height * length);
	}
	double ComVolume()
	{
		return length * wide * height;
	}
	Box(double length,double wide,double height):length(length),wide(wide),height(height){}

};
class Sphere :virtual public Shape
{
private:
	double radiuas;
public:
	void setradiuas(double radiuas)
	{
		this->radiuas = radiuas;
	}
	double getradiuas()
	{
		return radiuas;
	}
	double ComArea()
	{
		return 4 * acos(-1) * radiuas * radiuas;
	}
	double ComVolume()
	{
		return 4.0 / 3.0 * acos(-1) * radiuas * radiuas * radiuas;
	}
	Sphere(double radiuas):radiuas(radiuas){}
};
int main()
{
	Assistant a1("啊giao", '男', 40, 20000, 38);
	a1.Eat();
	//将基类设为虚基类是因为Assistant继承了Person的Teacher和Student两个子类，
	// 防止二义性以及空间浪费
	Box b(2.5, 3.4, 4.3);
	cout << "长为 " << b.getlength() << " 宽为 " << b.getwide() << " 高为 " << b.getheight() << " 的长方体的面积为 " << b.ComArea() << endl;
	cout << "长为 " << b.getlength() << " 宽为 " << b.getwide() << " 高为 " << b.getheight() << " 的长方体的体积为 " << b.ComVolume() << endl;
	Sphere s(7.62);
	cout << "半径为 " << s.getradiuas() << " 的球的体积为 " << s.ComVolume() << endl;
	cout << "半径为 " << s.getradiuas() << " 的球的面积为 " << s.ComArea() << endl;
}