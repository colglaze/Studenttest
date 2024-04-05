package test;

public class Account {
	private int id;
	private double balance;
	private double annualInterestRate;
	public Account(int id,double balance,double annualInterestRate)
	{
		this.id=id;
		this.balance=balance;
		this.annualInterestRate=annualInterestRate;
	}
	public int getid()
	{
		return id;
	}
	public void setid(int id)
	{
		this.id=id;
	}
	public double getbalance()
	{
		return balance;
	}
	public void setbalnace(double balance)
	{
		this.balance=balance;
	}
	public double getannualInterestRate()
	{
		return annualInterestRate;
	}
	public void setannualInterestRate(double annualInterestRate)
	{
		this.annualInterestRate=annualInterestRate;
	}
	public void withdraw(double amount)
	{
		if(balance<amount)
		{
			System.out.println("取款失败！");
			return;
		}
		else
		{
			balance-=amount;
			System.out.println("取出："+amount);
		}
	}
	public void deposit(double amount)
	{
		if(amount>0)
		{
			balance+=amount;
			System.out.println("成功存入："+amount);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
