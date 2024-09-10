package com.colglaze.schedule.controller;

import com.colglaze.schedule.pojo.SysUser;
import com.colglaze.schedule.service.SysUserService;
import com.colglaze.schedule.service.impl.SysUserServiceImpl;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

/*
@author ColGlaze
@create 2024-09-08 -16:12
*/
@WebServlet("/user/*")
public class SysUserController extends BaseController {
    private SysUserService sysUserService = new SysUserServiceImpl();

    /**
     * 用于完成用户的注册业务
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    protected void regist(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        String userPwd = req.getParameter("userPwd");
        SysUser sysUser = new SysUser(null, username, userPwd);

        int flag = sysUserService.regist(sysUser);

        if (flag > 0)
        {
            resp.sendRedirect("/registSuccess.html");
        }
        else
        {
            resp.sendRedirect("/registFail.html");
        }

    }

    /**
     * 用户登录请求，完成登录的业务
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    protected void login(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        String userPwd = req.getParameter("userPwd");
        SysUser sysUser = new SysUser(null, username, userPwd);
        int flag = sysUserService.login(sysUser);
        if (flag == 1)
        {
            resp.sendRedirect("/showschedule.html");
        }
        else if (flag == 2)
        {
            resp.sendRedirect("/loginUserpwdError.html");
        }
        else if (flag == 0)
        {
            resp.sendRedirect("/loginUsernameError.html");
        }
    }
}










































