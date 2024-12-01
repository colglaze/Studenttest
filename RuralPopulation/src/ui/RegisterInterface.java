package ui;

import bean.OperatorLogin;
import dao.impl.OperatorLoginDaoImpl;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
@author ColGlaze
@create 2024-11-30 -16:10
*/
public class RegisterInterface {

    JFrame jf = new JFrame("注册");
    final int WIDTH = 500;
    final int HEIGHT = 300;
    //组装界面
    public void init(){
        //设置界面相关属性
        jf.setBounds((Toolkit.getDefaultToolkit().getScreenSize().width - WIDTH)/2,
                (Toolkit.getDefaultToolkit().getScreenSize().height - HEIGHT)/2, WIDTH, HEIGHT);
        jf.setResizable(false);
        JPanel jp = new JPanel();
        //jp.setBounds(0, 0, WIDTH, HEIGHT);
        Box box = Box.createVerticalBox();

        //组装用户名
        Box box1 = Box.createHorizontalBox();
        JLabel userLabel = new JLabel("用户名：");
        JTextField userText = new JTextField(15);
        box1.add(userLabel);
        box1.add(Box.createHorizontalStrut(20));
        box1.add(userText);

        //组装密码
        Box box2 = Box.createHorizontalBox();
        JLabel pwdLabel = new JLabel("密    码：");
        JPasswordField pwdText = new JPasswordField(15);
        box2.add(pwdLabel);
        box2.add(Box.createHorizontalStrut(20));
        box2.add(pwdText);
        //组装按钮
        Box box3 = Box.createHorizontalBox();
        JButton registerBtn = new JButton("注册");
        registerBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String userName = userText.getText();
                String pwd = new String(pwdText.getPassword());
                OperatorLoginDaoImpl operatorLoginDao = new OperatorLoginDaoImpl();
                operatorLoginDao.addOperatorLogin(new OperatorLogin(null, userName, pwd));
                JOptionPane.showMessageDialog(jf, "注册成功,请返回登录");
                new MainInterface().init();
                jf.setVisible(false);
            }
        });

        JButton backBtn = new JButton("返回登录界面");
        backBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new MainInterface().init();
                jf.setVisible(false);
            }
        });
        box3.add(registerBtn);
        box3.add(Box.createHorizontalStrut(80));
        box3.add(backBtn);




        box.add(Box.createVerticalStrut(50));
        box.add(box1);
        box.add(Box.createVerticalStrut(20));
        box.add(box2);
        box.add(Box.createVerticalStrut(20));
        box.add(box3);


        jp.add(box);
        jf.add(jp);
        jf.setVisible(true);
    }
    public static void main(String[] args) {
        new RegisterInterface().init();
    }
}
