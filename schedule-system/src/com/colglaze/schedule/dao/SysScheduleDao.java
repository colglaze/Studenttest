package com.colglaze.schedule.dao;

import com.colglaze.schedule.pojo.SysSchedule;

import java.util.List;

/*
@author ColGlaze
@create 2024-09-06 -21:20
*/
public interface SysScheduleDao {
    /*
    * 用于增加一条数据
    * 数据以schedule的形式传入
    * 数据返回0表示失败，返回大于0的数表示成功
    * */
    int addSchedule(SysSchedule schedule);
    /*
    * 用于查询所有数据
    * 返回一个list集合
    *
    * */
    List<SysSchedule> findAll();

}
