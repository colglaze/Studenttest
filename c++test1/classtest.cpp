#include<iostream>
using namespace std;
class judger
{
public:
	int count;
	void judge(int man,int com);
};
class player
{
private:
	int status;
public:
	int getin();
	void Print(int man);
};
class computer
{
private:
	int status;
public:
	int getIn();
	void Print(int com);
};
void cover()
{
	cout << "********************************************\n";
	cout << "*********1.game star  2.game over **********\n";
	cout << "********************************************\n";
}
int main()
{

	int start = 0;
	judger jg;
	jg.count = 0;
	do
	{
		cover();
		cin >> start;
		if (start == 1)
		{
			cout << "请选择你的状态" << endl;
			cout << "1.剪刀	2.石头	3.布" << endl;
			player py; computer cp;
			int a = py.getin();
			jg.judge( a , cp.getIn());
			py.Print(a);
			cp.Print(cp.getIn());
			cout << endl;
		}
		else if (start == 2)
		{
			if (jg.count > 0)
			{
				cout << "恭喜你赢了\n";
			}
			else if(jg.count < 0)
			{
				cout << "很遗憾，你输了\n";
			}
			else
			{
				cout << "平局\n";
			}
			break;
		}
		else
		{
			cout << "输入错误，请重新输入\n";

		}
	} while (1);
	

}
int player::getin()
{
	cin >> status;
	return status;
}
int computer::getIn()
{
	status = (rand() % (3 - 1 + 1)) + 1;
	return status;
}
void judger::judge(int man, int com)
{
	if ((man == 1 && com == 2) || (man == 2 && com == 3) || (man == 3 && com == 1))
	{
		count--;
	}
	else if ((man == 1 && com == 3) || (man == 2 && com == 1) || (man == 3 && com == 2))
	{
		count++;
	}
	else
	{
		count += 0;
	}
}
void computer::Print(int com)
{
	switch (com)
	{
	case 1:
		cout << " 电脑出的是剪刀 ";
		break;
	case 2:
		cout << " 电脑出的是石头 ";
		break;
	case 3:
		cout << " 电脑出的是布 ";
		break;
	}
}
void player::Print(int man)
{
	switch (man)
	{
	case 1:
		cout << " 你出的是剪刀 ";
		break;
	case 2:
		cout << " 你出的是石头 ";
		break;
	case 3:
		cout << " 你出的是布 ";
		break;
	}
}