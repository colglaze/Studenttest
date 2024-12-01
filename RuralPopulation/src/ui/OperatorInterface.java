package ui;


import ui.component.MasterComponent;
import ui.component.MemberComponent;
import ui.component.OperatorComponent;

import javax.swing.*;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.table.TableColumnModel;
import javax.swing.table.TableModel;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeCellRenderer;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import java.util.Vector;

/*
@author ColGlaze
@create 2024-11-30 -16:55
*/
public class OperatorInterface {
    JFrame jf = new JFrame("操作员界面");
    final int WIDTH = 1000;
    final int HEIGHT = 600;
    public void init(){
        jf.setBounds((Toolkit.getDefaultToolkit().getScreenSize().width - WIDTH)/2,
                (Toolkit.getDefaultToolkit().getScreenSize().height - HEIGHT)/2, WIDTH, HEIGHT);
        jf.setResizable(false);
        JPanel jp = new JPanel();
        //设置菜单栏
        JMenuBar jmb = new JMenuBar();
        JMenu menu1 = new JMenu("设置");
        JMenuItem item1 = new JMenuItem("切换账号");
        JMenuItem item2 = new JMenuItem("退出程序");
        item1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new MainInterface().init();
                jf.setVisible(false);
            }
        });

        item2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        menu1.add(item1);
        menu1.add(item2);
        jmb.add(menu1);
        jf.setJMenuBar(jmb);


        //设置分割面板
        JSplitPane jSplitPane = new JSplitPane();
        jSplitPane.setContinuousLayout(true);
        jSplitPane.setDividerLocation(150);
        jSplitPane.setDividerSize(7);
        //组装左侧面板


        DefaultMutableTreeNode root = new DefaultMutableTreeNode("系统管理");
        DefaultMutableTreeNode node1 = new DefaultMutableTreeNode("户头信息");
        DefaultMutableTreeNode node2 = new DefaultMutableTreeNode("家庭成员信息");
        DefaultMutableTreeNode node3 = new DefaultMutableTreeNode("管理员信息");
        root.add(node1);
        root.add(node2);
        root.add(node3);
        JTree tree = new JTree(root);
//        Color color = new Color(203,220,217);
//        tree.setBackground(color);
        tree.setSelectionRow(1);
        tree.addTreeSelectionListener(new TreeSelectionListener() {
            @Override
            public void valueChanged(TreeSelectionEvent e) {
                Object lastPathComponent = e.getNewLeadSelectionPath().getLastPathComponent();
                if(node1.equals(lastPathComponent)){

                    jSplitPane.setRightComponent(new MasterComponent(jf));
                    jSplitPane.setDividerLocation(150);
                }else if(node2.equals(lastPathComponent)){

                    jSplitPane.setRightComponent(new MemberComponent(jf));
                    jSplitPane.setDividerLocation(150);
                }else if(node3.equals(lastPathComponent)){

                    jSplitPane.setRightComponent(new OperatorComponent(jf));
                    jSplitPane.setDividerLocation(150);
                }
            }
        });



        jSplitPane.setRightComponent(new MasterComponent(jf));
        jSplitPane.setLeftComponent(tree);


        jf.add(jSplitPane);
        jf.setVisible(true);

    }



    public static void main(String[] args) {
        new OperatorInterface().init();
    }
}
