import org.junit.Test;

import java.util.*;

/*
@author ColGlaze
@create 2024-08-01 -20:41
*/
public class MapFucTest {
    @Test
    public void test()
    {
        Student s = new Student("刘俊威",19);
        HashMap map = new HashMap();
        map.put("aa",new Student("古文豪",17));
        map.put("bb",new Student("徐静",18));
        map.put("dd",s);
        map.put("cc",new Student("陈涛",20));

        Set entrySet = map.entrySet();
        Iterator iterator = entrySet.iterator();
        while(iterator.hasNext())
        {
            Object obj = iterator.next();
            Map.Entry entry = (Map.Entry) obj;
            System.out.println(entry.getKey()+"--->"+entry.getValue());
        }
        System.out.println("***************************");
        Set set = map.keySet();
        Collection values = map.values();
        Iterator iterator1 = set.iterator();
        Iterator iterator2 = values.iterator();
        while(iterator1.hasNext())
        {
            System.out.println(iterator1.next() + "--->" + iterator2.next());
        }
        System.out.println("***************************");
        System.out.println(map.get("bb"));
        System.out.println(map.containsKey("aa"));
        System.out.println(map.containsValue(s));
    }
}
