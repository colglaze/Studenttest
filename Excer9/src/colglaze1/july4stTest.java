package colglaze1;

public class july4stTest {
	public static void main(String[] args) {
		Circle c1=new Circle(4.3);
		Circle c2=new Circle(2.3);
		System.out.println("c1和c2半径是否相等："+c1.equals(c2));
		System.out.println("c1面积为："+c1.findArea());
		System.out.println("c2面积为："+c2.findArea());
		System.out.println("c1半径为："+c1.toString());
		System.out.println("c2半径为："+c2.toString());
	}
}
