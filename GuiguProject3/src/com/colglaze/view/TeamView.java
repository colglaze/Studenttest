package com.colglaze.view;

import com.colglaze.domain.Employee;
import com.colglaze.domain.Programmer;
import com.colglaze.jutility.TSUtility;
import com.colglaze.service.NameListService;
import com.colglaze.service.TeamException;
import com.colglaze.service.TeamService;

public class TeamView {
	private NameListService listSvc=new NameListService();
	private TeamService teamSvc=new TeamService();
	public void enterMainMenu()//主界面显示及控制方法
	{
		char menu = '0';
        while (true) {
            if (menu != '1') {
                listAllEmployees();
            }
            System.out.print("1-团队列表  2-添加团队成员  3-删除团队成员 4-退出   请选择(1-4)：");
            menu = TSUtility.readMenuSelection();
            switch (menu) {
                case '1':
                    getTeam();
                    break;
                case '2':
                    addMember();
                    break;
                case '3':
                    deleteMember();
                    break;
                case '4':
                    System.out.print("是否确认退出(Y/N)：");
                    char isExit = TSUtility.readConfirmSelection();
                    if (isExit == 'Y') {
                        return;
                    }
            }
        }
	}
	public void listAllEmployees()//以表格形式列出公式所有员工
	{
		System.out.println("----------------------- 开发团队调度软件 -------------------------------\n");
		Employee[] employees=listSvc.getAllEmployees();
		if(employees==null)
		{
			System.out.println("当前列表为空，请添加成员");
		}
		else 
		{
			System.out.println("ID\t姓名\t\t年龄\t工资\t\t职位\t\t状态\t\t奖金\t\t股票\t\t领用设备");
            for (int i = 0; i < employees.length; i++) {
                System.out.println(employees[i]);
            }
		}
		 System.out.println("---------------------------------------------------------------------");
	}
	public void getTeam()//显示团队成员列表操作
	{
		
		Programmer[] p=teamSvc.getTeam();
		if(p==null||teamSvc.getTotal()==0)
		{
			System.out.println("当前列表为空！请先添加成员！");
		}
		else
		{
			//"ID\t姓名\t\t年龄\t工资\t\t职位\t\t状态\t\t奖金\t\t股票\t\t领用设备"
			System.out.println("-------------------------- 团队成员列表 -------------------------------\n");
			 System.out.println("TID/ID\t姓名\t\t年龄\t工资\t\t职位\t\t奖金\t\t股票");
			for(int i=0;i<teamSvc.getTotal();i++)
			{
				System.out.println(p[i].getMemberid()+"/"+p[i].TeamString());
			}
		}
		
	}
	public void addMember()//实现添加成员的操作
	{
		System.out.println("-------------------------- 添加成员 -------------------------------\n");
        System.out.print("请输入要添加的员工ID：");
		Employee[] employees=listSvc.getAllEmployees();
		int index=TSUtility.readInt();
		try {
			teamSvc.addMember(employees[index-1]);
			System.out.println("添加成功");
		} catch (TeamException e) {
			// TODO Auto-generated catch block
			System.out.println("添加失败"+e.getMessage());
		}
		TSUtility.readReturn();
	}
	public void deleteMember()//实现删除成员的操作
	{
		System.out.println("-------------------------- 删除成员 -------------------------------\n");
        System.out.print("请输入要添加的员工TID：");
        int memberId = TSUtility.readInt();
        System.out.print("是否确认删除(Y/N)：");
        char isDelete = TSUtility.readConfirmSelection();
        if (isDelete == 'Y') {
            try {
                teamSvc.removeMember(memberId);
                System.out.println("删除成功！");
            } catch (TeamException e) {
                System.out.println("删除失败，原因：" + e.getMessage());
            }
            TSUtility.readReturn();
        }
	}
	public static void main(String[] args) {
		TeamView t=new TeamView();
		//t.listAllEmployees();
		t.enterMainMenu();
		
	}
}
