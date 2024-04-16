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
	cout << "半径为 " << c1.getradius() << " 的圆面积为：" << c1.area() << endl;
	cout << "半径为 " << c1.getradius() << " 的圆周长为：" << c1.perimeter() << endl;
	Cylinder c2(5, 4);
	cout << "底面半径为 " << c2.getradius() << " 高为 " << c2.getheight() << " 的圆柱体表面积为：" << c2.Area() << endl;
	cout << "底面半径为 " << c2.getradius() << " 高为 " << c2.getheight() << " 的圆柱体体积为：" << c2.calcVol() << endl;
	Studentticket s1(0.8, "20:00", 25, "怦然心动", 40);
	cout << "开播时间：" << s1.gettime() << " 座位号：" << s1.getnumber() << " 电影名称：" << s1.getmoviename() << " 票价为：" << s1.getprice() << endl;
	Normallticket s2(39, "20:35", "你想活出怎样的人生", 30);
	cout << "开播时间：" << s2.gettime() << " 座位号：" << s2.getnumber() << " 电影名称：" << s2.getmoviename() << " 票价为：" << s2.getprice() << endl;
	Presentticket s3("9:30", 79, "白日梦想家", 40);
	cout << "开播时间：" << s3.gettime() << " 座位号：" << s3.getnumber() << " 电影名称：" << s3.getmoviename() << " 票价为：" << s3.getprice() << endl;
	
}