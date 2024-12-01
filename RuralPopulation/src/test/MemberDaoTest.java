package test;

import bean.Member;
import dao.MemberDao;
import dao.impl.MemberDaoImpl;
import org.junit.Test;

import java.util.ArrayList;

/*
@author ColGlaze
@create 2024-11-30 -10:48
*/
public class MemberDaoTest {
    @Test
    public void testAdd() {
        MemberDao memberDao = new MemberDaoImpl();
        Member member = new Member(null, "小王", "123456789012345678", "男", "上海", "12345678901", "上海银行", 1L);
        memberDao.addMember(member);
    }

    @Test
    public void testDelete() {
        MemberDao memberDao = new MemberDaoImpl();
        memberDao.deleteMember(14L);
    }

    @Test
    public void testUpdate() throws Exception {
        MemberDao memberDao = new MemberDaoImpl();
        Member member = new Member(12L, "大王", null, null, null, null, null, 2L);
        memberDao.updateMember(member);
    }

    @Test
    public void testQuery() {
        MemberDao memberDao = new MemberDaoImpl();
        ArrayList<Member> members = memberDao.queryMember(1L);
        for (Member member : members) {
            System.out.println(member);
        }
    }

    @Test
    public void testQueryList() {
        MemberDao memberDao = new MemberDaoImpl();
        ArrayList<Member> members = (ArrayList<Member>) memberDao.queryList();
        for (Member member : members) {
            System.out.println(member);
        }
    }
}
