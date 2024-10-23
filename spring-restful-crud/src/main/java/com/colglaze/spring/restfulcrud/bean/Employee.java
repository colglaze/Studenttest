package com.colglaze.spring.restfulcrud.bean;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.math.BigDecimal;

/*
@author ColGlaze
@create 2024-10-22 -22:14
*/
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Employee {
    private Integer id;
    private String Name;
    private String gender;
    private String email;
    private String address;
    private Integer age;
    private BigDecimal salary;
}
