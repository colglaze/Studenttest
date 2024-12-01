package dao.impl;

import bean.OperatorLogin;
import dao.BaseDAO;
import dao.OperatorLoginDao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-30 -15:45
*/
public class OperatorLoginDaoImpl extends BaseDAO implements OperatorLoginDao {
    @Override
    public int addOperatorLogin(OperatorLogin newOperatorLogin) {
        String sql = "insert into operator_login(username,password) values(?,?)";
        try {
            return update(sql,newOperatorLogin.getUsername(),newOperatorLogin.getPassword());
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public int deleteOperatorLogin(Long id) {
        String sql = "delete from operator_login where id = ?";
        try {
            return update(sql,id);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public List<OperatorLogin> queryList() {
        String sql = "select id,username,password" +
                " from operator_login";
        try {
            List<OperatorLogin> operatorLogins = query(OperatorLogin.class, sql);
            return operatorLogins;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public int updateOperatorLogin(Long id) {
       String sql = "update operator_login set username = ?,password = ? where id = ?";
        ArrayList<OperatorLogin> operatorLogins = queryOperatorLogin(id);
        OperatorLogin operatorLogin = operatorLogins.get(0);
        if (operatorLogin.getUsername() != null){
            operatorLogin.setUsername(operatorLogin.getUsername());
        }
        if (operatorLogin.getPassword() != null){
            operatorLogin.setPassword(operatorLogin.getPassword());
        }
        try {
            return update(sql,operatorLogin.getUsername(),operatorLogin.getPassword(),id);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public ArrayList<OperatorLogin> queryOperatorLogin(Long id) {

        String sql = "select id,username,password from operator_login where id = ?";
        try {
            ArrayList<OperatorLogin> operatorLogins = query(OperatorLogin.class, sql, id);
            return operatorLogins;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
