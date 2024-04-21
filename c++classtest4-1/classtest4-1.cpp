#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	string name;
	int age;
	double score;
public:
	string getname()const
	{
		return name;
	}
	void setname(const string& name)
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
	double getscore()
	{
		return score;
	}
	void setscore(double score)
	{
		this->score = score;
	}
	Student(string name,int age,double score):name(name),age(age),score(score){}
	bool operator >(int age)
	{
		if (this->age > age)
		{
			return true;
		}
		return false;
	}
	Student& operator--()
	{
		age -= 1;
		return (*this);
	}
	Student operator=(Student& s)
	{
		s.age = this->age;
		s.name = this->name;
		s.score = this->score;
		return s;
	}
};
int main()
{
	Student s1("宇将军", 25, 30);
	if (s1 > 60)
	{
		cout << s1.getname() << "是老头" << endl;
	}
	else
	{
		cout << s1.getname() << "还年轻" << endl;
	}
	--s1;
	cout << s1.getage() << endl;
	Student s2 = s1;
	cout << "年龄 " << s2.getage() << " 姓名 " << s2.getname() << " 分数 " << s2.getscore() << endl;
}