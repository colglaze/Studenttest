package com.colglaze.reflect;

/*
@author ColGlaze
@create 2024-08-06 -22:58
*/
public class Person {
    private String name;
    private int age;
    private int id;

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

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Person(String name, int age, int id) {
        this.name = name;
        this.age = age;
        this.id = id;
    }

    public Person() {
    }
    public void show()
    {
        System.out.println("我爱你，你也爱我吗？");
    }
}
