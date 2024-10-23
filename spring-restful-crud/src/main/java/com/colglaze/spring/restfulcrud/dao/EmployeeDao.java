package com.colglaze.spring.restfulcrud.dao;

import com.colglaze.spring.restfulcrud.bean.Employee;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.List;

/*
@author ColGlaze
@create 2024-10-22 -22:20
*/
@Repository
public class EmployeeDao {
    @Autowired
    JdbcTemplate jdbcTemplate;


    public void addEmployee(Employee employee) {
        String sql = "insert into employee values(null,?,?,?,?,?,?)";
        jdbcTemplate.update(sql,
                employee.getName(),
                employee.getAge(),
                employee.getEmail(),
                employee.getGender(),
                employee.getAddress(),
                employee.getSalary());
    }

    public void deleteEmployee(Integer id) {

        String sql = "delete from employee where id=?";
        jdbcTemplate.update(sql,id);

    }

    public void updateEmployee(Employee employee){

        String sql = "update employee set name=?,age=?,email=?,gender=?,address=?,salary=? where id=?";
        jdbcTemplate.update(sql,
                employee.getName(),
                employee.getAge(),
                employee.getEmail(),
                employee.getGender(),
                employee.getAddress(),
                employee.getSalary(),
                employee.getId());

    }


    public Employee findEmployeeById(Integer id) {

        String sql = "select * from employee where id=?";
        return jdbcTemplate.queryForObject(sql,new BeanPropertyRowMapper<Employee>(Employee.class),id);

    }

    public List<Employee> findAllEmployees() {

        String sql = "select * from employee";
        List<Employee> query = jdbcTemplate.query(sql, new BeanPropertyRowMapper<Employee>(Employee.class));
        return query;
    }
}
