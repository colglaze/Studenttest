package ui;

import bean.OperatorLogin;
import dao.impl.OperatorLoginDaoImpl;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-30 -14:53
*/
public class MainInterface {

    JFrame jf = new JFrame("农村人口管理系统");
    final int WIDTH = 500, HEIGHT = 300;

    //组装视图
    public void init() {
        //设置界面相关属性

        //获取屏幕的宽高
        int width = Toolkit.getDefaultToolkit().getScreenSize().width;
        int height = Toolkit.getDefaultToolkit().getScreenSize().height;
        jf.setBounds((width - WIDTH)/2, (height - HEIGHT)/2, WIDTH, HEIGHT);
        jf.setResizable(false);
        //设置界面布局内容
        JPanel jp = new JPanel();

        //组装登录相关元素
        Box verticalBox = Box.createVerticalBox();
        //组装用户名
        Box horizontalBox1 = Box.createHorizontalBox();
        JLabel userLabel = new JLabel("用户名：");
        JTextField userText = new JTextField(15);

        horizontalBox1.add(userLabel);
        horizontalBox1.add(Box.createHorizontalStrut(20));
        horizontalBox1.add(userText);

        //组装密码
        Box horizontalBox2 = Box.createHorizontalBox();
        JLabel pwdLabel = new JLabel("密    码：");
        JPasswordField pwdText = new JPasswordField(15);
        horizontalBox2.add(pwdLabel);
        horizontalBox2.add(Box.createHorizontalStrut(20));
        horizontalBox2.add(pwdText);

        //组装按钮
        Box horizontalBox3 = Box.createHorizontalBox();
        JButton loginBtn = new JButton("登录");
        JButton registerBtn = new JButton("注册");
        loginBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //获取用户名和密码
                String userName = userText.getText();
                String pwd = new String(pwdText.getPassword());
                //访问登录模块
                OperatorLoginDaoImpl operatorLoginDao = new OperatorLoginDaoImpl();
                List<OperatorLogin> operatorLogins = operatorLoginDao.queryList();
                for (OperatorLogin operatorLogin : operatorLogins){
                    if (operatorLogin.getUsername().equals(userName) && operatorLogin.getPassword().equals(pwd)){
                        JOptionPane.showMessageDialog(jf, "登录成功");
                        //跳转至操作员界面
                        new OperatorInterface().init();
                        jf.setVisible(false);
                        return;
                    }

                }
                JOptionPane.showMessageDialog(jf, "用户名或密码错误");
            }
        });

        registerBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //跳转至注册界面
                new RegisterInterface().init();
                jf.setVisible(false);
            }
        });

        horizontalBox3.add(loginBtn);
        horizontalBox3.add(Box.createHorizontalStrut(100));
        horizontalBox3.add(registerBtn);

        verticalBox.add(Box.createVerticalStrut(50));
        verticalBox.add(horizontalBox1);
        verticalBox.add(Box.createVerticalStrut(20));
        verticalBox.add(horizontalBox2);
        verticalBox.add(Box.createVerticalStrut(40));
        verticalBox.add(horizontalBox3);

        jp.add(verticalBox);
        jf.add(jp);
        jf.setVisible(true);


    }



    // 主界面,程序入口
    public static void main(String[] args) {

        new MainInterface().init();
    }
}
