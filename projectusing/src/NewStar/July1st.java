package NewStar;

public class July1st {
public static void main(String[] args) {
	Point p1=new Point(2,3);
	Point p2=new Point(4,13);
	System.out.println("�����ľ���"+p1.distance(p2));
	Line L1=new Line(5,4);
	Line L2=new Line(p1,p2);
	if(L1.isOnLine(p2))
	{
		System.out.println("��ֱ����");
		
	}
	else
	{
		System.out.println("����ֱ����");
	}
	if(L1.isParallel(L2))
	{
		System.out.println("��ֱ��ƽ��");
	}
	else
	{
		System.out.println("��ֱ�߲�ƽ��");
	}
	Point p3=new Point(0, 0);
	Point p4=new Point(0, 5);
	Point p5=new Point(6, 0);
	Point p6=new Point(6, 5);
	Rectangle R=new Rectangle(p3,p4,p5,p6);
	if(R.isRectangle(R))
	{
		System.out.println("���Թ��ɳ�����");
	}
	else
	{
		System.out.println("�޷����ɳ�����");
	}
	System.out.println("��Ϊ��"+R.Long(R));
	System.out.println("��Ϊ��"+R.Wide(R));
	System.out.println("���Ϊ��"+R.Area(R));
	System.out.println("�ܳ�Ϊ��"+R.Circle(R));
	
}
}