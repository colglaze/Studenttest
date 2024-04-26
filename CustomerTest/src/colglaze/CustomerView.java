package colglaze;

public class CustomerView {
	CustomerList customerlist=new CustomerList(10);
	public void enterMainMenu()
	{
		boolean isExit=true;
		while(isExit)
		{
			System.out.println("\n-----------------客户信息管理软件-----------------\n");
			System.out.println("                   1 添 加 客 户");
			System.out.println("                   2 修 改 客 户");
			System.out.println("                   3 删 除 客 户");
			System.out.println("                   4 客 户 列 表");
			System.out.println("                   5 退       出\\n");
			System.out.print("                   请选择(1-5)：");
			char choice=utility.readMenuSelection();
			switch(choice)
			{
			case '1':
				addNewCustomer();
				break;
			case '2':
				modifyCustomer();
				break;
			case'3':
				deleteCustomer();
				break;
			case'4':
				viewCustomer();
				break;
			case'5':
				System.out.println("是否确认退出(Y/N)");
				char exitInfo=utility.readConfirmSelection();
				if(exitInfo=='Y')
				{
					isExit=false;
				}
				break;
			}
		}
		System.out.println("程序已退出！");
	}
	private void addNewCustomer()
	{
		   System.out.println("-------------------添加客户-------------------");
		   System.out.print("姓名：");
		   String name=utility.readString(5);
		   System.out.print("性别：");
		   char gender=utility.readChar();
		   System.out.print("年龄：");
		   int age=utility.readInt();
		   System.out.print("电话: ");
		   String phone=utility.readString(13);
		   System.out.print("邮箱：");
		   String email=utility.readString(30);
		   Customer customer=new Customer(name,age,gender,email,phone);
		   boolean isAdd=customerlist.addCustomer(customer);
		   if(isAdd)
		   {
			   System.out.println("-------------------添加成功-------------------");
		   }
		   else
		   {
			   System.out.println("----------------记录已满，无法添加----------------");
		   }
	}
	private void modifyCustomer()
	{
		System.out.println("-------------------修改客户-------------------");
		int number;
		while(true)
		{
			System.out.println("请选择待修改用户的编号，输入（-1）退出");
			number=utility.readInt();
			if(number==-1)
			{
				return;
			}
			Customer modCustomer=customerlist.getcustomer(number-1);
			if(modCustomer==null)
			{
				System.out.println("无法找到该用户！");
			}
			else
			{
				System.out.println("姓名("+modCustomer.getName()+")");
				String name=utility.readString(5, modCustomer.getName());
				System.out.println("性别("+modCustomer.getGender()+")");
				char gender=utility.readChar(modCustomer.getGender());
				System.out.println("年龄("+modCustomer.getAge()+")");
				int age=utility.readInt(modCustomer.getAge());
				System.out.println("电话("+modCustomer.getPhone()+")");
				String phone=utility.readString(13, modCustomer.getPhone());
				System.out.println("邮箱("+modCustomer.getEmail()+")");
				String email=utility.readString(30, modCustomer.getEmail());
				Customer replaceCustomer=new Customer(name,age,gender,email,phone);
				boolean isMod=customerlist.replaceCustomer(number-1, replaceCustomer);
				if(isMod)
				{
					System.out.println("-------------------修改成功-------------------");
					break;
				}
				else
				{
					System.out.println("-------------无法找到指定客户，修改失败--------------");
					break;
				}
			}
		}
	}
	private void deleteCustomer()
	{
		System.out.println("-------------------删除客户-------------------");
		int number;
		while(true)
		{
			System.out.println("请选择待删除用户的编号，输入（-1）退出");
			number=utility.readInt();
			if(number==-1)
			{
				return;
			}
			
				Customer deleteCustomer=customerlist.getcustomer(number-1);
				if(deleteCustomer==null)
				{
					System.out.println("无法找到指定用户!");
				}
				else
				{
					System.out.println("确认是否删除(Y/N)");
					char isYN=utility.readConfirmSelection();
					if(isYN=='Y')
					{
						boolean isDelete=customerlist.deleteCustomer(number-1);
						if(isDelete)
						{
							System.out.println("-------------------删除成功-------------------");
							return;
						}
						else
						{
							System.out.println("-------------无法找到指定用户，删除失败--------------");
							
						}
					}
					else
					{
						break;
					}
				}
			
	}
		}
	private void viewCustomer()
	{
		System.out.println("-------------------客户列表-------------------");
		int custNum=customerlist.gettotal();
		if(custNum<=0)
		{
			System.out.println("没有找到客户信息记录！");
		}
		else
		{
				System.out.println("编号  姓名  性别  年龄  电话         邮箱");
				Customer[] custlist=customerlist.getAllcustomer();
				for(int i=0;i<custlist.length;i++)
				{
					System.out.println((i+1)+"  "+custlist[i].getName()+"  "+custlist[i].getGender()+"  "+custlist[i].getAge()+"  "+custlist[i].getPhone()+"  "+custlist[i].getEmail());
					
				}
			
		}
		System.out.println("-------------------客户列表完成-------------------");
	}
public static void main(String[] args) {
	CustomerView menu=new CustomerView();
	menu.enterMainMenu();
}
}
