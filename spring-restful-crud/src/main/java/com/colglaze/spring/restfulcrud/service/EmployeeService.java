package com.colglaze.spring.restfulcrud.service;

import com.colglaze.spring.restfulcrud.bean.Employee;
import org.springframework.stereotype.Service;

import java.util.List;

/*
@author ColGlaze
@create 2024-10-22 -23:17
*/
@Service
public interface EmployeeService {
    /**
     * 新增员工
     * @param employee
     */
    void addEmployee(Employee employee);

    /**
     * 删除员工
     * @param id
     */
    void deleteEmployee(Integer id);

    /**
     * 查询单个员工
     * @param id
     * @return
     */
    Employee findEmployeeById(Integer id);

    /**
     * 修改员工信息
     * @param employee
     */
    void updateEmployee(Employee employee);

    /**
     * 查询所有员工
     * @return
     */
    List<Employee> findAllEmployees();
}
