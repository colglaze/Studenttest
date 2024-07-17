package com.colglaze.exer;

public class TestInterface {
	public static void main(String[] args) {
		ComparableCircle c1=new ComparableCircle(9.9);
		ComparableCircle c2=new ComparableCircle(7.9);
		System.out.println(c1.compareTo(c2));
	}
}
