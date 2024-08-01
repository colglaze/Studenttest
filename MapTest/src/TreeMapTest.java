
import org.junit.Test;

import java.util.*;

/*
@author ColGlaze
@create 2024-08-01 -22:12
*/
public class TreeMapTest {
    @Test
    public void test()
    {
        TreeMap map =new TreeMap();
        Student s = new Student("刘俊威",19);
        map.put(new Student("古文豪",17),"aa");
        map.put(new Student("徐静",18),"bb");
        map.put(s,"dd");
        map.put(new Student("陈涛",20),"cc");
        Set entrySet = map.entrySet();
        Iterator iterator1  = entrySet.iterator();
        while(iterator1.hasNext())
        {
           Object obj = iterator1.next();
           Map.Entry entry = (Map.Entry) obj;
            System.out.println(entry.getKey() + "--->" + entry.getValue());
        }
        System.out.println("***************************");
        Iterator iterator2 = map.keySet().iterator();//Set类
        Iterator iterator3 = map.values().iterator();//collection类
        while(iterator2.hasNext())
        {
            System.out.println(iterator2.next() + "--->" + iterator3.next());
        }
    }
    @Test
    public void test2()
    {
        TreeMap map =new TreeMap(new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                if(o1 instanceof Student && o2 instanceof Student)
                {
                    Student s1 = (Student) o1;
                    Student s2 = (Student) o2;
                    return ((Student) o1).getName().compareTo(((Student) o2).getName());

                }
                throw new RuntimeException("类型不符");
            }
        });
        Student s = new Student("刘俊威",19);
        map.put(new Student("古文豪",17),"aa");
        map.put(new Student("徐静",18),"bb");
        map.put(s,"dd");
        map.put(new Student("陈涛",20),"cc");
        Iterator iterator1 = map.keySet().iterator();
        Iterator iterator2 = map.values().iterator();
        while(iterator1.hasNext())
        {
            System.out.println(iterator1.next() + "--->" + iterator2.next());
        }
        System.out.println("***************************");
        Set set = map.entrySet();
        Iterator iterator = set.iterator();
        while(iterator.hasNext())
        {
            Object obj =iterator.next();
            Map.Entry entry = (Map.Entry) obj;
            System.out.println(entry.getKey() + "--->" + entry.getValue());
        }
    }
}
