package ui.component;

import bean.Master;
import dao.impl.MasterDaoImpl;
import ui.component.btn.AddMasterDialog;
import ui.component.btn.UpdateMasterDialog;


import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumnModel;
import javax.swing.table.TableModel;
import java.awt.*;
import java.util.List;
import java.util.Vector;

/*
@author ColGlaze
@create 2024-11-30 -19:36
*/
public class MasterComponent extends Box {
    final int WIDTH = 850;
    final int HEIGHT = 600;
    private JTable table;
    private Vector<String> titels;
    private Vector<Vector> tableData;
    private TableModel tableModel;
    public  MasterComponent(JFrame jf) {
        super(BoxLayout.Y_AXIS);

        JPanel btnPanel = new JPanel();
        btnPanel.setMaximumSize(new Dimension(WIDTH, 80));
        btnPanel.setLayout(new FlowLayout(FlowLayout.RIGHT));
        JButton addBtn = new JButton("添加");
        JButton removeBtn = new JButton("删除");
        JButton updateBtn = new JButton("修改");
        addBtn.addActionListener(e -> {
            new AddMasterDialog(jf, "添加户头", true).setVisible(true);
            requestData();

        });
        updateBtn.addActionListener(e -> {
            if (table.getSelectedRow() == -1) {
                JOptionPane.showMessageDialog(jf, "请选择要修改的行");
                return;
            }
            new UpdateMasterDialog(jf, "修改户头", true,table.getValueAt(table.getSelectedRow(),0).toString()).setVisible(true);
            requestData();
        });
        removeBtn.addActionListener(e -> {
            if (table.getSelectedRow() == -1) {
                JOptionPane.showMessageDialog(jf, "请选择要删除的行");
                return;
            }
            int res = JOptionPane.showConfirmDialog(jf, "确定删除吗？");
            if (res == 0) {
                new MasterDaoImpl().deleteMaster(Long.parseLong(table.getValueAt(table.getSelectedRow(), 0).toString()));
                requestData();
            }

        });
        btnPanel.add(addBtn);
        btnPanel.add(removeBtn);
        btnPanel.add(updateBtn);
        this.add(btnPanel);
        String[] ts = {"户头编号", "姓名", "身份证", "性别", "地址", "电话", "家庭面积", "人口数", "贫困种类"};
        titels = new Vector<>();
        for (String t : ts){
            titels.add(t);
        }
        tableData = new Vector<>();
        tableModel = new DefaultTableModel(tableData, titels);

        table = new JTable(tableModel){
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };
        table.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        JScrollPane scrollPane = new JScrollPane(table);
        this.add(scrollPane);

        //获取表格列
        requestData();

    }



    public void requestData() {
        List<Master> masters = new MasterDaoImpl().queryList();
        tableData.clear();
        for (Master master : masters) {
            Vector<String> row = new Vector<>();
            row.add(master.getId().toString());
            row.add(master.getName());
            row.add(master.getIdentId());
            row.add(master.getGender());
            row.add(master.getAddress());
            row.add(master.getPhoneNum());
            row.add(master.getHouseArea().toString());
            row.add(master.getPeopleSize().toString());
            row.add(master.getPoorName());
            tableData.add(row);

        }
       // tableModel.fireTableDataChanged();
    }
}
