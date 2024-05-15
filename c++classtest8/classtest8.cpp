#include<iostream>
#include<string>
using namespace std;
class OptionException
{
private:
	const char* message;
public:
	OptionException() :message("输入非法，请重新输入！"){}
	const char* what()
	{
		return message;
	}
};
class NameException
{
private:
	const char* message;
public:
	NameException():message("不可输入空字符！"){}
	const char* what()
	{
		return message;
	}
};
class Player
{
private:
	string name;
	int count;
public:
	virtual int showhand() = 0;
	void setName(const string& name)
	{
		if (name.empty())
		{
			throw NameException();
		}
		else
		{
			this->name = name;
		}
	}
	string getName()const
	{
		return name;
	}
	void setCount()
	{
		count++;
	}
	int getCount()
	{
		return count;
	}
	Player(string name)
	{
		setName(name);
		count = 0;
	}
};
class Person :virtual public Player
{
private:
	int option;
public:
	Person(string name):Player(name){}
	void setOption(int option)
	{
		this->option = option;
	}
	int getOption()
	{
		return option;
	}
	int  showhand()
	{
		return option;
	}
	void ShowHand()
	{
		int num;
		cout << "请选择你要出的拳（1.剪刀 2.石头 3.布）\n";
		cin >> num;
		if (num < 1 || num>3)
		{
			throw OptionException();
		}
		else
		{
			setOption(num);
		}
	}
};
class Computer :virtual public Player
{
private:
	int option;
public:
	Computer(string name):Player("人机"){}
	int getOption()
	{
		return option;
	}
	int showhand()
	{
		return option;
	}
	void ShowHand()
	{
		option = rand() % 3 + 1;
	}
};
class Judger
{
private:
	int total;
	Player* player[2];
public:
	Judger():total(0){}
	void init(Player* p1,Player* p2)
	{
		player[0] = p1;
		player[1] = p2;
	}
	void judge()
	{
		/*
			1.剪刀
			2.石头
			3.布
		*/
		if (player[0]->showhand() == 1 && player[1]->showhand() == 2)
		{
			player[1]->setCount();
		}
		else if(player[0]->showhand() == 2 && player[1]->showhand() == 3)
		{
			player[1]->setCount();
		}
		else if (player[0]->showhand() == 3 && player[1]->showhand() == 1)
		{
			player[1]->setCount();
		}
		else if (player[0]->showhand() == player[1]->showhand())
		{
			player[1]->setCount();
			player[0]->showhand();
		}
		else
		{
			player[0]->setCount();
		}
	}
	bool control()
	{
		char isFlage;
		cin >> isFlage;
		if (isFlage == 'Y' || isFlage == 'y')
		{
			return true;
		}
		else if (isFlage == 'N' || isFlage == 'n')
		{
			return false;
		}
	}
	void declare()
	{
		if (player[0]->getCount() > player[1]->getCount())
		{
			cout << player[0]->getName() << "获得胜利！" << endl;
		}
		else if (player[0]->getCount() < player[1]->getCount())
		{
			cout << player[1]->getName() << "获得胜利！" << endl;
		}
		else
		{
			cout << "平局！" << endl;
		}
	}
};
template<class T>
void show(T P)
{
	if (P.getOption() == 1)
	{
		cout << P.getName() << "出的是剪刀 ";
	}
	else if (P.getOption() == 2)
	{
		cout << P.getName() << "出的是石头 ";
	}
	else if (P.getOption() == 3)
	{
		cout << P.getName() << "出的是布 ";
	}
}
int main()
{
	try
	{
		Judger j1;
		cout << "请输入玩家姓名：" << endl;
		string name;
		cin >> name;
		Person p1(name);
		Computer c1("人机");
		j1.init(&p1, &c1);
		while (1)
		{
			cout << "是否开始游戏？(Y/N)" << endl;
			if (j1.control())
			{
				p1.ShowHand();
				c1.ShowHand();
				j1.judge();
				show(p1); show(c1);
				cout << endl;
			}
			else
			{
				j1.declare();
				break;
			}
		}
	}
	catch (OptionException err1)
	{
		cout << err1.what() << endl;
	}
	catch (NameException err2)
	{
		cout << err2.what() << endl;
	}
	return 0;
}