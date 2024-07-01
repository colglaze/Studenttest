package NewStar;

public class Line {
	private double k;
	private double c;
	public Line(double k,double c)
	{
		this.c=c;
		this.k=k;
	}
	public Line(Point p1,Point p2)
	{
		if (p1.getX() == p2.getX())
		{
			k = -1;
			c = p1.getX();
		}
		else if (p1.getY() == p2.getY())
		{
			k = 0;
			c = p1.getY();
		}
		else
		{
			k = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
			c = p1.getY() - k * p1.getX();
		}
	}
	void setK(double k)
	{
		this.k=k;
	}
	void setC(double c)
	{
		this.c=c;
	}
	double getK()
	{
		return k;
	}
	double getC()
	{
		return c;
	}
	boolean isOnLine(Point p)
	{
		if(p.getY()==k*p.getX()+c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	boolean isParallel(Line l)
	{
		if(l.getK()==k)
		{
			return true;
		}
		return false;
	}
	boolean isvertical(Line l)
	{
		if(l.getK()*k==-1)
		{
			return true;
		}
		return false;
	}
	
}

