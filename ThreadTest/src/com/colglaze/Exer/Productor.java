package com.colglaze.Exer;

/*
@author ColGlaze
@creat  2024-07-27 -22:50
*/public class Productor extends Thread {
    //生产
    private  Clerk clerk;

    public Productor(Clerk clerk) {
        this.clerk = clerk;
    }

    public void run()
    {
        while(true)
        {
                clerk.product();
        }


    }

}
