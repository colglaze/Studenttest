package Demo;

public class ct {
	public static void main(String[] args)
	{
		int[] arr=new int[] {1,5,9,8,7,2,55,3,6};
		for(int i=0;i<arr.length-1;i++)
		{
			for(int j=0;j<arr.length-1-i;j++)
			{
				if(arr[j+1]<arr[j])
				{
					int tmp=arr[j+1];
					arr[j+1]=arr[j];
					arr[j]=tmp;
					
				}
			}
			
		}
		for(int i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]);
		}
	}

}
