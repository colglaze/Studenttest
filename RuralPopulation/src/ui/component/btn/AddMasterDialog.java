package ui.component.btn;


import bean.Master;
import dao.impl.MasterDaoImpl;
import ui.component.MasterComponent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
@author ColGlaze
@create 2024-11-30 -23:38
*/
public class AddMasterDialog extends JDialog {
    final int WIDTH = 600;
    final int HEIGHT = 450;
    public AddMasterDialog(JFrame jf, String title,Boolean isModel){
        super(jf,title,isModel);
        this.setBounds((Toolkit.getDefaultToolkit().getScreenSize().width - WIDTH)/2,(Toolkit.getDefaultToolkit().getScreenSize().height - HEIGHT)/2, WIDTH, HEIGHT);
        Box vBox = Box.createVerticalBox();
        //组装姓名
        Box horizontalBox1 = Box.createHorizontalBox();
        JLabel nameLabel = new JLabel("姓        名：");
        JTextField nameText = new JTextField(15);
        horizontalBox1.add(nameLabel);
        horizontalBox1.add(Box.createHorizontalStrut(20));
        horizontalBox1.add(nameText);
        //组装身份证
        Box horizontalBox2 = Box.createHorizontalBox();
        JLabel identIdLabel = new JLabel("身  份  证：");
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
        JLabel addressLabel = new JLabel("地        址：");
        JTextField addressText = new JTextField(15);
        horizontalBox4.add(addressLabel);
        horizontalBox4.add(Box.createHorizontalStrut(20));
        horizontalBox4.add(addressText);
        //组装电话
        Box horizontalBox5 = Box.createHorizontalBox();
        JLabel phoneNumLabel = new JLabel("电        话：");
        JTextField phoneNumText = new JTextField(15);
        horizontalBox5.add(phoneNumLabel);
        horizontalBox5.add(Box.createHorizontalStrut(20));
        horizontalBox5.add(phoneNumText);
        //组装宅基地面积
        Box horizontalBox6 = Box.createHorizontalBox();
        JLabel houseAreaLabel = new JLabel("房屋面积：");
        JTextField houseAreaText = new JTextField(15);
        horizontalBox6.add(houseAreaLabel);
        horizontalBox6.add(Box.createHorizontalStrut(20));
        horizontalBox6.add(houseAreaText);
        //组装人口数
        Box horizontalBox7 = Box.createHorizontalBox();
        JLabel peopleSizeLabel = new JLabel("人  口  数：");
        JTextField peopleSizeText = new JTextField(15);
        horizontalBox7.add(peopleSizeLabel);
        horizontalBox7.add(Box.createHorizontalStrut(20));
        horizontalBox7.add(peopleSizeText);
        //组装贫困户ID
        Box horizontalBox8 = Box.createHorizontalBox();
        JLabel poorIdLabel = new JLabel("贫困户ID：");
        JTextField poorIdText = new JTextField(15);
        horizontalBox8.add(poorIdLabel);
        horizontalBox8.add(Box.createHorizontalStrut(20));
        horizontalBox8.add(poorIdText);
       //组装按钮
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
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox8);
        vBox.add(Box.createVerticalStrut(20));

        Box horizontalBox9 = Box.createHorizontalBox();
        JButton addBtn = new JButton("添加");
        addBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = nameText.getText();
                String identId = identIdText.getText();
                String gender = genderText.getText();
                String address = addressText.getText();
                String phoneNum = phoneNumText.getText();
                Long houseArea = Long.parseLong(houseAreaText.getText());
                Long peopleSize = Long.parseLong(peopleSizeText.getText());
                Long poorId = Long.parseLong(poorIdText.getText());
                Master master = new Master(null,name,identId,gender,address,phoneNum,houseArea,peopleSize,poorId);
                new MasterDaoImpl().insertMaster(master);
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
