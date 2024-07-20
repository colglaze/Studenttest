package com.colglaze.exer;

/*
@author colglaze
@create  ${year}-${month}-${day}
*/public class Main {
    public static void main(String[] args) {
    ThreadTest t1=new ThreadTest();
    t1.start();
    for(int i=0;i<100;i++)
    {
        if(i%2!=0)
        {
            System.out.println(ThreadTest.currentThread().getName()+":"+i);


        }
    }
    }
}