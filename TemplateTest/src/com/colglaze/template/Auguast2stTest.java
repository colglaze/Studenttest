package com.colglaze.template;

import java.util.Iterator;
import java.util.Map;
import java.util.Set;

//import static jdk.internal.org.jline.utils.Colors.s;


/*
@author ColGlaze
@create 2024-08-02 -23:45
*/
public class Auguast2stTest {
    public static void main(String[] args) {
        DAO<User> dao = new DAO<>();
        dao.save("aa",new User(1001,21,"ct"));
        dao.save("bb",new User(1002,27,"gwh"));
        dao.save("cc",new User(1003,18,"xj"));
        dao.save("dd",new User(1004,11,"ljw"));
        dao.save("ee",new User(1005,98,"lll"));
        System.out.println(dao.get("aa"));
        Set<Map.Entry<String, User>> entries = dao.getMap().entrySet();
        Iterator<Map.Entry<String, User>> iterator = entries.iterator();
        while(iterator.hasNext())
        {
            System.out.println(iterator.next().getValue());
        }
        System.out.println("**************************");
        dao.update("aa",new User(1009,15,"jhj"));
        for (String s : dao.getMap().keySet()) {
            System.out.println(dao.getMap().get(s));
        }
        System.out.println("**************************");
        dao.delete("bb");
        Set<String> strings = dao.getMap().keySet();
        Iterator<String> iterator1 = strings.iterator();
        while(iterator1.hasNext())
        {
            System.out.println(dao.getMap().get(iterator1.next()));
        }
        System.out.println("**************************");
        for (User user : dao.list()) {
            System.out.println(user);
        }

    }
}
