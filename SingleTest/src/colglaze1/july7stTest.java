package colglaze1;

public class july7stTest {
	public static void main(String[] args) {
		Single1 s1=Single1.getInstance();
		Single1 s2=Single1.getInstance();
		if(s1==s2)
		{
			System.out.println("s1与s2相同");
		}
		Single2 s3=Single2.getInstannce();
		Single2 s4=Single2.getInstannce();
		if(s3==s4)
		{
			System.out.println("s3与s4相同");
		}
	}
}
