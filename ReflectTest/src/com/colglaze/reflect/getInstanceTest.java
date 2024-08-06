package com.colglaze.reflect;

import org.junit.Test;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/*
@author ColGlaze
@create 2024-08-06 -22:57
*/
public class getInstanceTest {
    @Test
    public void test() throws ClassNotFoundException {
        Class clazz1 = Person.class;
        System.out.println(clazz1);

        Person p = new Person();
        Class clazz2 = p.getClass();
        System.out.println(clazz2);

        Class clazz3 = Class.forName("com.colglaze.reflect.Person");
        System.out.println(clazz3);

        System.out.println(clazz1 == clazz2);
        System.out.println(clazz1 == clazz3);


    }
    @Test
    public void test1() throws ClassNotFoundException, InstantiationException, IllegalAccessException,
            NoSuchFieldException, NoSuchMethodException, InvocationTargetException {
        Class clazz = Class.forName("com.colglaze.reflect.Person");
        Constructor[] constructors = clazz.getConstructors();
        for(Constructor c : constructors)
        {
            System.out.println(c);
        }
        Person p = (Person) clazz.newInstance();
        Field name = clazz.getDeclaredField("name");
        name.setAccessible(true);
        name.set(p,"tom");
        System.out.println(p.getName());
        Method show = clazz.getDeclaredMethod("show");
        show.setAccessible(true);
        show.invoke(p);

    }


}
