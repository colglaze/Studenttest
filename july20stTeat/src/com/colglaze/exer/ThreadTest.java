package com.colglaze.exer;/*
@author colglaze
@create  2024-7-20
*/

public class ThreadTest extends Thread {
    public void run()
    {
        for(int i=0;i<100;i++)
        {
            if(i%2==0)
            {
                System.out.println(ThreadTest.currentThread().getName()+":"+i);

            }
        }

    }

}
