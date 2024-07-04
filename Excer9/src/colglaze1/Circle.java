package colglaze1;

public class Circle extends GeometricObject {
	private double radius;
	public Circle(double radius)
	{
		this.radius=radius;
	}
	public Circle()
	{
		this.radius=1.0;
	}
	public Circle(String color, double weight,double radius) {
		super(color,weight);
		this.radius=radius;
	}
	public void setRadius(double radius)
	{
		this.radius=radius;
	}
	public double getRadius()
	{
		return radius;
	}
	public double findArea()
	{
		return Math.PI*radius*radius;
	}
	public boolean equals(Object obj)
	{
		if(this==obj)
		{
			return true;
		}
		if(obj instanceof Circle)
		{
			Circle c=(Circle)obj;
			return c.getRadius()==this.radius;
		}
		return false;
	}
	public String toString()
	{
		return "[radius="+radius+"]";
	}
}
