package com.colglaze.schedule.service;

import com.colglaze.schedule.pojo.SysUser;

/*
@author ColGlaze
@create 2024-09-08 -16:05
*/
public interface SysUserService {
    /**
     *注册用户的方法
     * @param sysUser
     * @return 注册成功返回1，失败返回0
     */
    int regist(SysUser sysUser);

    /**
     * 用户登录的方法
     * @param sysUser
     * @return 注册成功返回1，用户名不存在返回0，用户名存在但密码错误返回2；
     */
    int login(SysUser sysUser);
}
