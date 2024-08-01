package com.colglaze.collect;

import java.util.Objects;

/*
@author ColGlaze
@create 2024-07-31 -23:06
*/
public class Person implements Comparable {
    private String name;
    private int age;
    public Person (String name,int age)
    {
        this.age=age;
        this.name=name;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public Person() {
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Person person = (Person) o;
        return age == person.age && Objects.equals(name, person.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }

    @Override
    public int compareTo(Object o) {
        if(o instanceof Person)
        {
            Person p = (Person) o;
            if(this.age > p.getAge())
            {
                return 1;
            }
            else if(this.age < p.getAge())
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        else
            throw new RuntimeException("类型不符");

    }
}
