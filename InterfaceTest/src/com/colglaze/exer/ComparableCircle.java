package com.colglaze.exer;

public class ComparableCircle extends Circle implements CompareObject {

	public ComparableCircle(double radius) {
		super(radius);
		// TODO Auto-generated constructor stub
	}

	@Override
	public int compareTo(Object o) {
		Circle c=(Circle)o;
		if(super.getRadius()==c.getRadius())
		{
			return 0;
		}
		else if(super.getRadius()>c.getRadius())
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

}
