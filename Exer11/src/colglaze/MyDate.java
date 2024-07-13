package colglaze;

public class MyDate {
	private int year;
	private int month;
	private int day;
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}
	public int getMonth() {
		return month;
	}
	public void setMonth(int month) {
		this.month = month;
	}
	public int getDay() {
		return day;
	}
	public void setDay(int day) {
		this.day = day;
	}
//	public MyDate()
//	{
//		
//	}
	public MyDate(int year,int month,int day)
	{
		this.year=year;
		this.day=day;
		this.month=month;
	}
	public String toDateString()
	{
		return year+"Äê"+month+"ÔÂ"+day+"ÈÕ";
	}
}
