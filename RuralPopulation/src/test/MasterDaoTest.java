package test;

import bean.Master;
import dao.MasterDao;
import dao.impl.MasterDaoImpl;
import org.junit.Test;


import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-29 -23:13
*/
public class MasterDaoTest {
    @Test
    public void testAddMaster() throws Exception {
       // Master master = new Master();
        MasterDaoImpl dao = new MasterDaoImpl();
        //int i = dao.insertMaster(master);
    }
    @Test
    public void testDeleteMaster() throws Exception {
        MasterDaoImpl dao = new MasterDaoImpl();
        int i = dao.deleteMaster(1L);
        System.out.println(i);
    }
    @Test
    public void testUpdateMaster() throws Exception {
        MasterDaoImpl dao = new MasterDaoImpl();
        Master master = new Master();
        master.setGender("男");
        master.setAddress("广东省番禺区");
        master.setId(4L);
        int i = dao.updateMaster(master);

    }

    @Test
    public void testQueryMaster() throws Exception {
        MasterDaoImpl dao = new MasterDaoImpl();
        ArrayList<Master> masters = dao.queryMaster(2L);
        System.out.println(masters);
    }
    @Test
    public void testQueryList() throws Exception {
        MasterDaoImpl dao = new MasterDaoImpl();
        List<Master> masters = dao.queryList();
        System.out.println(masters);
    }
}
