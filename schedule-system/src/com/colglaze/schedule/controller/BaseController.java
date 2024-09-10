package com.colglaze.schedule.controller;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.lang.reflect.Method;

/*
@author ColGlaze
@create 2024-09-09 -10:06
*/
public class BaseController extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String requestURL = String.valueOf(req.getRequestURL());
        String[] split = requestURL.split("/");
        String methodName = split[split.length - 1];
        Class clazz = this.getClass();
            try {
                    Method
                    method=clazz.getDeclaredMethod(methodName,HttpServletRequest.class,HttpServletResponse
                    .class);
                    // 设置方法可以访问
                    method.setAccessible(true);
                    // 通过反射执行代码
                    method.invoke(this,req,resp);
                 } catch (Exception e) {
                    e.printStackTrace();
                 }
     }

}
