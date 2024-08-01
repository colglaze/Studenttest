package com.colglaze.collect;

import org.junit.Test;

import java.util.*;

/*
@author ColGlaze
@create 2024-07-31 -23:05
*/
public class LlistTest {
    @Test
    public void test()
    {
        ArrayList arr=new ArrayList();
        arr.add(new Person("李晓青",19));
        arr.add(124);
        arr.add((456));
        arr.add("789");
        Iterator iterator=arr.iterator();//通过调用collection及其子类的iterator来完成声明
        while(iterator.hasNext())
        {
            System.out.println(iterator.next());
        }
        System.out.println("*****************");
        arr.add(0,new Person("陈涛",19));
        List arr2=  Arrays.asList(new int[]{1,2,3});//返回值是何种类型，就用何种类型接受
        arr.addAll(arr2);//参数要求：只要是collection的子类即可
        System.out.println(arr.get(1));
        System.out.println(arr.indexOf(124));
        System.out.println("*****************");
        arr.remove(new Integer(124));
        arr.set(2,123);
        List arr3= arr.subList(0,2);
        Iterator iterator1 = arr3.iterator();
        while(iterator1.hasNext())
        {
            System.out.println(iterator1.next());
        }
        System.out.println("*****************");
        for(Object obj:arr3)
        {
            System.out.println(obj);
        }
        System.out.println("*****************");
        for(Object obj:arr)
        {
            System.out.println(obj);
        }
        LinkedList list = new LinkedList();
        list.add(new Person("刘俊威",19));
        list.add("12ad");
        list.add(890);
        for(Object obj:list)
        {
            System.out.println(obj);
        }
        Iterator iterator2 = list.iterator();
        while(iterator2.hasNext())
        {
            System.out.println(iterator2.next());
        }
    }
}
