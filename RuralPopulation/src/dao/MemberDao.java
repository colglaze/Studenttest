package dao;

import bean.Member;

import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-30 -10:21
*/
public interface MemberDao {
    /**
     * 删除家庭成员
     * @param id
     * @return
     */
    int deleteMember(Long id);
    /**
     * 修改家庭成员信息
     * @param newMember
     * @return
     */
    int updateMember(Member newMember) throws Exception;

    /**
     * 查询所有庭成员信息
     * @param
     * @return
     */
    List<Member> queryList();
    /**
     * 查询单个家庭成员信息
     * @param id
     * @return
     */
    ArrayList<Member> queryMember(Long id);

    /**
     * 添加家庭成员
     * @param newMember
     * @return
     */
    int addMember(Member newMember);
}
