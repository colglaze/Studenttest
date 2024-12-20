package NewStar;

public class Point {
	private double x;
	private double y;
	public Point()
	{
		
	}
	public Point(double x,double y)
	{
		this.x=x;
		this.y=y;
	}
	public void setX(double x)
	{
		this.x=x;
	}
	public void setY(double y)
	{
		this.y=y;
	}
	public double getX()
	{
		return x;
	}
	public double getY()
	{
		return y;
	}
	public double distance(Point p1)
	{
		return Math.sqrt((x-p1.getX())*(x-p1.getX())+(y-p1.getY())*(y-p1.getY()));
	}
}
