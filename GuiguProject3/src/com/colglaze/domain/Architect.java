package com.colglaze.domain;

import com.colglaze.service.Status;

public class Architect extends Designer {
	private int stock;//��Ʊ

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
//\t\tְλ\t\t״̬\t\t����\t\t��Ʊ\t\t�����豸"
	@Override
	public String toString() {
		return super.baseString()+"\t\t�ܹ�ʦ\t\t"+getStatus()+"\t\t"+super.getBous()+"\t\t"+stock+"\t\t"+getEquipment();
	}
	public String TeamString()
	{
		return super.baseString()+"\t\t�ܹ�ʦ\t\t"+super.getBous()+"\t\t"+stock;
	}
}
