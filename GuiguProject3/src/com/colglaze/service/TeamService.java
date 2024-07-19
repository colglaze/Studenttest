package com.colglaze.service;

import com.colglaze.domain.Architect;
import com.colglaze.domain.Designer;
import com.colglaze.domain.Employee;
import com.colglaze.domain.Programmer;

public class TeamService {
	public static int counter=1;//memberid
	public final int MAX_MEMBER=5;
	private Programmer[] team=new Programmer[MAX_MEMBER];
	private int total=0;//记录团队成员总数
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
			throw new TeamException("成员已满，无法添加");
		}
		if(!(e instanceof Programmer))
		{
			throw new TeamException("该成员不是开发成员，无法添加");
		}
		if(isExit(e))
		{
			throw new TeamException("该员工已在本开发团队中");
		}
		Programmer p=(Programmer)e;
		if(p.getStatus().equals(Status.BUSY))
		{
			throw new TeamException("该员工已是某开发团队的成员");
		}
		if(p.getStatus().equals(Status.VOCTION))
		{
			throw new TeamException("该员工正在度假，无法添加");
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
				throw new TeamException("团队中至多只能有一名架构师");
			}
		}
		else if(e instanceof Designer)
		{
			if(numofDesigner>=2)
			{
				throw new TeamException("团队中至多只能有两名设计师");
			}
		}
		else if(e instanceof Programmer)
		{
			if(numofProgrammer>=3)
			{
				throw new TeamException("团队中至多只能有三名程序员");
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
//			throw new TeamException("团队为空，请先添加团队成员");
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
//				throw new TeamException("未找到该成员，删除失败");
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
                //将该员工的status置为FREE
                team[i].setStatus(Status.FREE);
                //删除元素，后面的元素覆盖前面的元素
                for (int j = i; j < total - 1; j++) {
                    team[j] = team[j + 1];
                }
                //最后一个元素置成null
                team[total - 1] = null;
                //当前团队成员数减1
                total--;
                return;
            }
        }
        throw new TeamException("找不到指定memberId的员工，删除失败");
    }
}

