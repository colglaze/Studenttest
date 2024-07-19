package com.colglaze.domain;

public class Printer implements Equipment {

	@Override
	public String toString() {
		return getDescription();
	}
	private String name;
	private String type;//»úÆ÷ÀàÐÍ
	public Printer() {
		super();
	}
	public Printer(String name, String type) {
		super();
		this.name = name;
		this.type = type;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	@Override
	public String getDescription() {
		return type+"("+name+")";
	}
	

}
