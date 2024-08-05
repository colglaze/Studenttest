package com.colglaze.fileTest;

import java.io.*;

/*
对象序列化操作
@author ColGlaze
@create 2024-08-05 -10:04
*/
public class ObjectStreamTest {
    public static void main(String[] args) {
        Person p1 = new Person("lxq",19,new Phone("iphone15","chinese",13000));
        System.out.println(p1);
        FileOutputStream fos = null;
        FileInputStream fis = null;
        ObjectOutputStream oos = null;
        ObjectInputStream ois = null;
        Person p2 = null;
        try {
            File person = new File("person");
            fos = new FileOutputStream(person);
            oos = new ObjectOutputStream(fos);
            oos.writeObject(p1);
            fis = new FileInputStream(person);
            ois = new ObjectInputStream(fis);
            p2 = (Person) ois.readObject();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        } finally {
            if(oos != null)
            {
                try {
                    oos.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if(ois != null)
            {
                try {
                    ois.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if(fis != null)
            {
                try {
                    fis.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if(fos != null)
            {
                try {
                    fos.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

        }
        System.out.println(p2);
    }
}
