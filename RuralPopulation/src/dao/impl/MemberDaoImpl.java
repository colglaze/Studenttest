package dao.impl;

import bean.Member;
import dao.BaseDAO;
import dao.MemberDao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-30 -10:24
*/
public class MemberDaoImpl extends BaseDAO implements MemberDao {
    @Override
    public int deleteMember(Long id) {
        String sql = "delete from home_memeber where id = ?";
        try {
            int update = update(sql, id);
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }


    @Override
    public int updateMember(Member newMember) throws Exception {
        String sql = "update home_memeber set name = ?,ident_id = ?,gender = ?,address = ?,phone_num = ?,work_unit = ?,master_id = ?" +
                " where id = ?";
        if (newMember.getId() == null){
            throw new Exception("id为空");
        }
        ArrayList<Member> query = queryMember(newMember.getId());
        Member member = query.get(0);
        //member.setId(newMember.getId());
        if (newMember.getName() != null){
            member.setName(newMember.getName());
        }
        if (newMember.getIdentId() != null){
            member.setIdentId(newMember.getIdentId());
        }
        if (newMember.getGender() != null){
            member.setGender(newMember.getGender());
        }
        if (newMember.getAddress() != null){
            member.setAddress(newMember.getAddress());
        }
        if (newMember.getPhoneNum() != null){
            member.setPhoneNum(newMember.getPhoneNum());
        }
        if (newMember.getWorkUnit() != null){
            member.setWorkUnit(newMember.getWorkUnit());
        }
        if (newMember.getMasterId() != null){
            member.setMasterId(newMember.getMasterId());
        }

        try {
            int update = update(sql, member.getName(), member.getIdentId(), member.getGender(),
                    member.getAddress(), member.getPhoneNum(), member.getWorkUnit(), member.getMasterId(), member.getId());
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public List<Member> queryList() {
        String sql = "select id,master_id masterId,name,ident_id identId,gender,address,phone_num phoneNum,work_unit workUnit" +
                " from home_memeber";
        try {
            List<Member> members = query(Member.class, sql);
            return members;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public ArrayList<Member> queryMember(Long id) {
        String sql = "select id,master_id masterId,name,ident_id identId,gender,address,phone_num phoneNum,work_unit workUnit" +
                " from home_memeber where id = ?";
        try {
            ArrayList<Member> members = query(Member.class, sql, id);
            return members;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public int addMember(Member newMember) {
        String sql = "insert into home_memeber(name,ident_id,gender,address,phone_num,work_unit,master_id)" +
                " values(?,?,?,?,?,?,?)";
        try {
            int update = update(sql, newMember.getName(), newMember.getIdentId(), newMember.getGender(),
                    newMember.getAddress(), newMember.getPhoneNum(), newMember.getWorkUnit(), newMember.getMasterId());
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }
}
