package com.colglaze.Exer;

/*
@author ColGlaze
@creat  2024-07-27 -22:29
*/
public class Account implements Runnable
{
    private int balance;
    public void run()
    {
        synchronized(this)
        {
            for (int i = 0; i < 3; i++) {

                balance += 1000;
                System.out.println(Thread.currentThread().getName()+":"+balance);
            }
        }

    }
}
