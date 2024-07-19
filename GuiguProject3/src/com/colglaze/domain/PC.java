package com.colglaze.domain;

public class PC implements Equipment {
	@Override
	public String toString() {
		return getDescription();
	}

	private String model;//�������ͺ�
	private String display;//��������
	
	public PC() {
		super();
	}

	public PC(String model, String display) {
		super();
		this.model = model;
		this.display = display;
	}

	public String getModel() {
		return model;
	}

	public void setModel(String model) {
		this.model = model;
	}

	public String getDisplay() {
		return display;
	}

	public void setDisplay(String display) {
		this.display = display;
	}

	@Override
	public String getDescription() {
	
		return model+"("+display+")";
	}
	

}
