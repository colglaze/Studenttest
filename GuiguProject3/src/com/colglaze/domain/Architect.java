package com.colglaze.domain;

import com.colglaze.service.Status;

public class Architect extends Designer {
	private int stock;//股票

	public Architect(int id, String name, int age, double salary, int memberid, Status status, Equipment equipment,
			double bous, int stock) {
		super(id, name, age, salary, memberid, status, equipment, bous);
		this.stock = stock;
	}

	public Architect(int id, String name, int age, double salary, int memberid, Status status, Equipment equipment,
			double bous) {
		super(id, name, age, salary, memberid, status, equipment, bous);
	}

	public int getStock() {
		return stock;
	}

	public void setStock(int stock) {
		this.stock = stock;
	}
//\t\t职位\t\t状态\t\t奖金\t\t股票\t\t领用设备"
	@Override
	public String toString() {
		return super.baseString()+"\t\t架构师\t\t"+getStatus()+"\t\t"+super.getBous()+"\t\t"+stock+"\t\t"+getEquipment();
	}
	public String TeamString()
	{
		return super.baseString()+"\t\t架构师\t\t"+super.getBous()+"\t\t"+stock;
	}
}
