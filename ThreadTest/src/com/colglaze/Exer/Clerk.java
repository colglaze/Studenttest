package com.colglaze.Exer;

/*
@author ColGlaze
@creat  2024-07-27 -22:50
*/public class Clerk {
    //中转
    private int product = 0;
    public synchronized void product()  {
        if(product < 20)
        {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            product++;
            System.out.println(Thread.currentThread().getName()+":生产第"+product+"个产品");
            notify();
        }
        else
        {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
    public synchronized void custom()
    {
        if(product > 0)
        {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println(Thread.currentThread().getName()+":消费第"+product+"个产品");
            product--;
            notify();
        }
        else
        {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
