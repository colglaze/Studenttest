package com.colglaze.service;

import com.colglaze.domain.Architect;
import com.colglaze.domain.Designer;
import com.colglaze.domain.Employee;
import com.colglaze.domain.Equipment;
import com.colglaze.domain.NoteBook;
import com.colglaze.domain.PC;
import com.colglaze.domain.Printer;
import com.colglaze.domain.Programmer;

public class NameListService {
	private Employee[] employees;

	public NameListService() {
		employees=new Employee[Data.EMPLOYEES.length];
		for(int i=0;i<Data.EMPLOYEES.length ;i++)
		{
			int num=Integer.parseInt(Data.EMPLOYEES[i][0]);
			
			switch(num)
			{
			case Data.EMPLOYEE:
				employees[i]=new Employee(Integer.parseInt(Data.EMPLOYEES[i][1]),Data.EMPLOYEES[i][2],Integer.parseInt(Data.EMPLOYEES[i][3]),Double.parseDouble(Data.EMPLOYEES[i][4]));
				break;
			case Data.ARCHITECT:
				employees[i]=new Architect(Integer.parseInt(Data.EMPLOYEES[i][1]),Data.EMPLOYEES[i][2],Integer.parseInt(Data.EMPLOYEES[i][3]),Double.parseDouble(Data.EMPLOYEES[i][4])
						,0,Status.FREE,setEQUIP(i),Double.parseDouble(Data.EMPLOYEES[i][5]),Integer.parseInt(Data.EMPLOYEES[i][6]));
				
				break;
			case Data.DESIGNER:
				employees[i]=new Designer(Integer.parseInt(Data.EMPLOYEES[i][1]),Data.EMPLOYEES[i][2],Integer.parseInt(Data.EMPLOYEES[i][3]),Double.parseDouble(Data.EMPLOYEES[i][4])
						,0,Status.FREE,setEQUIP(i),Double.parseDouble(Data.EMPLOYEES[i][5]));
				break;
			case Data.PROGRAMMER:
				
				employees[i]=new Programmer(Integer.parseInt(Data.EMPLOYEES[i][1]),Data.EMPLOYEES[i][2],Integer.parseInt(Data.EMPLOYEES[i][3]),Double.parseDouble(Data.EMPLOYEES[i][4])
						,0,Status.FREE,setEQUIP(i));
				break;
			}
		}
		
	}
	public Equipment setEQUIP(int i)
	{
		int num1=Integer.parseInt(Data.EQUIPMENTS[i][0]);
		Equipment equipments=null;
		switch(num1)
		{
		case Data.PC:
			equipments=new PC(Data.EQUIPMENTS[i][1],Data.EQUIPMENTS[i][2]);
			return equipments;
		case Data.NOTEBOOK:
			equipments=new NoteBook(Data.EQUIPMENTS[i][1],Double.parseDouble(Data.EQUIPMENTS[i][2]));
			return equipments;
		case Data.PRINTER:
			equipments=new Printer(Data.EQUIPMENTS[i][1],Data.EQUIPMENTS[i][2]);
			return equipments;
		}
		return null;
		
	}
	public Employee getEmployee(int id) throws TeamException {
		for(int i=0;i<Data.EMPLOYEES.length;i++)
		{
			if(employees[i].getId()==id)
			{
				return employees[i];
			}
			
		}
		throw new TeamException("找不到指定员工!");
	}
	public Employee[] getAllEmployees()
	{
		return employees;
	}
	public void setEmployee(Employee[] employees) {
		this.employees = employees;
	}
	
}
