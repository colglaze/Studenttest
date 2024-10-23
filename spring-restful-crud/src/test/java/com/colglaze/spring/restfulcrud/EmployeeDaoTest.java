package com.colglaze.spring.restfulcrud;

/*
@author ColGlaze
@create 2024-10-22 -22:57
*/

import com.colglaze.spring.restfulcrud.bean.Employee;
import com.colglaze.spring.restfulcrud.dao.EmployeeDao;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.math.BigDecimal;

@SpringBootTest
public class EmployeeDaoTest {
    @Autowired
    EmployeeDao employeeDao;




    @Test
    void testFindAllEmployee() throws Exception {
        System.out.println(employeeDao.findAllEmployees());
    }
    @Test
    void testFindEmployeeById() throws Exception {
        System.out.println(employeeDao.findEmployeeById(1));
    }
    @Test
    void testUpdateEmployee() throws Exception {
        employeeDao.updateEmployee(new Employee(5, "zhangsan", "男", "zhangsan@qq.com", "xian", 183, new BigDecimal(10200)));
    }

    @Test
    void testDeleteEmployee() throws Exception {
        employeeDao.deleteEmployee(6);
    }
    @Test
    void testAddEmployee() throws Exception {
        employeeDao.addEmployee(new Employee(null, "zhangsan", "男", "zhangsan@qq.com", "xian", 183, new BigDecimal(10200)));
    }
}
