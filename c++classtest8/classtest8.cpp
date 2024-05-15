#include<iostream>
#include<string>
using namespace std;
class OptionException
{
private:
	const char* message;
public:
	OptionException() :message("����Ƿ������������룡"){}
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
	NameException():message("����������ַ���"){}
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
		cout << "��ѡ����Ҫ����ȭ��1.���� 2.ʯͷ 3.����\n";
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
	Computer(string name):Player("�˻�"){}
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
			1.����
			2.ʯͷ
			3.��
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
			cout << player[0]->getName() << "���ʤ����" << endl;
		}
		else if (player[0]->getCount() < player[1]->getCount())
		{
			cout << player[1]->getName() << "���ʤ����" << endl;
		}
		else
		{
			cout << "ƽ�֣�" << endl;
		}
	}
};
template<class T>
void show(T P)
{
	if (P.getOption() == 1)
	{
		cout << P.getName() << "�����Ǽ��� ";
	}
	else if (P.getOption() == 2)
	{
		cout << P.getName() << "������ʯͷ ";
	}
	else if (P.getOption() == 3)
	{
		cout << P.getName() << "�����ǲ� ";
	}
}
int main()
{
	try
	{
		Judger j1;
		cout << "���������������" << endl;
		string name;
		cin >> name;
		Person p1(name);
		Computer c1("�˻�");
		j1.init(&p1, &c1);
		while (1)
		{
			cout << "�Ƿ�ʼ��Ϸ��(Y/N)" << endl;
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