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
	public void enterMainMenu()//��������ʾ�����Ʒ���
	{
		char menu = '0';
        while (true) {
            if (menu != '1') {
                listAllEmployees();
            }
            System.out.print("1-�Ŷ��б�  2-����Ŷӳ�Ա  3-ɾ���Ŷӳ�Ա 4-�˳�   ��ѡ��(1-4)��");
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
                    System.out.print("�Ƿ�ȷ���˳�(Y/N)��");
                    char isExit = TSUtility.readConfirmSelection();
                    if (isExit == 'Y') {
                        return;
                    }
            }
        }
	}
	public void listAllEmployees()//�Ա����ʽ�г���ʽ����Ա��
	{
		System.out.println("----------------------- �����Ŷӵ������ -------------------------------\n");
		Employee[] employees=listSvc.getAllEmployees();
		if(employees==null)
		{
			System.out.println("��ǰ�б�Ϊ�գ�����ӳ�Ա");
		}
		else 
		{
			System.out.println("ID\t����\t\t����\t����\t\tְλ\t\t״̬\t\t����\t\t��Ʊ\t\t�����豸");
            for (int i = 0; i < employees.length; i++) {
                System.out.println(employees[i]);
            }
		}
		 System.out.println("---------------------------------------------------------------------");
	}
	public void getTeam()//��ʾ�Ŷӳ�Ա�б����
	{
		
		Programmer[] p=teamSvc.getTeam();
		if(p==null||teamSvc.getTotal()==0)
		{
			System.out.println("��ǰ�б�Ϊ�գ�������ӳ�Ա��");
		}
		else
		{
			//"ID\t����\t\t����\t����\t\tְλ\t\t״̬\t\t����\t\t��Ʊ\t\t�����豸"
			System.out.println("-------------------------- �Ŷӳ�Ա�б� -------------------------------\n");
			 System.out.println("TID/ID\t����\t\t����\t����\t\tְλ\t\t����\t\t��Ʊ");
			for(int i=0;i<teamSvc.getTotal();i++)
			{
				System.out.println(p[i].getMemberid()+"/"+p[i].TeamString());
			}
		}
		
	}
	public void addMember()//ʵ����ӳ�Ա�Ĳ���
	{
		System.out.println("-------------------------- ��ӳ�Ա -------------------------------\n");
        System.out.print("������Ҫ��ӵ�Ա��ID��");
		Employee[] employees=listSvc.getAllEmployees();
		int index=TSUtility.readInt();
		try {
			teamSvc.addMember(employees[index-1]);
			System.out.println("��ӳɹ�");
		} catch (TeamException e) {
			// TODO Auto-generated catch block
			System.out.println("���ʧ��"+e.getMessage());
		}
		TSUtility.readReturn();
	}
	public void deleteMember()//ʵ��ɾ����Ա�Ĳ���
	{
		System.out.println("-------------------------- ɾ����Ա -------------------------------\n");
        System.out.print("������Ҫ��ӵ�Ա��TID��");
        int memberId = TSUtility.readInt();
        System.out.print("�Ƿ�ȷ��ɾ��(Y/N)��");
        char isDelete = TSUtility.readConfirmSelection();
        if (isDelete == 'Y') {
            try {
                teamSvc.removeMember(memberId);
                System.out.println("ɾ���ɹ���");
            } catch (TeamException e) {
                System.out.println("ɾ��ʧ�ܣ�ԭ��" + e.getMessage());
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
