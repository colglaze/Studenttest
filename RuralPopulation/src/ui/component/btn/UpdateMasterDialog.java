package ui.component.btn;

import bean.Master;
import dao.impl.MasterDaoImpl;
import ui.component.MasterComponent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

/*
@author ColGlaze
@create 2024-12-01 -11:04
*/
public class UpdateMasterDialog extends Dialog {
    final int WIDTH = 600;
    final int HEIGHT = 450;
    //masterID
    private String id;
    public UpdateMasterDialog(JFrame jf, String title, Boolean isModel,String id){
        super(jf,title,isModel);
        this.id = id;
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
        JButton updateBtn = new JButton("修改");
        updateBtn.addActionListener(new ActionListener() {
            Long masterId = Long.parseLong(id);
            @Override
            public void actionPerformed(ActionEvent e) {


                //获取修改后的数据
                MasterDaoImpl masterDao = new MasterDaoImpl();
                masterDao.updateMaster(new Master(masterId,nameText.getText(),
                        identIdText.getText(),genderText.getText(),addressText.getText(),
                        phoneNumText.getText(),Long.parseLong(houseAreaText.getText()),
                        Long.parseLong(peopleSizeText.getText()),Long.parseLong(poorIdText.getText())));
                JOptionPane.showMessageDialog(jf,"修改成功");
                new MasterComponent(jf).requestData();
                dispose();

            }
        });


        horizontalBox9.add(updateBtn);
        vBox.add(horizontalBox9);

        Box horizontalBox10 =Box.createHorizontalBox();
        horizontalBox10.add(Box.createHorizontalStrut(20));
        horizontalBox10.add(vBox);
        horizontalBox10.add(Box.createHorizontalStrut(20));
        this.add(horizontalBox10);


        MasterDaoImpl masterDao = new MasterDaoImpl();
        ArrayList<Master> masters = masterDao.queryMaster(Long.parseLong(id));
        Master master = masters.get(0);
        nameText.setText(master.getName());
        identIdText.setText(master.getIdentId());
        genderText.setText(master.getGender());
        addressText.setText(master.getAddress());
        phoneNumText.setText(master.getPhoneNum());
        houseAreaText.setText(master.getHouseArea().toString());
        peopleSizeText.setText(master.getPeopleSize().toString());
        poorIdText.setText(master.getPoorId().toString());

    }

}
