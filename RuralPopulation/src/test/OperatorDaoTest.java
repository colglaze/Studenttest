package test;

import bean.Operator;
import dao.OperatorDao;
import dao.impl.OperatorDaoImpl;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-30 -11:25
*/
public class OperatorDaoTest {
    @Test
    public void testaddOperator() {
        OperatorDao operatorDao = new OperatorDaoImpl();
        Operator operator = new Operator(null, "张三", "123456789", "男", "上海", "123456789", "上海");
        int i = operatorDao.addOperator(operator);
    }
    @Test
    public void testdeleteOperator() {
        OperatorDao operatorDao = new OperatorDaoImpl();
        int i = operatorDao.deleteOperator(2L);
    }
    @Test
    public void testqueryList() {
        OperatorDao operatorDao = new OperatorDaoImpl();
        List<Operator> list = operatorDao.queryList();
        for (Operator operator : list) {
            System.out.println(operator);
        }
    }
    @Test
    public void testqueryOperator() {
        OperatorDao operatorDao = new OperatorDaoImpl();
        ArrayList<Operator> operators = operatorDao.queryOperator(1L);
        for (Operator operator : operators) {
            System.out.println(operator);
        }
    }
    @Test
    public void testupdateOperator() {
        OperatorDao operatorDao = new OperatorDaoImpl();
        Operator operator = new Operator(2L, null, null, "女", null, null, "北京");
        int i = operatorDao.updateOperator(operator);
    }
}
