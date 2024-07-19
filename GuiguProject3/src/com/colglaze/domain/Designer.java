package com.colglaze.domain;

import com.colglaze.service.Status;

public class Designer extends Programmer {
	private double bonus;//奖金

	public Designer(int id, String name, int age, double salary, int memberid, Status status, Equipment equipment,
			double bous) {
		super(id, name, age, salary, memberid, status, equipment);
		this.bonus = bous;
	}

	public Designer(int id, String name, int age, double salary, int memberid, Status status, Equipment equipment) {
		super(id, name, age, salary, memberid, status, equipment);
	}

	public double getBous() {
		return bonus;
	}

	public void setBous(double bous) {
		this.bonus = bous;
	}
//\t\t职位\t\t状态\t\t奖金\t\t股票\t\t领用设备"
	@Override
	public String toString() {
		return super.baseString()+"\t\t设计师\t\t"+getStatus()+"\t\t"+bonus+"\t\t\t\t"+getEquipment();
	}
	public String TeamString()
	{
		return super.baseString()+"\t\t设计师\t\t"+bonus;
	}
	
	
}
