package ui.component.btn;

import bean.Member;
import dao.impl.MemberDaoImpl;

import javax.swing.*;
import java.awt.*;
import java.util.List;

/*
@author ColGlaze
@create 2024-12-01 -12:56
*/
public class UpdateMemberDialog extends Dialog {
    final int WIDTH = 600;
    final int HEIGHT = 430;

    public UpdateMemberDialog(JFrame jf, String title, Boolean isModel, String id) {
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
        JLabel addressLabel = new JLabel("佳通住址：");
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
        JLabel poorIdLabel = new JLabel("所属户主：");
        JTextField poorIdText = new JTextField(15);
        horizontalBox6.add(poorIdLabel);
        horizontalBox6.add(Box.createHorizontalStrut(20));
        horizontalBox6.add(poorIdText);
        //组装单位
        Box horizontalBox7 = Box.createHorizontalBox();
        JLabel unitLabel = new JLabel("工作单位：");
        JTextField unitText = new JTextField(15);
        horizontalBox7.add(unitLabel);
        horizontalBox7.add(Box.createHorizontalStrut(20));
        horizontalBox7.add(unitText);

        //组装按钮
        vBox.add(Box.createVerticalStrut(20));
        vBox.add(horizontalBox);
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
        JButton updateBtn = new JButton("修改");
        updateBtn.addActionListener(e -> {
            //获取数据
            MemberDaoImpl memberDao = new MemberDaoImpl();
            Member member = new Member(Long.parseLong(memberIdText.getText()), nameText.getText(),
                    identIdText.getText(), genderText.getText(), addressText.getText(),
                    phoneNumText.getText(), unitText.getText(),
                    Long.parseLong(poorIdText.getText()));
            try {
                memberDao.updateMember(member);
                JOptionPane.showMessageDialog(jf, "修改成功");
                dispose();
            } catch (Exception ex) {
                throw new RuntimeException(ex);
            }
        });



        horizontalBox9.add(updateBtn);
        vBox.add(horizontalBox9);

        Box horizontalBox10 =Box.createHorizontalBox();
        horizontalBox10.add(Box.createHorizontalStrut(20));
        horizontalBox10.add(vBox);
        horizontalBox10.add(Box.createHorizontalStrut(20));
        this.add(horizontalBox10);
        MemberDaoImpl memberDao = new MemberDaoImpl();
        Long Id = Long.parseLong(id);
        List<Member> members = memberDao.queryMember(Id);
        Member member = members.get(0);
        memberIdText.setText(member.getId().toString());
        nameText.setText(member.getName());
        identIdText.setText(member.getIdentId());
        genderText.setText(member.getGender());
        addressText.setText(member.getAddress());
        phoneNumText.setText(member.getPhoneNum());
        poorIdText.setText(member.getMasterId().toString());
        unitText.setText(member.getWorkUnit());


    }
}
