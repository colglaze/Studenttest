#include<iostream>
#include<string>
using namespace std;
class Circle
{
private:
	double radius;
public:
	Circle(double radius):radius(radius){}
	double getradius()
	{
		return radius;
	}
	void setradius(double radius)
	{
		this->radius = radius;
	}
	double area()
	{
		return 3.14 * radius * radius;
	}
	double perimeter()
	{
		return 3.14 * 2 * radius;
	}
};
class Cylinder:public Circle
{
private:
	double height;
public:
	Cylinder(double height,double radius) :Circle(radius),height(height){}
	
	double Area()
	{
		return area() * 2 + perimeter() * height;
	}
	double calcVol()
	{
		return area() * height;
	}
	double getheight()
	{
		return height;
	}
	void setheight(double height)
	{
		this->height = height;
	}
}; 
class Movie
{
private:
	string editor;
	
public:
	string moviename;
	int price;
	int getprice()
	{
		return price;
	}
	void setprice(int price)
	{
		this->price = price;
	}
	string getmoviename()const
	{
		return moviename;
	}
	void setmoviename(const string& moviename)
	{
		this->moviename = moviename;
	}
	string geteditor()const
	{
		return editor;
	}
	void seteditor(const string& editor)
	{
		this->editor = editor;
	}
	Movie(const string& moviename,int price):moviename(moviename),price(price){}

};
class Ticket :public Movie
{
private:
	int number;
	string time;
public:
	int getnumber()
	{
		return number;
	}
	void setnumber(int number)
	{
		this->number = number;
	}
	string gettime()const
	{
		return time;
	}
	void settime(const string& time)
	{
		this->time = time;
	}
	Ticket(int number, const string& time, const string& Moviename,int Price):Movie(Moviename,Price),number(number),time(time){}
};
class Studentticket :public Ticket
{
private:
	double discount;
public:
	double getdiscount()
	{
		return discount;
	}
	void setdiscount(double discount)
	{
		this->discount = discount;
	}
	Studentticket(double discount,const string& time,int number, const string& Moviename, int Price):Ticket(number,time,Moviename,Price*discount),discount(discount){}

};
class Normallticket :public Ticket
{
public:
	Normallticket(int number, const string& time, const string& Moviename, int Price):Ticket(number, time, Moviename, Price){}

};
class Presentticket :public Ticket
{
private:
	string presenter;
public:
	string getpresenter()const
	{
		return presenter;
	}
	void setpresenter(const string& presenter)
	{
		this->presenter = presenter;
	}
	Presentticket(const string& time, int number, const string& Moviename, int Price):Ticket(number, time, Moviename, Price*0){}
};
int main()
{
	Circle c1(3);
	cout << "�뾶Ϊ " << c1.getradius() << " ��Բ���Ϊ��" << c1.area() << endl;
	cout << "�뾶Ϊ " << c1.getradius() << " ��Բ�ܳ�Ϊ��" << c1.perimeter() << endl;
	Cylinder c2(5, 4);
	cout << "����뾶Ϊ " << c2.getradius() << " ��Ϊ " << c2.getheight() << " ��Բ��������Ϊ��" << c2.Area() << endl;
	cout << "����뾶Ϊ " << c2.getradius() << " ��Ϊ " << c2.getheight() << " ��Բ�������Ϊ��" << c2.calcVol() << endl;
	Studentticket s1(0.8, "20:00", 25, "��Ȼ�Ķ�", 40);
	cout << "����ʱ�䣺" << s1.gettime() << " ��λ�ţ�" << s1.getnumber() << " ��Ӱ���ƣ�" << s1.getmoviename() << " Ʊ��Ϊ��" << s1.getprice() << endl;
	Normallticket s2(39, "20:35", "����������������", 30);
	cout << "����ʱ�䣺" << s2.gettime() << " ��λ�ţ�" << s2.getnumber() << " ��Ӱ���ƣ�" << s2.getmoviename() << " Ʊ��Ϊ��" << s2.getprice() << endl;
	Presentticket s3("9:30", 79, "���������", 40);
	cout << "����ʱ�䣺" << s3.gettime() << " ��λ�ţ�" << s3.getnumber() << " ��Ӱ���ƣ�" << s3.getmoviename() << " Ʊ��Ϊ��" << s3.getprice() << endl;
	
}