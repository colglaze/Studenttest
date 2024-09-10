package com.colglaze.schedule.dao.impl;

import com.colglaze.schedule.dao.BaseDao;
import com.colglaze.schedule.dao.SysUserDao;
import com.colglaze.schedule.pojo.SysUser;

import java.sql.SQLException;
import java.util.List;

/*
@author ColGlaze
@create 2024-09-07 -19:06
*/
public class SysUserDaoImpl extends BaseDao implements SysUserDao {

    @Override
    public int addSysUser(SysUser sysUser) {
        String sql = "INSERT INTO sys_user VALUES(NULL,?,?)";
        int update;
        try {
            update = update(sql, sysUser.getUsername(), sysUser.getUserPwd());
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return update;
    }

    @Override
    public List<SysUser> findAll() {
        String sql = "SELECT uid,username,user_pwd 'userPwd' FROM sys_user";
        try {
            return query(SysUser.class, sql);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
