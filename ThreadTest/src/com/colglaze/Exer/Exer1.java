package com.colglaze.Exer;

public class Exer1 {
    public static void main(String[] args) {
        Account account = new Account();
        Thread c1 = new Thread(account);
        Thread c2 = new Thread(account);
        c1.setName("顾客一");
        c2.setName("顾客二");
        c1.start();
        c2.start();

    }
}
