package com.colglaze.schedule.test;

import com.colglaze.schedule.dao.SysScheduleDao;
import com.colglaze.schedule.dao.impl.SysScheduleDaoImpl;
import com.colglaze.schedule.pojo.SysSchedule;
import org.junit.BeforeClass;
import org.junit.Test;

import java.util.Iterator;
import java.util.List;

/*
@author ColGlaze
@create 2024-09-08 -10:38
*/
public class TestSysScheduleDao {
    public static SysScheduleDao scheduleDao;
    @BeforeClass
    public static void initScheduleDaoImpl()
    {
        scheduleDao = new SysScheduleDaoImpl();
    }
    @Test
    public void testAdd()
    {
        int i = scheduleDao.addSchedule(new SysSchedule(null, 3, "学习java", 1));
        System.out.println(i);

    }
    @Test
    public void testFindAll()
    {
        List<SysSchedule> all = scheduleDao.findAll();
        Iterator<SysSchedule> iterator = all.iterator();
        while (iterator.hasNext())
        {
            System.out.println(iterator.next());
        }
    }
}
