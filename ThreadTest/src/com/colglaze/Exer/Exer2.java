package com.colglaze.Exer;

/*
@author ColGlaze
@creat  2024-07-27 -22:49
*/public class Exer2 {
    public static void main(String[] args) {
        Clerk clerk = new Clerk();
        Productor p = new Productor(clerk);
        Customer c = new Customer(clerk);
        p.setName("生产者");
        c.setName("消费者");
        p.start();
        c.start();
    }
}
