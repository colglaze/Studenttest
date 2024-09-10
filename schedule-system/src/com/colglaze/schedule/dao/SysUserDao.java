package com.colglaze.schedule.dao;

import com.colglaze.schedule.pojo.SysUser;

import java.util.List;

/*
@author ColGlaze
@create 2024-09-06 -21:13
*/
public interface SysUserDao {
    /**
     * 用于向SysUser添加数据
     * @param sysUser
     * @return  返回值大于0，表示添加成功，小于等于0则表示失败
     */
    int addSysUser(SysUser sysUser);

    /**
     * 用于查询SysUser表格中的所有数据
     * @return 返回表中所有数据
     */
    List<SysUser> findAll();

}
