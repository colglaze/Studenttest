package com.colglaze.schedule.test;

import com.colglaze.schedule.dao.SysUserDao;
import com.colglaze.schedule.dao.impl.SysUserDaoImpl;
import com.colglaze.schedule.pojo.SysUser;
import org.junit.BeforeClass;
import org.junit.Test;

import java.util.List;

/*
@author ColGlaze
@create 2024-09-08 -15:53
*/
public class TestSysUserDaoImpl {
    public static SysUserDao sysUser;
    @BeforeClass
    public static void initSysUser()
    {
        sysUser = new SysUserDaoImpl();
    }
    @Test
    public void testAdd()
    {
        int i = sysUser.addSysUser(new SysUser(null, "glasss", "123456"));
        System.out.println(i);
    }
    @Test
    public void findAll()
    {
        List<SysUser> all = sysUser.findAll();
        for (SysUser user : all) {
            System.out.println(user);

        }
    }
}
