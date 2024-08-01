package com.colglaze.collect;

import com.sun.source.tree.Tree;
import org.junit.Test;

import java.util.*;

/*
@author ColGlaze
@create 2024-08-01 -0:35
*/
public class setTest {
    @Test
    public void test2()
    {
        HashSet set =new HashSet();
        set.add(new Person("李晓青",19));
        set.add(new Person("陈涛",19));
        set.add(123);
        set.add(345);
        set.add("asdf");
        for(Object obj:set)
        {
            System.out.println(obj);
        }
        System.out.println("***************************");
        Iterator iterator = set.iterator();
        while(iterator.hasNext())
        {
            System.out.println(iterator.next());
        }
        HashSet set1 = new HashSet();
        set1.add(new Person("李晓青",19));
        set1.add(new Person("陈涛",19));
        set1.add(1233);
        set1.add(3453);

        System.out.println("***************************");
        for(Object obj:set1)
        {
            System.out.println(obj);
        }
        set1.retainAll(set);
        System.out.println("***************************");
        for(Object obj:set1)
        {
            System.out.println(obj);
        }
        LinkedHashSet set2 = new LinkedHashSet();
        set2.add(new Person("李晓青",19));
        set2.add(new Person("陈涛",19));
        set2.add(123);
        set2.add(345);
        set2.add("asdf");
        System.out.println("***************************");
        for(Object obj:set2)
        {
            System.out.println(obj);
        }
        TreeSet set3 = new TreeSet();
        set3.add(new Person("Make",19));
        set3.add(new Person("niko",23));
        set3.add(new Person("donk",18));
        set3.add(new Person("monesy",22));
        Iterator iterator1 = set3.iterator();
        while(iterator1.hasNext())
        {
            System.out.println(iterator1.next());
        }
        System.out.println("***************************");
        Comparator com = new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                if(o1 instanceof Person && o2 instanceof Person)
                {
                    Person p1 = (Person)o1;
                    Person p2 = (Person)o2;
                    return -p1.getName().compareTo(p2.getName());
                }
                else
                {
                    throw new RuntimeException("类型不符");
                }
            }
        };
        TreeSet set4 = new TreeSet(com);
        set4.add(new Person("Make",19));
        set4.add(new Person("niko",23));
        set4.add(new Person("donk",18));
        set4.add(new Person("monesy",22));
        System.out.println("***************************");
        for(Object obj:set4)
        {
            System.out.println(obj);
        }
    }
}
