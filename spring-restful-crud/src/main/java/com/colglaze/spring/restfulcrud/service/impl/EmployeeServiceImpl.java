package com.colglaze.spring.restfulcrud.service.impl;

import com.colglaze.spring.restfulcrud.bean.Employee;
import com.colglaze.spring.restfulcrud.dao.EmployeeDao;
import com.colglaze.spring.restfulcrud.service.EmployeeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/*
@author ColGlaze
@create 2024-10-22 -23:18
*/
@Service
public class EmployeeServiceImpl implements EmployeeService {
    @Autowired
    EmployeeDao employeeDao;
    @Override
    public void addEmployee(Employee employee) {

        employeeDao.addEmployee(employee);
    }

    @Override
    public void deleteEmployee(Integer id) {

        employeeDao.deleteEmployee(id);
    }

    @Override
    public Employee findEmployeeById(Integer id) {

        return employeeDao.findEmployeeById(id);
    }

    @Override
    public void updateEmployee(Employee employee) {

        if(employee.getName()==null){
            employee.setName(employeeDao.findEmployeeById(employee.getId()).getName());
        }

        if(employee.getEmail()==null){
            employee.setEmail(employeeDao.findEmployeeById(employee.getId()).getEmail());
        }

        if(employee.getAddress()==null){
            employee.setAddress(employeeDao.findEmployeeById(employee.getId()).getAddress());
        }

        if(employee.getGender()==null){
            employee.setGender(employeeDao.findEmployeeById(employee.getId()).getGender());
        }

        if(employee.getAge()==null){
            employee.setAge(employeeDao.findEmployeeById(employee.getId()).getAge());
        }

        if(employee.getSalary()==null){
            employee.setSalary(employeeDao.findEmployeeById(employee.getId()).getSalary());
        }


        employeeDao.updateEmployee(employee);
    }

    @Override
    public List<Employee> findAllEmployees() {
        return employeeDao.findAllEmployees();
    }
}
