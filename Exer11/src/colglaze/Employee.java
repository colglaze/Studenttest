package colglaze;

public abstract class Employee {
	private String name;
	private int num;
	private MyDate brithday;
	public abstract double earnings();
	public String toString()
	{
		return "name:"+name+" num"+num+" brithday:"+brithday;
	}
	
	public Employee(String name,int num,MyDate brithday)
	{
		this.brithday=brithday;
		this.name=name;
		this.num=num;
	}
	public void setName(String name)
	{
		this.name=name;
	}
	public String getName()
	{
		return name;
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public MyDate getBrithday() {
		return brithday;
	}
	public void setBrithday(MyDate brithday) {
		this.brithday = brithday;
	}
	
}
