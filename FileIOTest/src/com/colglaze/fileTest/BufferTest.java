package com.colglaze.fileTest;

import org.junit.Test;

import java.io.*;

/*
BufferRead，BufferWriter，BufferInputStream，BufferOutputStream的各项理解以及操作
@author ColGlaze
@create 2024-08-05 -9:18
*/
public class BufferTest {
    @Test
    public void test()
    {
        FileInputStream fis = null;
        FileOutputStream fos = null;
        BufferedInputStream bis = null;
        BufferedOutputStream bos = null;
        try {
            fis = null;
            fos = null;
            bis = null;
            bos = null;
            File src = new File("beauty.jpg");
            File dest = new File("beauty2.jpg");
            fis = new FileInputStream(src);
            fos = new FileOutputStream(dest);
            bis = new BufferedInputStream(fis);
            bos = new BufferedOutputStream(fos);
            byte[] buffer = new byte[10];
            int len;
            long l = System.currentTimeMillis();
            while((len = bis.read(buffer)) != -1)
            {
                bos.write(buffer,0,len);
            }
            long l1 = System.currentTimeMillis();
            System.out.println("所需时间：" + (l1-l));
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            if(bos != null)
            {
                try {
                    bos.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if(bis != null)
            {
                try {
                    bis.close();
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
    }
    @Test
    public void test1()
    {
        FileReader fr = null;
        FileWriter fw = null;
        BufferedReader br = null;
        BufferedWriter bw = null;
        try {
            File src = new File("hello.txt");
            File dest = new File("hello2.txt");
            fr = new FileReader(src);
            fw = new FileWriter(dest);
            br = new BufferedReader(fr);
            bw = new BufferedWriter(fw);
            char[] cbuf = new char[5];
            int len;
            long l = System.currentTimeMillis();
            while((len = br.read(cbuf)) != -1)
            {
                bw.write(cbuf,0,len);
            }
            long l1 = System.currentTimeMillis();
            System.out.println(l1 - l);
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            if(br != null)
            {
                try {
                    br.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            if(bw != null)
            {
                try {
                    bw.close();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
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
