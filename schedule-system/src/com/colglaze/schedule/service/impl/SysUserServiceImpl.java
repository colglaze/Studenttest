package com.colglaze.schedule.service.impl;

import com.colglaze.schedule.dao.SysUserDao;
import com.colglaze.schedule.dao.impl.SysUserDaoImpl;
import com.colglaze.schedule.pojo.SysUser;
import com.colglaze.schedule.service.SysUserService;
import com.colglaze.schedule.util.MD5util;

/*
@author ColGlaze
@create 2024-09-08 -16:06
*/
public class SysUserServiceImpl implements SysUserService {

    private SysUserDao userDao = new SysUserDaoImpl();
    @Override
    public int regist(SysUser sysUser) {
        //将用户的明文密码转换为密文
        String encrypt = MD5util.encrypt(sysUser.getUserPwd());
        sysUser.setUserPwd(encrypt);
        int flag = userDao.addSysUser(sysUser);
        return flag;
    }

    @Override
    public int login(SysUser sysUser) {
        String encrypt = MD5util.encrypt(sysUser.getUserPwd());
        for (SysUser user : userDao.findAll()) {
            if (user.getUsername().equals(sysUser.getUsername()))
            {
                if (user.getUserPwd().equals(encrypt))
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }

        }
        return 0;
    }
}


































