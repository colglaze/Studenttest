package com.colglaze.spring.restfulcrud.controller;

import com.colglaze.spring.restfulcrud.bean.Employee;
import com.colglaze.spring.restfulcrud.common.R;
import com.colglaze.spring.restfulcrud.service.EmployeeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/*
@author ColGlaze
@create 2024-10-22 -23:28
*/
@CrossOrigin
@RestController
@RequestMapping("/api/v1")
public class EmployeeController {

    @Autowired
    EmployeeService employeeService;

    /**
     * URI	            请求方式	   请求体	        作用	        返回数据
     * /employee/{id}	GET	        无	            查询某个员工	    Employee JSON
     * /employee	    POST	    employee json	新增某个员工	    成功或失败状态
     * /employee	    PUT	        employee json	修改某个员工	    成功或失败状态
     * /employee/{id}	DELETE	    无	            删除某个员工	    成功或失败状态
     * /employees	    GET	        无/查询条件	    查询所有员工  	List<Employee> JSON
     * /employees/page	GET	        无/分页条件	    查询所有员工	    分页数据 JSON
     * @param
     * @return
     */

    @GetMapping("/employees")
    public R getAllEmployees(){
        List<Employee> allEmployees = employeeService.findAllEmployees();
        R ok = R.ok(allEmployees);
        return ok;
    }


    @DeleteMapping("/employee/{id}")
    public R deleteEmployeeById(@PathVariable("id") Integer id){
        employeeService.deleteEmployee(id);
        return R.ok();
    }


    @GetMapping("/employee/{id}")
    public R findEmployeeById(@PathVariable("id") Integer id) {
        Employee employeeById = employeeService.findEmployeeById(id);
        return R.ok(employeeById);
    }

    @PostMapping("/employee")
    public R addEmployee(@RequestBody Employee employee) {

        employeeService.addEmployee(employee);

        return R.ok();
    }

    @PutMapping("/employee")
    public R updateEmployee(@RequestBody Employee employee) {
        employeeService.updateEmployee(employee);
        return R.ok();
    }

}
