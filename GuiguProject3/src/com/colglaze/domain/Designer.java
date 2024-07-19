package com.colglaze.domain;

import com.colglaze.service.Status;

public class Designer extends Programmer {
	private double bonus;//����

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
//\t\tְλ\t\t״̬\t\t����\t\t��Ʊ\t\t�����豸"
	@Override
	public String toString() {
		return super.baseString()+"\t\t���ʦ\t\t"+getStatus()+"\t\t"+bonus+"\t\t\t\t"+getEquipment();
	}
	public String TeamString()
	{
		return super.baseString()+"\t\t���ʦ\t\t"+bonus;
	}
	
	
}
