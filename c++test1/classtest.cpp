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
			cout << "��ѡ�����״̬" << endl;
			cout << "1.����	2.ʯͷ	3.��" << endl;
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
				cout << "��ϲ��Ӯ��\n";
			}
			else if(jg.count < 0)
			{
				cout << "���ź���������\n";
			}
			else
			{
				cout << "ƽ��\n";
			}
			break;
		}
		else
		{
			cout << "�����������������\n";

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
		cout << " ���Գ����Ǽ��� ";
		break;
	case 2:
		cout << " ���Գ�����ʯͷ ";
		break;
	case 3:
		cout << " ���Գ����ǲ� ";
		break;
	}
}
void player::Print(int man)
{
	switch (man)
	{
	case 1:
		cout << " ������Ǽ��� ";
		break;
	case 2:
		cout << " �������ʯͷ ";
		break;
	case 3:
		cout << " ������ǲ� ";
		break;
	}
}