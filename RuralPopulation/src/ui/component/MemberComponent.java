package ui.component;

import bean.Member;
import dao.impl.MemberDaoImpl;
import ui.component.btn.AddMemberDialog;
import ui.component.btn.UpdateMemberDialog;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;
import java.awt.*;
import java.util.Vector;
import java.util.List;
/*
@author ColGlaze
@create 2024-11-30 -22:57
*/
public class MemberComponent extends Box {
    final int WIDTH = 850;
    final int HEIGHT = 600;
    private JTable table;
    private Vector<String> titels;
    private Vector<Vector> tableData;
    private TableModel tableModel;

    public MemberComponent(JFrame jf) {
        super(BoxLayout.Y_AXIS);

        JPanel btnPanel = new JPanel();
        btnPanel.setMaximumSize(new Dimension(WIDTH, 80));
        btnPanel.setLayout(new FlowLayout(FlowLayout.RIGHT));
        JButton addBtn = new JButton("添加");
        JButton removeBtn = new JButton("删除");
        JButton updateBtn = new JButton("修改");
        addBtn.addActionListener(e -> {
            new AddMemberDialog(jf, "添加家庭成员", true).setVisible(true);
            requestData();
        });
        updateBtn.addActionListener(e -> {
            if (table.getSelectedRow() == -1) {
                JOptionPane.showMessageDialog(jf, "请选择要修改的成员");
                return;
            }
            new UpdateMemberDialog(jf, "修改家庭成员", true, table.getValueAt(table.getSelectedRow(), 0).toString()).setVisible(true);
            requestData();
        });
        removeBtn.addActionListener(e -> {
            if (table.getSelectedRow() == -1) {
                JOptionPane.showMessageDialog(jf, "请选择要删除的成员");
                return;
            }
            if (JOptionPane.showConfirmDialog(jf, "确定要删除吗？", "提示", JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION) {
                new MemberDaoImpl().deleteMember(Long.parseLong(table.getValueAt(table.getSelectedRow(), 0).toString()));
                requestData();
            }
        });

        btnPanel.add(addBtn);
        btnPanel.add(removeBtn);
        btnPanel.add(updateBtn);
        this.add(btnPanel);
        String[] ts = {"编号", "姓名", "身份证号", "性别", "家庭住址", "联系电话", "所属户主", "工作单位"};
        titels = new Vector<>();
        for (String t : ts) {
            titels.add(t);
        }
        tableData = new Vector<>();
        tableModel = new DefaultTableModel(tableData, titels);

        table = new JTable(tableModel) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };
        table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        JScrollPane scrollPane = new JScrollPane(table);
        this.add(scrollPane);

        requestData();

    }
    public void requestData() {
        List<Member> members = new MemberDaoImpl().queryList();
        tableData.clear();
        for (Member member : members) {
            Vector<String> row = new Vector<>();
            row.add(member.getId().toString());
            row.add(member.getName());
            row.add(member.getIdentId());
            row.add(member.getGender());
            row.add(member.getAddress());
            row.add(member.getPhoneNum());
            row.add(member.getMasterId().toString());
            row.add(member.getWorkUnit());
            tableData.add(row);
        }
    }
}