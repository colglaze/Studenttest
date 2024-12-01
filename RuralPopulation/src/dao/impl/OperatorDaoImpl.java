package dao.impl;

import bean.Operator;
import dao.BaseDAO;
import dao.OperatorDao;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-30 -11:11
*/
public class OperatorDaoImpl extends BaseDAO implements OperatorDao {
    @Override
    public int addOperator(Operator newOperator) {
        String sql = "insert into operater values(?,?,?,?,?,?,?)";
        try {
            int update = update(sql, null,newOperator.getName(), newOperator.getIdentId(),
                    newOperator.getGender(), newOperator.getAddress(), newOperator.getPhoneNum(),
                    newOperator.getWorkeAddress());
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public int deleteOperator(Long id) {
        String sql = "delete from operater where id = ?";
        try {
            int update = update(sql, id);
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public List<Operator> queryList() {
       String sql = "select id,name,ident_id identId,gender,address,phone_num phoneNum,work_address workeAddress" +
               " from operater";
       try {
           List<Operator> operators = query(Operator.class, sql);
           return operators;
       } catch (Exception e) {
           throw new RuntimeException(e);
       }
    }

    @Override
    public ArrayList<Operator> queryOperator(Long id) {
        String sql = "select id,name,ident_id identId,gender,address,phone_num phoneNum,work_address workeAddress" +
                " from operater where id = ?";
        try {
            ArrayList<Operator> operators = query(Operator.class, sql, id);
            return operators;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public int updateOperator(Operator newOperator) {
        String sql = "update operater set name = ?,ident_id = ?,gender = ?,address = ?,phone_num = ?,work_address = ?" +
                " where id = ?";
        if(newOperator.getId() == null){
            throw new RuntimeException("id为空");
        }
        ArrayList<Operator> operators = queryOperator(newOperator.getId());
        Operator operator = operators.get(0);

        if (newOperator.getName() != null){
            operator.setName(newOperator.getName());
        }
        if (newOperator.getIdentId() != null){
            operator.setIdentId(newOperator.getIdentId());
        }
        if (newOperator.getGender() != null){
            operator.setGender(newOperator.getGender());
        }
        if (newOperator.getAddress() != null){
            operator.setAddress(newOperator.getAddress());
        }
        if (newOperator.getPhoneNum() != null){
            operator.setPhoneNum(newOperator.getPhoneNum());
        }
        if (newOperator.getWorkeAddress() != null){
            operator.setWorkeAddress(newOperator.getWorkeAddress());
        }
        try {
            int update = update(sql, operator.getName(), operator.getIdentId(),
                    operator.getGender(), operator.getAddress(), operator.getPhoneNum(),
                    operator.getWorkeAddress(), operator.getId());
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
