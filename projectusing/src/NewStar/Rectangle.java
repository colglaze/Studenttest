package NewStar;

public class Rectangle {
	private Point a;
	private Point b;
	private Point c;
	private Point d;
	public Rectangle(Point a,Point b,Point c,Point d)
	{
		this.a=a;
		this.b=b;
		this.c=c;
		this.d=d;
	}
	public Rectangle() {
		
	}
	public Point getA() {
		return a;
	}
	public void setA(Point a) {
		this.a = a;
	}
	public Point getB() {
		return b;
	}
	public void setB(Point b) {
		this.b = b;
	}
	public Point getC() {
		return c;
	}
	public void setC(Point c) {
		this.c = c;
	}
	public Point getD() {
		return d;
	}
	public void setD(Point d) {
		this.d = d;
	}
	boolean isRectangle( Rectangle R)
	{
		Line L1=new Line(R.a, R.b);Line L3=new Line(R.a, R.d);
		Line L2=new Line(R.a, R.c);Line L4=new Line(R.c, R.d);
		if (L1.isvertical(L2) && L1.isParallel(L4))
		{
			if (a.distance(b) == c.distance(d))
				return true;
		}
		else if (L1.isvertical(L3) && L1.isParallel(L4))
		{
			if (a.distance(b) == c.distance(d))
				return true;
		}
		else
		{
			return false;
		}
		return false;
	}
	double Long(Rectangle r)
	{
		double x = a.distance(b);
		double y = a.distance(c);
		double z = a.distance(d);
		if ((x > y && x < z) || (x > z && x < y))
		{
			return x;
		}
		else if ((y > x && y < z) || ((y > z && y < x)))
		{
			return y;
		}
		else
		{
			return z;
		}
	}
	double Wide( Rectangle r)
	{
		double x = a.distance(b);
		double y = a.distance(c);
		double z = a.distance(d);
		x = x < y ? x : y;
		x = x < z ? x : z;
		return x;
	}
	double Circle( Rectangle r)
	{
		return 2 * (Wide(r) + Long(r));
	}
	double Area( Rectangle r)
	{
		return Wide(r) * Long(r);
	}
}
