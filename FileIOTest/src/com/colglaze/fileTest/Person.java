package com.colglaze.fileTest;

import java.io.Serializable;

/*
@author ColGlaze
@create 2024-08-05 -10:00
*/
public class Person implements Serializable {
    public static final long serialVersionUID = 29458673L;
    private String name;
    private int age;
    private Phone phone;

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", phone=" + phone +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public Phone getPhone() {
        return phone;
    }

    public void setPhone(Phone phone) {
        this.phone = phone;
    }

    public Person() {
    }

    public Person(String name, int age, Phone phone) {
        this.name = name;
        this.age = age;
        this.phone = phone;
    }
}
