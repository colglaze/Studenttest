package colglaze;

public class Customer {
	private String name;
	private int age;
	private char gender;
	private String email;
	private String phone;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public char getGender() {
		return gender;
	}
	public void setGender(char gender) {
		this.gender = gender;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getPhone() {
		return phone;
	}
	public void setPhone(String phone) {
		this.phone = phone;
	}
	public Customer()
	{
		
	}
	public Customer(String name,int age,char gender,String email,String phone)
	{
		this.age=age;
		this.email=email;
		this.gender=gender;
		this.name=name;
		this.phone=phone;
	}
}
