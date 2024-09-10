package com.colglaze.schedule.dao.impl;

import com.colglaze.schedule.dao.BaseDao;
import com.colglaze.schedule.dao.SysScheduleDao;
import com.colglaze.schedule.pojo.SysSchedule;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-09-07 -19:05
*/
public class SysScheduleDaoImpl extends BaseDao implements SysScheduleDao {


    @Override
    public int addSchedule(SysSchedule schedule) {
        String sql = "INSERT INTO sys_schedule VALUES(NULL,?,?,?)";
        int len=0;
        try {
            len = update(sql, schedule.getUid(), schedule.getTitle(), schedule.getCompleted());
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return len;
    }

    @Override
    public List<SysSchedule> findAll() {
        String sql = "SELECT sid,uid,title,completed FROM sys_schedule";
        try {
            ArrayList<SysSchedule> query = query(SysSchedule.class, sql);
            return query;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
