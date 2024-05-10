#include<iostream>
using namespace std;
class AgeinvalidException
{
private:
	const char* message;
public:
	AgeinvalidException():message("无效的年龄"){}
	const char* what()
	{
		return message;
	}
};
class EmptyNameException
{
private:
	const char* message;
public:
	EmptyNameException():message("姓名不能为空"){}
	const char* what()
	{
		return message;
	}
	
};
class Student
{
private:
	string name;
	int age;
	double score;
public:
	Student(const string& name,int age,double score)
	{
		setName(name);
		setAge(age);
		this->score = score;
	}
	void setScore(double score)
	{
		this->score = score;
	}
	double getScore()
	{
		return score;
	}
	void setAge(int age)
	{
		if (age < 7 || age>30)
		{
			throw AgeinvalidException();
		}
		this->age = age;
	}
	int getAge()
	{
		return age;
	}
	string getName()const
	{
		return name;
	}
	void setName(const string& name)
	{
		if (name.empty())
		{
			throw EmptyNameException();
		}
		this->name = name;
	}
};
int main()
{
	while (1)
	{
		try
		{
				cout << "请依次输入名字，年龄，分数\n";
				string name;
				int age;
				double score;
				cin >> name >> age >> score;
				Student s(name, age, score);
				cout << "姓名：" << s.getName() << " 年龄：" << s.getAge() << " 分数：" << s.getScore() << endl;
		}
		catch (AgeinvalidException err1)
		{
			cout << err1.what() << endl;
			break;
		}
		catch (EmptyNameException err2)
		{
			cout << err2.what() << endl;
		}
	}
	try
	{
		Student s2("", 23, 100);
		cout << s2.getAge() << s2.getScore() << endl;
	}
	catch (EmptyNameException err3)
	{
		cout << err3.what() << endl;
	}
	cout << "程序结束运行\n";
	return 0;
}