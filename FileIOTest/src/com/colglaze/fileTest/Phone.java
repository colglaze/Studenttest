package com.colglaze.fileTest;

import java.io.Serializable;

/*
@author ColGlaze
@create 2024-08-05 -10:01
*/
public class Phone implements Serializable {
    public static final long serialVersionUID = 234879L;
    private String name;
    private String module;
    private double price;

    @Override
    public String toString() {
        return "Phone{" +
                "name='" + name + '\'' +
                ", module='" + module + '\'' +
                ", price=" + price +
                '}';
    }

    public Phone(String name, String module, double price) {
        this.name = name;
        this.module = module;
        this.price = price;
    }

    public Phone() {
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getModule() {
        return module;
    }

    public void setModule(String module) {
        this.module = module;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}
