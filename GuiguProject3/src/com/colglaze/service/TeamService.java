package com.colglaze.service;

import com.colglaze.domain.Architect;
import com.colglaze.domain.Designer;
import com.colglaze.domain.Employee;
import com.colglaze.domain.Programmer;

public class TeamService {
	public static int counter=1;//memberid
	public final int MAX_MEMBER=5;
	private Programmer[] team=new Programmer[MAX_MEMBER];
	private int total=0;//��¼�Ŷӳ�Ա����
	public int getTotal()
	{
		return total;
	}
	public Programmer[] getTeam()
	{
		return team;
	}
	
	
	public void addMember(Employee e) throws TeamException
	{
		int numofArchitect=0;
		int numofDesigner=0;
		int numofProgrammer=0;
		if(total>=MAX_MEMBER)
		{
			throw new TeamException("��Ա�������޷����");
		}
		if(!(e instanceof Programmer))
		{
			throw new TeamException("�ó�Ա���ǿ�����Ա���޷����");
		}
		if(isExit(e))
		{
			throw new TeamException("��Ա�����ڱ������Ŷ���");
		}
		Programmer p=(Programmer)e;
		if(p.getStatus().equals(Status.BUSY))
		{
			throw new TeamException("��Ա������ĳ�����Ŷӵĳ�Ա");
		}
		if(p.getStatus().equals(Status.VOCTION))
		{
			throw new TeamException("��Ա�����ڶȼ٣��޷����");
		}
		
		
			for(int i=0;i<total;i++)
			{
				if(team[i] instanceof Architect)
				{
					numofArchitect++;
				}
				else if(team[i] instanceof Designer)
				{
					numofDesigner++;
				}
				else if(team[i] instanceof Programmer)
				{
					numofProgrammer++;
				}
			}
		
		if(e instanceof Architect)
		{
			if(numofArchitect>=1)
			{
				throw new TeamException("�Ŷ�������ֻ����һ���ܹ�ʦ");
			}
		}
		else if(e instanceof Designer)
		{
			if(numofDesigner>=2)
			{
				throw new TeamException("�Ŷ�������ֻ�����������ʦ");
			}
		}
		else if(e instanceof Programmer)
		{
			if(numofProgrammer>=3)
			{
				throw new TeamException("�Ŷ�������ֻ������������Ա");
			}
		}
		Programmer pro=(Programmer)e;
		team[total++]=pro;
		pro.setStatus(Status.BUSY);
		pro.setMemberid(counter++);

		e=pro;

		
	}
	
	public boolean isExit(Employee e)
	{
		for(int i=0;i<total;i++)
		{
			if(e.getId()==team[i].getId())
			{
				return true;
			}
		}
		return false;
	}
//	public void removeMember(int memberid) throws TeamException
//	{
//		int i=0;
//		if(total==0)
//		{
//			throw new TeamException("�Ŷ�Ϊ�գ���������Ŷӳ�Ա");
//		}
//		for(i=0;i<total;i++)
//		{
//			if(team[i].getMemberid()==memberid)
//			{
//				team[i].setStatus(Status.FREE);
//				for(int j=i;j<total-2;j++)
//				{
//					team[j]=team[j+1];
//				}
//				team[--total]=null;
//				break;
//			}
//			else if(i==total-1)
//			{
//				throw new TeamException("δ�ҵ��ó�Ա��ɾ��ʧ��");
//			}
//		}
////		team[i].setStatus(Status.FREE);
////		for(int j=i;j<total-2;j++)
////		{
////			team[j]=team[j+1];
////		}
////		team[--total]=null;
//		
//	}
	public void removeMember(int memberId) throws TeamException {
        for (int i = 0; i < total; i++) {
            if (team[i].getMemberid() == memberId) {
                //����Ա����status��ΪFREE
                team[i].setStatus(Status.FREE);
                //ɾ��Ԫ�أ������Ԫ�ظ���ǰ���Ԫ��
                for (int j = i; j < total - 1; j++) {
                    team[j] = team[j + 1];
                }
                //���һ��Ԫ���ó�null
                team[total - 1] = null;
                //��ǰ�Ŷӳ�Ա����1
                total--;
                return;
            }
        }
        throw new TeamException("�Ҳ���ָ��memberId��Ա����ɾ��ʧ��");
    }
}

