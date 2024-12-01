package ui.component;

import bean.Operator;
import dao.impl.OperatorDaoImpl;
import ui.component.btn.AddOperatorDialog;
import ui.component.btn.UpdateOperatorDialog;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;

import java.awt.*;
import java.util.List;
import java.util.Vector;

/*
@author ColGlaze
@create 2024-11-30 -22:24
*/
public class OperatorComponent extends Box {
    final int WIDTH = 850;
    final int HEIGHT = 600;
    private JTable table;
    private Vector<String> titels;
    private Vector<Vector> tableData;
    private TableModel tableModel;

    public OperatorComponent(JFrame jf) {
        super(BoxLayout.Y_AXIS);

        JPanel btnPanel = new JPanel();
        btnPanel.setMaximumSize(new Dimension(WIDTH, 80));
        btnPanel.setLayout(new FlowLayout(FlowLayout.RIGHT));
        JButton addBtn = new JButton("添加");
        JButton removeBtn = new JButton("删除");
        JButton updateBtn = new JButton("修改");
        addBtn.addActionListener(e -> {
            new AddOperatorDialog(jf, "添加操作员", true).setVisible(true);
            requestData();
        });
        removeBtn.addActionListener(e -> {
            int row = table.getSelectedRow();
            if (row == -1) {
                JOptionPane.showMessageDialog(jf, "请选择要删除的行");
                return;
            }
            Long id = Long.parseLong(table.getValueAt(row, 0).toString());
            int result = new OperatorDaoImpl().deleteOperator(id);
            if (result > 0) {
                JOptionPane.showMessageDialog(jf, "删除成功");
                requestData();
            }
        });
        updateBtn.addActionListener(e -> {
            int row = table.getSelectedRow();
            if (row == -1) {
                JOptionPane.showMessageDialog(jf, "请选择要修改的行");
                return;
            }
            new UpdateOperatorDialog(jf, "修改操作员", true, table.getValueAt(row, 0).toString()).setVisible(true);
            requestData();

        });

        btnPanel.add(addBtn);
        btnPanel.add(removeBtn);
        btnPanel.add(updateBtn);
        this.add(btnPanel);
        String[] ts = {"编号", "姓名", "身份证", "性别", "地址", "电话", "工作单位"};
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
        List<Operator> operators = new OperatorDaoImpl().queryList();
        tableData.clear();
        for (Operator operator : operators) {
            Vector<String> row = new Vector<>();
            row.add(operator.getId().toString());
            row.add(operator.getName());
            row.add(operator.getIdentId());
            row.add(operator.getGender());
            row.add(operator.getAddress());
            row.add(operator.getPhoneNum());
            row.add(operator.getWorkeAddress());
            tableData.add(row);
        }

    }
}