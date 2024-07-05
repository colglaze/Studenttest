package colglaze1;

import java.util.Scanner;
import java.util.Vector;

public class ScoreTest {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int score = 0;
		Vector v = new Vector();
		int maxScore = 0;
		while(true)
		{
			score = scan.nextInt();
			if(score < 0)
			{
				break;
			}
			if(score > 100)
			{
				System.out.println("输入数据非法，请重新输入！");
				continue;
			}
			Integer in1 = score;//Integer in1=new Integer(score);
			v.addElement(in1);
			if(maxScore < score)
			{
				maxScore = score;
			}
		}
		System.out.println("最高分为："+maxScore);
		for(int i=0;i<v.size();i++)
		{
			Object obj=v.elementAt(i);
			Integer in = (Integer)obj;
//			int num = in.intValue();
			if(maxScore - in <= 10)
			{
				System.out.println('A');
			}
			else if(maxScore - in <= 20)
			{
				System.out.println('B');
			}
			else if(maxScore - in <= 30)
			{
				System.out.println('C');
			}
			else
			{
				System.out.println('D');
			}
		}
	}
}
