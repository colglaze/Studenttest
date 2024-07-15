package colglaze;

import java.util.Scanner;

public class Ecmdef {
	
	public static void main(String[] args)  {
		
		Scanner scan = new Scanner(System.in);
		int[] arr= new int[3];
		try
		{
			
				arr[0]=scan.nextInt();
				arr[1]=scan.nextInt();
				System.out.println(ecm(arr[0],arr[1]));
			
		}
		catch(NumberFormatException e) //��ʽ����
		{
			System.out.println(e.getMessage());
		}
		catch(ArithmeticException e)
		{
			System.out.println(e.getMessage());
		}
		catch(ZeroException e)
		{
			System.out.println(e.getMessage());
		}
		catch(ArrayIndexOutOfBoundsException e)//�ٲ���
		{
			System.out.println(e.getMessage());
		}
		
	}
	public static double ecm(int a,int b) throws ZeroException 
	{
		if(b==0)
		{
			throw new ArithmeticException("��0");
		}
		if(b<0||a<0)
		{
			throw new ZeroException("���븺��");
		}
		return a/b;
	}
}
