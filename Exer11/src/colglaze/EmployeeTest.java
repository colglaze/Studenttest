package colglaze;

public class EmployeeTest {
	public static void main(String[] args) {
		SalariedEmployee se=new SalariedEmployee("¿Ó",1001,new MyDate(2005,11,8),60000);
		System.out.println(se.earnings());
		
	}
}
