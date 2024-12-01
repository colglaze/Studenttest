package test;

import bean.OperatorLogin;
import dao.OperatorLoginDao;
import dao.impl.OperatorLoginDaoImpl;
import org.junit.Test;

import java.util.ArrayList;

/*
@author ColGlaze
@create 2024-11-30 -15:52
*/
public class OperatorLoginTest {
    @Test
    public void testaddOperatorLogin() {
        OperatorLoginDao operatorLoginDao = new OperatorLoginDaoImpl();
        OperatorLogin operatorLogin = new OperatorLogin(null, "admin", "admin");
        int i = operatorLoginDao.addOperatorLogin(operatorLogin);
    }
    @Test
    public void testdeleteOperatorLogin() {
        OperatorLoginDao operatorLoginDao = new OperatorLoginDaoImpl();
        int i = operatorLoginDao.deleteOperatorLogin(2L);
    }
    @Test
    public void testqueryOperatorLogin() {
        OperatorLoginDao operatorLoginDao = new OperatorLoginDaoImpl();
        ArrayList<OperatorLogin> operatorLogins = operatorLoginDao.queryOperatorLogin(1L);
        for (OperatorLogin operatorLogin : operatorLogins) {
            System.out.println(operatorLogin);
        }
    }
}
