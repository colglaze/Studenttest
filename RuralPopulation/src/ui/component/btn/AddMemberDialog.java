package ui.component.btn;

import bean.Master;
import bean.Member;
import dao.impl.MasterDaoImpl;
import dao.impl.MemberDaoImpl;
import ui.component.MasterComponent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
@author ColGlaze
@create 2024-12-01 -12:40
*/
public class AddMemberDialog extends JDialog {
    final int WIDTH = 600;
    final int HEIGHT = 400;
    public AddMemberDialog(JFrame jf, String title,Boolean isModel) {
        super(jf, title, isModel);
        this.setBounds((Toolkit.getDefaultToolkit().getScreenSize().width - WIDTH) / 2, (Toolkit.getDefaultToolkit().getScreenSize().height - HEIGHT) / 2, WIDTH, HEIGHT);
        Box vBox = Box.createVerticalBox();
        //"编号", "姓名", "身份证号", "性别", "家庭住址", "联系电话", "所属户主", "工作单位"
        //组装编号
        Box horizontalBox = Box.createHorizontalBox();
        JLabel memberId = new JLabel("编        号：");
        JTextField memberIdText = new JTextField(15);
        horizontalBox.add(memberId);
        horizontalBox.add(Box.createHorizontalStrut(20));
        horizontalBox.add(memberIdText);
        //组装姓名
        Box horizontalBox1 = Box.createHorizontalBox();
        JLabel nameLabel = new JLabel("姓        名：");
        JTextField nameText = new JTextField(15);
        horizontalBox1.add(nameLabel);
        horizontalBox1.add(Box.createHorizontalStrut(20));
        horizontalBox1.add(nameText);
        //组装身份证
        Box horizontalBox2 = Box.createHorizontalBox();
        JLabel identIdLabel = new JLabel("身份证号：");
        JTextField identIdText = new JTextField(15);
        horizontalBox2.add(identIdLabel);
        horizontalBox2.add(Box.createHorizontalStrut(20));
        horizontalBox2.add(identIdText);
        //组装性别
        Box horizontalBox3 = Box.createHorizontalBox();
        JLabel genderLabel = new JLabel("性        别：");
        JTextField genderText = new JTextField(15);
        horizontalBox3.add(genderLabel);
        horizontalBox3.add(Box.createHorizontalStrut(20));
        horizontalBox3.add(genderText);
        //组装地址
        Box horizontalBox4 = Box.createHorizontalBox();
        JLabel addressLabel = new JLabel("家庭住址：");
        JTextField addressText = new JTextField(15);
        horizontalBox4.add(addressLabel);
        horizontalBox4.add(Box.createHorizontalStrut(20));
        horizontalBox4.add(addressText);
        //组装电话
        Box horizontalBox5 = Box.createHorizontalBox();
        JLabel phoneNumLabel = new JLabel("联系电话：");
        JTextField phoneNumText = new JTextField(15);
        horizontalBox5.add(phoneNumLabel);
        horizontalBox5.add(Box.createHorizontalStrut(20));
        horizontalBox5.add(phoneNumText);
        //组装所属户主
        Box horizontalBox6 = Box.createHorizontalBox();
        JLabel masterIdLabel = new JLabel("所属户主：");
        JTextField masterIdText = new JTextField(15);
        horizontalBox6.add(masterIdLabel);
        horizontalBox6.add(Box.createHorizontalStrut(20));
        horizontalBox6.add(masterIdText);
        //组装工作单位
        Box horizontalBox7 = Box.createHorizontalBox();
        JLabel workUnitLabel = new JLabel("工作单位：");
        JTextField workUnitText = new JTextField(15);
        horizontalBox7.add(workUnitLabel);
        horizontalBox7.add(Box.createHorizontalStrut(20));
        horizontalBox7.add(workUnitText);

        //组装按钮
//        vBox.add(Box.createVerticalStrut(20));
//        vBox.add(horizontalBox);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox1);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox2);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox3);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox4);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox5);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox6);
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox7);


        Box horizontalBox9 = Box.createHorizontalBox();
        JButton addBtn = new JButton("添加");
        addBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
               // Long id = Long.parseLong(memberIdText.getText());
                String name = nameText.getText();
                String identId = identIdText.getText();
                String gender = genderText.getText();
                String address = addressText.getText();
                String phoneNum = phoneNumText.getText();
                String workUnit = workUnitText.getText();
                Long masterId = Long.parseLong(masterIdText.getText());
                Member member = new Member(null, name, identId, gender, address, phoneNum, workUnit, masterId);
                new MemberDaoImpl().addMember(member);


                JOptionPane.showMessageDialog(jf, "添加成功");
                new MasterComponent(jf).requestData();
                dispose();


            }
        });

        horizontalBox9.add(addBtn);
        vBox.add(horizontalBox9);

        Box horizontalBox10 = Box.createHorizontalBox();
        horizontalBox10.add(Box.createHorizontalStrut(20));
        horizontalBox10.add(vBox);
        horizontalBox10.add(Box.createHorizontalStrut(20));
        this.add(horizontalBox10);
    }
}
