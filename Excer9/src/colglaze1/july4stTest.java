package colglaze1;

public class july4stTest {
	public static void main(String[] args) {
		Circle c1=new Circle(4.3);
		Circle c2=new Circle(2.3);
		System.out.println("c1��c2�뾶�Ƿ���ȣ�"+c1.equals(c2));
		System.out.println("c1���Ϊ��"+c1.findArea());
		System.out.println("c2���Ϊ��"+c2.findArea());
		System.out.println("c1�뾶Ϊ��"+c1.toString());
		System.out.println("c2�뾶Ϊ��"+c2.toString());
	}
}
