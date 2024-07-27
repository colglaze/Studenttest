package com.colglaze.Exer;

/*
@author ColGlaze
@creat  2024-07-27 -22:50
*/
public class Customer extends Thread {
    //消费
    private Clerk clerk;

    public Customer(Clerk clerk) {
        this.clerk = clerk;
    }

    @Override
    public void run() {
        while(true)
        {
                clerk.custom();
        }

    }
}
