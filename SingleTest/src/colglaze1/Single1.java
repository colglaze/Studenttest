package colglaze1;

public class Single1 {
	//饿汉模式
	private Single1() {
		
	}
	private static Single1 instance=new Single1();
	public static Single1 getInstance()
	{
		return instance;
	}
}
