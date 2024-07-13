package colglaze;

public class SalariedEmployee extends Employee {
	private double monthlySalary;
	
	
//	public SalariedEmployee() {
//		//super();
//		// TODO Auto-generated constructor stub
//	}


	public SalariedEmployee(String name, int num, MyDate brithday,double monthlySalary) {
		super(name, num, brithday);
		this.monthlySalary= monthlySalary;
		// TODO Auto-generated constructor stub
	}


	@Override
	public String toString() {
		return "SalariedEmployee [getName()=" + getName() + ", getNum()=" + getNum() + ", getBrithday()="
				+ getBrithday() + "]";
	}


	public double getMonthlySalary() {
		return monthlySalary;
	}


	public void setMonthlySalary(double monthlySalary) {
		this.monthlySalary = monthlySalary;
	}


	@Override
	public double earnings() {
		if(super.getBrithday().getMonth()==11)
		{
			monthlySalary+=100;
		}
		return monthlySalary;
	}

}
