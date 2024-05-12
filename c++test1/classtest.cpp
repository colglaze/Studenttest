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
	player(int a)
	{
		status = a;
	}
	int getin();
	void setin(int b);
	void Print(int man);
};
class computer
{
private:
	int status;
public:
	int getIn();
	void setin(int a);
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
		srand(time(0));
		cover();
		cin >> start;
		if (start == 1)
		{
			cout << "��ѡ�����״̬" << endl;
			cout << "1.����	2.ʯͷ	3.��" << endl;
			int a = 0;
			cin >> a;
			player py(a); computer cp;
			cp.setin((rand() % (3 - 1 + 1)) + 1);
			jg.judge( a , cp.getIn());
			py.Print(a);
			cp.Print(cp.getIn());
			cout << endl;
			//int temp = cp.getIn();//���ڵ���
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
	return status;
}
void computer::setin(int a)
{
	status = a; //(rand() % (3 - 1 + 1)) + 1;
}
int computer::getIn()
{
	//status = (rand() % (3 - 1 + 1)) + 1;
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
		cout << "������Ǽ��� ";
		break;
	case 2:
		cout << "�������ʯͷ ";
		break;
	case 3:
		cout << "������ǲ� ";
		break;
	}
}
void player::setin(int b)
{
	if (b > 0 && b < 4)
	{
		status = b;
	}
	else
	{
		cout << "�������\n";
	}
}
//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//
//using namespace std;
//
//class Person {
//private:
//	int win;
//	int choice;
//public:
//	int getw()
//	{
//		return win;
//	}
//	Person() :win(0), choice(0) {
//	}
//	void setWin(int win)
//	{
//		this->win = win;
//	}
//	int play();
//};
//
//class Computer {
//private:
//	int win;
//	int AI;
//public:
//	int getw()
//	{
//		return win;
//	}
//	Computer() :win(0), AI(0) {
//	}
//	void setWin(int win) {
//		this->win = win;
//	}
//	int play();
//};
//
//int Person::play() {
//	cout << "������ȭ��1.ʯͷ 2.���� 3.��" << endl;
//	cin >> choice;
//	if (choice >= 1 && choice <= 3)
//	{
//		switch (choice)
//		{
//		case 1:
//			cout << "������ǣ�ʯͷ" << endl;
//			break;
//		case 2:
//			cout << "������ǣ�����" << endl;
//			break;
//		case 3:
//			cout << "������ǣ���" << endl;
//			break;
//		}
//		return choice;
//	}
//	else
//	{
//		cout << "�������" << endl;
//		return false;
//	}
//
//}
//
//int Computer::play()
//{
//	srand((unsigned int)time(NULL));
//	AI = rand() % 3 + 1;
//	if (AI >= 1 && AI <= 3)
//	{
//		switch (AI)
//		{
//		case 1:
//			cout << "���Գ����ǣ�ʯͷ" << endl;
//			break;
//		case 2:
//			cout << "���Գ����ǣ�����" << endl;
//			break;
//		case 3:
//			cout << "���Գ����ǣ���" << endl;
//			break;
//		}
//		return AI;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//class Judger
//{
//private:
//	int total;
//	Person per;
//	Computer com;
//public:
//	void init()
//	{
//		total = 0;
//		per.setWin(0);
//		com.setWin(0);
//	}
//	void judge(int Pe, int Co)
//	{
//		if (Pe == 1 && Co == 2 || Pe == 2 && Co == 3 || Pe == 3 && Co == 1)
//		{
//			per.setWin(per.getw() + 1);
//			cout << "������Ӯ�ˣ�" << endl;
//		}
//		else if (Pe == Co)
//		{
//			cout << "ƽ��" << endl;
//		}
//		else
//		{
//			com.setWin(com.getw() + 1);
//			cout << "���������ˣ�" << endl;
//		}
//		total++;
//	}
//	void declare()
//	{
//		cout << "------��Ϸ����------" << endl;
//		cout << "�������\t�������" << endl;
//		cout << " " << per.getw() << "\t" << com.getw() << " " << endl;
//		cout << "ƽ�ֻغ�����" << total - per.getw() - com.getw() << endl;
//		if (per.getw() > com.getw())
//		{
//			cout << "YOU WON" << endl;
//		}
//		else
//		{
//			cout << "YOU OUT" << endl;
//		}
//	}
//	void Continue()
//	{
//		int Continue = 0;
//
//		cout << "1.��ʼ��Ϸ\t0.������Ϸ" << endl;
//		cin >> Continue;
//		while (Continue == 1)
//		{
//			int Pe = 0;
//			int Co = 0;
//			cout << "---��Ϸ��ʼ---" << endl;
//			Pe = per.play();
//			Co = com.play();
//			judge(Pe, Co);
//			cout << "�Ƿ������Ϸ��0.�� 1.��" << endl;
//			int anwser = 0;
//			cin >> anwser;
//			Continue = anwser == 1;
//		}
//		declare();
//	}
//
//};
//
//int main()
//{
//	cout << "------�˻���ȭ��Ϸ------" << endl;
//	Judger judge;
//	judge.init();
//	judge.Continue();
//	return 0;
//}