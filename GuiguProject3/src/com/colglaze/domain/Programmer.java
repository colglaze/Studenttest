package com.colglaze.domain;

import com.colglaze.service.Status;

public class Programmer extends Employee {
	private int memberid;
	private Status status=Status.FREE;
	private Equipment equipment;
	public Programmer(int id, String name, int age, double salary, int memberid, Status status, Equipment equipment) {
		super(id, name, age, salary);
		this.memberid = memberid;
		this.status = status;
		this.equipment = equipment;
	}
	public Programmer(int id, String name, int age, double salary) {
		super(id, name, age, salary);
	}
	public int getMemberid() {
		return memberid;
	}
	public void setMemberid(int memberid) {
		this.memberid = memberid;
	}
	public Status getStatus() {
		return status;
	}
	public void setStatus(Status status) {
		this.status = status;
	}
	public Equipment getEquipment() {
		return equipment;
	}
	public void setEquipment(Equipment equipment) {
		this.equipment = equipment;
	}
	//"ID\t姓名\t\t年龄\t工资\t\t职位\t\t状态\t\t奖金\t\t股票\t\t领用设备"
	
	@Override
	public String toString() {
		return super.baseString()+"\t\t程序员\t\t"+status+"\t\t\t\t\t\t"+getEquipment();
	}
	public String TeamString()
	{
		return super.baseString()+"\t\t程序员\t\t";
	}
}
