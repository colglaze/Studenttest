package com.colglaze.service;

public class Status {
	private final String NAME;
	private Status(String NAME)
	{
		this.NAME=NAME;
	}
	public static final Status FREE=new Status("FREE");
	public static final Status VOCTION=new Status("VOCYION");
	public static final Status BUSY=new Status("BUSY");
	public String getName()
	{
		return NAME;
	}
	public String toString()
	{
		return NAME;
	}
}
