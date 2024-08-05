package com.colglaze.fileTest;

import org.junit.Test;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/*
文件的基本读入，写出操作
@author ColGlaze
@create 2024-08-04 -23:26
*/
public class FileTest {
   @Test
    public void test () {
       FileReader fr = null;
       try {
           File file = new File("hello.txt");
           fr = new FileReader(file);
           char[] cubf = new char[20];
           int len;
           while ((len = fr.read(cubf)) != -1) {
               for (int i = 0; i < len; i++) {
                   System.out.print(cubf[i]);
               }
           }
       } catch (IOException e) {
           throw new RuntimeException(e);
       } finally {
           if (fr != null)
           {
               try {
                   fr.close();
               } catch (IOException e) {
                   throw new RuntimeException(e);
               }
           }
       }


   }
    @Test
    public void test1()
    {
        FileReader fr = null;
        FileWriter fw = null;
        try {
            File file1 = new File("hello.txt");
            fr = new FileReader(file1);
            File file2 = new File("hello1.txt");
            fw = new FileWriter(file2);
            char[] cubf = new char[10];
            int len;
            long l = System.currentTimeMillis();
            while((len = fr.read(cubf)) != -1)
            {
                fw.write(cubf,0,len);
            }
            long l1 = System.currentTimeMillis();
            System.out.println(l1-l);
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            if(fr != null)
            {
                try {
                    fr.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if(fw != null)
            {
                try {
                    fw.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }


}
