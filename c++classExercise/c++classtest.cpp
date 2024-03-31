#include<iostream>
using namespace std;
class Point
{
private:
	double x;
	double y;
public:
	void setterX(double a)
	{
		x = a;
	}
	void setterY(double b)
	{
		y = b;
	}
	double getterX()const
	{
		return x;
	}
	double getterY()const
	{
		return y;
	}
	Point(double a, double b)
	{
		x = a;
		y = b;
	}
	double distance(double x2, double y2)
	{
		double a = (x - x2) * (x - x2);
		double b = (y - y2) * (y - y2);
		return sqrt(a + b);
	}
};
class Line
{
private:
	double k;
	double c;
public:
	Line(double kk, double cc)
	{
		k = kk;
		c = cc;
	}
	Line(const Point& p1, const Point& p2)
	{
		if (p1.getterX() == p2.getterX())
		{
			k = -1;
			c = p1.getterX();
		}
		else if (p1.getterY() == p2.getterY())
		{
			k = 0;
			c = p1.getterY();
		}
		else
		{
			k = (p1.getterY() - p2.getterY()) / (p1.getterX() - p2.getterX());
			c = p1.getterY() - k * p1.getterX();
		}
	}
	bool isOnline(double x,double y)
	{
		return k * x + c - y == 0;
	}
	bool isParallel(const Line& l1)
	{
		return l1.k == k;
	}
	bool isvertical(const Line& l1)
	{
		if (l1.k == 0 && k == -1)
		{
			return true;
		}
		return l1.k * k == -1;
	}
};
class Rectangle
{
private:
	Point a; Point b; Point c; Point d;
public:
	Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
		:a(p1), b(p2), c(p3), d(p4) {};
	bool isRectangle(const Rectangle& R)
	{
		Line L1(R.a, R.b);  Line L3(R.a, R.d);
		Line L2(R.a, R.c);  Line L4(R.c, R.d);
		if (L1.isvertical(L2) && L1.isParallel(L4) )
		{
			if(a.distance(b.getterX(), b.getterY()) == c.distance(d.getterX(), d.getterY()))
			return true;
		}
		else if (L1.isvertical(L3) && L1.isParallel(L4))
		{
			if (a.distance(b.getterX(), b.getterY()) == c.distance(d.getterX(), d.getterY()))
				return true;
		}
		else
		{
			return false;
		}
	}
	double Long(const Rectangle& r)
	{
		double x=a.distance(b.getterX(), b.getterY());
		double y=a.distance(c.getterX(), c.getterY());
		double z=a.distance(d.getterX(), d.getterY());
		if ((x > y && x < z)||(x > z && x < y))
		{
			return x;
		}
		else if ((y > x && y < z)||((y > z && y < x)))
		{
			return y;
		}
		else
		{
			return z;
		}
	}
	double Wide(const Rectangle& r)
	{
		double x = a.distance(b.getterX(), b.getterY());
		double y = a.distance(c.getterX(), c.getterY());
		double z = a.distance(d.getterX(), d.getterY());
		x = x < y ? x : y;
		x = x < z ? x : z;
		return x;
	}
	double Circle(const Rectangle& r)
	{
		return 2 * (Wide(r) + Long(r));
	}
	double Area(const Rectangle& r)
	{
		return Wide(r) * Long(r);
	}
};
int main()
{
	//Point类的测验
	Point p1(2, 3);
	Point p2(4, 13);
	cout << "两点间的距离 " << p1.distance(p2.getterX(), p2.getterY()) << endl;
	//Line测验
	Line L1(5, 4);
	Line L2(p1, p2);
	cout << "是否在线上 " << L1.isOnline(8, 3) << endl;
	cout << "是否平行 " << L1.isParallel(L2) << endl;
	cout << "是否垂直 " << L2.isvertical(L1) << endl;
	//Rectangle测验
	Point p3(0, 0);
	Point p4(0, 5);
	Point p5(6, 0);
	Point p6(6, 5);
	Rectangle R(p3, p4, p5, p6);
	cout << "能否构成长方形 " << R.isRectangle(R) << endl;
	cout << "长为：" << R.Long(R) << endl;
	cout << "宽为：" << R.Wide(R) << endl;
	cout << "面积为：" << R.Area(R) << endl;
	cout << "周长为：" << R.Circle(R) << endl;
	return 0;
}
