package colglaze;

public class CustomerList {
	private Customer[] customerList;
	private int total=0;
	public CustomerList()
	{
		
	}
	public CustomerList(int Customertotal)
	{
		customerList=new Customer[Customertotal];
	}
	public boolean addCustomer(Customer customer)
	{
		if(customerList.length<=total)
		{
			System.out.println("数组已满，无法添加成员！");
			return false;
		}
		else
		{
			customerList[total++]=customer;
			return true;
		}
	}
	public boolean replaceCustomer(int aim,Customer customer)
	{
		if(aim<0||aim>=customerList.length)
		{
			System.out.println("不在数组的范围！");
			return false;
		}
		else
		{
			customerList[aim]=customer;
			return true;
		}
	}
	public boolean deleteCustomer(int aim)
	{
		if(aim<0||aim>=customerList.length)
		{
			System.out.println("不在数组范围内！");
			return false;
		}
		else
		{
			for(int i=aim;i<customerList.length-1;i++)
			{
				customerList[i]=customerList[i+1];
			}
			customerList[total-1]=null;
			total--;
			return true;
		}
	}
	public Customer[] getAllcustomer()
	{
		Customer[] allcustomer=new Customer[total];
		for(int i=0;i<total;i++)
		{
			allcustomer[i]=customerList[i];
		}
		return allcustomer;
    }
	public Customer getcustomer(int aim)
	{
		if(aim<0||aim>customerList.length)
		{
			System.out.println("未找到该成员！");
			return null;
		}
		else
		{
			return customerList[aim];
		}
	}
	public int gettotal()
	{
		return total;
	}
}

