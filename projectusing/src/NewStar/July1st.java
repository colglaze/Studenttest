package NewStar;

public class July1st {
public static void main(String[] args) {
	Point p1=new Point(2,3);
	Point p2=new Point(4,13);
	System.out.println("两点间的距离"+p1.distance(p2));
	Line L1=new Line(5,4);
	Line L2=new Line(p1,p2);
	if(L1.isOnLine(p2))
	{
		System.out.println("在直线上");
		
	}
	else
	{
		System.out.println("不在直线上");
	}
	if(L1.isParallel(L2))
	{
		System.out.println("两直线平行");
	}
	else
	{
		System.out.println("两直线不平行");
	}
	Point p3=new Point(0, 0);
	Point p4=new Point(0, 5);
	Point p5=new Point(6, 0);
	Point p6=new Point(6, 5);
	Rectangle R=new Rectangle(p3,p4,p5,p6);
	if(R.isRectangle(R))
	{
		System.out.println("可以构成长方形");
	}
	else
	{
		System.out.println("无法构成长方形");
	}
	System.out.println("长为："+R.Long(R));
	System.out.println("宽为："+R.Wide(R));
	System.out.println("面积为："+R.Area(R));
	System.out.println("周长为："+R.Circle(R));
	
}
}