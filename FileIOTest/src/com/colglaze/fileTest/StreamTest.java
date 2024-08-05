package com.colglaze.fileTest;

import org.junit.Test;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/*
InputStream，OutputStream的练习
@author ColGlaze
@create 2024-08-05 -8:46
*/
public class StreamTest {
    @Test
    public void test1()
    {
        FileInputStream fis = null;
        FileOutputStream fos = null;
        try {
            File srcfile = new File("beauty.jpg");
            File copyfile = new File("beauty1.jpg");
            fis = new FileInputStream(srcfile);
            fos = new FileOutputStream(copyfile);
            byte[] buffer = new byte[10];
            int len;
            long l = System.currentTimeMillis();
            while((len = fis.read(buffer)) != -1)
            {
                fos.write(buffer,0,len);
            }
            long l1 = System.currentTimeMillis();
            System.out.println("所花时间为：" + (l1-l));
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
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

}
