package ui.component.btn;


import bean.Operator;
import bean.OperatorLogin;
import dao.impl.OperatorDaoImpl;
import ui.component.MasterComponent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
@author ColGlaze
@create 2024-12-01 -13:32
*/
public class AddOperatorDialog extends Dialog {
    final int WIDTH = 600;
    final int HEIGHT = 330;
    public AddOperatorDialog(JFrame jf, String title, Boolean isModel) {
        super(jf, title, isModel);
        this.setBounds((Toolkit.getDefaultToolkit().getScreenSize().width - WIDTH) / 2, (Toolkit.getDefaultToolkit().getScreenSize().height - HEIGHT) / 2, WIDTH, HEIGHT);
        Box vBox = Box.createVerticalBox();
        //组装用户名
        Box box1 = Box.createHorizontalBox();
        JLabel userLabel = new JLabel("用  户  名：");
        JTextField userText = new JTextField(15);
        box1.add(userLabel);
        box1.add(Box.createHorizontalStrut(20));
        box1.add(userText);
        //组装身份证号
        Box box2 = Box.createHorizontalBox();
        JLabel idLabel = new JLabel("身份证号：");
        JTextField idText = new JTextField(15);
        box2.add(idLabel);
        box2.add(Box.createHorizontalStrut(20));
        box2.add(idText);
        //组装性别
        Box box3 = Box.createHorizontalBox();
        JLabel sexLabel = new JLabel("性      别：");
        JTextField sexText = new JTextField(15);
        box3.add(sexLabel);
        box3.add(Box.createHorizontalStrut(20));
        box3.add(sexText);
        //组装家庭地址
        Box box4 = Box.createHorizontalBox();
        JLabel addressLabel = new JLabel("家庭地址：");
        JTextField addressText = new JTextField(15);
        box4.add(addressLabel);
        box4.add(Box.createHorizontalStrut(20));
        box4.add(addressText);
        //组装手机号
        Box box5 = Box.createHorizontalBox();
        JLabel phoneLabel = new JLabel("手  机  号：");
        JTextField phoneText = new JTextField(15);
        box5.add(phoneLabel);
        box5.add(Box.createHorizontalStrut(20));
        box5.add(phoneText);
        //组装工作地址
        Box box6 = Box.createHorizontalBox();
        JLabel workLabel = new JLabel("工作地址：");
        JTextField workText = new JTextField(15);
        box6.add(workLabel);
        box6.add(Box.createHorizontalStrut(20));
        box6.add(workText);

        //组装
        vBox.add(box1);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(box2);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(box3);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(box4);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(box5);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(box6);

        //组装按钮
        Box horizontalBox9 = Box.createHorizontalBox();
        JButton addBtn = new JButton("添加");
        addBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                //获取数据
                String userName = userText.getText();
                String id = idText.getText();
                String sex = sexText.getText();
                String address = addressText.getText();
                String phone = phoneText.getText();
                String work = workText.getText();
                Operator operator = new Operator(null, userName, id, sex, address, phone, work);
                OperatorDaoImpl operatorDao = new OperatorDaoImpl();
                operatorDao.addOperator(operator);

                JOptionPane.showMessageDialog(jf,"添加成功");
                new MasterComponent(jf).requestData();
                dispose();


            }
        });

        horizontalBox9.add(addBtn);
        vBox.add(horizontalBox9);

        Box horizontalBox10 =Box.createHorizontalBox();
        horizontalBox10.add(Box.createHorizontalStrut(20));
        horizontalBox10.add(vBox);
        horizontalBox10.add(Box.createHorizontalStrut(20));
        this.add(horizontalBox10);




    }
}
