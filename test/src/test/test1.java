package test;

public class test1 {
public static void main(String[] args) {
	Customer c1=new Customer("Jane","Smith");
	Account Ac1=new Account(1000,2000,0.0123);
	c1.setaccount(Ac1);
	c1.getaccount().deposit(100);
	c1.getaccount().withdraw(960);
	c1.getaccount().withdraw(2000);
	System.out.println("Customer"+"[ "+c1.getfirstname()+c1.getlastname()+" ]"+"has a account: id is"+c1.getaccount().getid()+","+"annualInterestRate is "+c1.getaccount().getannualInterestRate()+",banlance is "+c1.getaccount().getbalance());
	
}
}
