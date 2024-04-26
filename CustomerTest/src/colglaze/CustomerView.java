package colglaze;

public class CustomerView {
	CustomerList customerlist=new CustomerList(10);
	public void enterMainMenu()
	{
		boolean isExit=true;
		while(isExit)
		{
			System.out.println("\n-----------------�ͻ���Ϣ�������-----------------\n");
			System.out.println("                   1 �� �� �� ��");
			System.out.println("                   2 �� �� �� ��");
			System.out.println("                   3 ɾ �� �� ��");
			System.out.println("                   4 �� �� �� ��");
			System.out.println("                   5 ��       ��\\n");
			System.out.print("                   ��ѡ��(1-5)��");
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
				System.out.println("�Ƿ�ȷ���˳�(Y/N)");
				char exitInfo=utility.readConfirmSelection();
				if(exitInfo=='Y')
				{
					isExit=false;
				}
				break;
			}
		}
		System.out.println("�������˳���");
	}
	private void addNewCustomer()
	{
		   System.out.println("-------------------��ӿͻ�-------------------");
		   System.out.print("������");
		   String name=utility.readString(5);
		   System.out.print("�Ա�");
		   char gender=utility.readChar();
		   System.out.print("���䣺");
		   int age=utility.readInt();
		   System.out.print("�绰: ");
		   String phone=utility.readString(13);
		   System.out.print("���䣺");
		   String email=utility.readString(30);
		   Customer customer=new Customer(name,age,gender,email,phone);
		   boolean isAdd=customerlist.addCustomer(customer);
		   if(isAdd)
		   {
			   System.out.println("-------------------��ӳɹ�-------------------");
		   }
		   else
		   {
			   System.out.println("----------------��¼�������޷����----------------");
		   }
	}
	private void modifyCustomer()
	{
		System.out.println("-------------------�޸Ŀͻ�-------------------");
		int number;
		while(true)
		{
			System.out.println("��ѡ����޸��û��ı�ţ����루-1���˳�");
			number=utility.readInt();
			if(number==-1)
			{
				return;
			}
			Customer modCustomer=customerlist.getcustomer(number-1);
			if(modCustomer==null)
			{
				System.out.println("�޷��ҵ����û���");
			}
			else
			{
				System.out.println("����("+modCustomer.getName()+")");
				String name=utility.readString(5, modCustomer.getName());
				System.out.println("�Ա�("+modCustomer.getGender()+")");
				char gender=utility.readChar(modCustomer.getGender());
				System.out.println("����("+modCustomer.getAge()+")");
				int age=utility.readInt(modCustomer.getAge());
				System.out.println("�绰("+modCustomer.getPhone()+")");
				String phone=utility.readString(13, modCustomer.getPhone());
				System.out.println("����("+modCustomer.getEmail()+")");
				String email=utility.readString(30, modCustomer.getEmail());
				Customer replaceCustomer=new Customer(name,age,gender,email,phone);
				boolean isMod=customerlist.replaceCustomer(number-1, replaceCustomer);
				if(isMod)
				{
					System.out.println("-------------------�޸ĳɹ�-------------------");
					break;
				}
				else
				{
					System.out.println("-------------�޷��ҵ�ָ���ͻ����޸�ʧ��--------------");
					break;
				}
			}
		}
	}
	private void deleteCustomer()
	{
		System.out.println("-------------------ɾ���ͻ�-------------------");
		int number;
		while(true)
		{
			System.out.println("��ѡ���ɾ���û��ı�ţ����루-1���˳�");
			number=utility.readInt();
			if(number==-1)
			{
				return;
			}
			
				Customer deleteCustomer=customerlist.getcustomer(number-1);
				if(deleteCustomer==null)
				{
					System.out.println("�޷��ҵ�ָ���û�!");
				}
				else
				{
					System.out.println("ȷ���Ƿ�ɾ��(Y/N)");
					char isYN=utility.readConfirmSelection();
					if(isYN=='Y')
					{
						boolean isDelete=customerlist.deleteCustomer(number-1);
						if(isDelete)
						{
							System.out.println("-------------------ɾ���ɹ�-------------------");
							return;
						}
						else
						{
							System.out.println("-------------�޷��ҵ�ָ���û���ɾ��ʧ��--------------");
							
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
		System.out.println("-------------------�ͻ��б�-------------------");
		int custNum=customerlist.gettotal();
		if(custNum<=0)
		{
			System.out.println("û���ҵ��ͻ���Ϣ��¼��");
		}
		else
		{
				System.out.println("���  ����  �Ա�  ����  �绰         ����");
				Customer[] custlist=customerlist.getAllcustomer();
				for(int i=0;i<custlist.length;i++)
				{
					System.out.println((i+1)+"  "+custlist[i].getName()+"  "+custlist[i].getGender()+"  "+custlist[i].getAge()+"  "+custlist[i].getPhone()+"  "+custlist[i].getEmail());
					
				}
			
		}
		System.out.println("-------------------�ͻ��б����-------------------");
	}
public static void main(String[] args) {
	CustomerView menu=new CustomerView();
	menu.enterMainMenu();
}
}
