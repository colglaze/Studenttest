package colglaze1;

public class Single2 {
	//����ģʽ
	private Single2()
	{
		
	}
	private static Single2 instance=null;
	public static Single2 getInstannce()
	{
		if(instance==null)
		{
			instance=new Single2();
		}
		return instance;
	}
}
