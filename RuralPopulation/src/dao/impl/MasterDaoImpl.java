package dao.impl;

import bean.Master;
import dao.BaseDAO;
import dao.MasterDao;


import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-29 -22:59
*/
public class MasterDaoImpl extends BaseDAO implements MasterDao {
    @Override
    public int insertMaster(Master master) {
        String sql = "insert into " +
                "home_master(name,ident_id,gender,address,phone_num,house_area,people_size,poor_id) " +
                "values(?,?,?,?,?,?,?,?)";
        try {
            int update = update(sql, master.getName(), master.getIdentId(),
                    master.getGender(), master.getAddress(), master.getPhoneNum(),
                    master.getHouseArea(), master.getPeopleSize(), master.getPoorId());
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public int deleteMaster(Long id) {
        String sql = "delete from home_master where id = ?";
        try {
            int update = update(sql, id);
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public int updateMaster(Master newMaster) {
        String sql = "update home_master set name = ?,ident_id = ?,gender= ?,address= ?," +
                "phone_num = ?,house_area = ?,people_size = ?,poor_id = ? where id = ?";
        if (newMaster.getId() == null){
            throw new RuntimeException("id为空，无法修改");
        }
        ArrayList<Master> masters = queryMaster(newMaster.getId());
        Master master = masters.get(0);
        master.setId(newMaster.getId());
        if (newMaster.getName() != null){
            master.setName(newMaster.getName());
        }
        if (newMaster.getIdentId() != null){
            master.setIdentId(newMaster.getIdentId());
        }
        if (newMaster.getGender() != null){
            master.setGender(newMaster.getGender());
        }
        if (newMaster.getAddress() != null){
            master.setAddress(newMaster.getAddress());
        }
        if (newMaster.getPhoneNum() != null){
            master.setPhoneNum(newMaster.getPhoneNum());
        }
        if (newMaster.getHouseArea() != null){
            master.setHouseArea(newMaster.getHouseArea());
        }
        if (newMaster.getPeopleSize() != null){
            master.setPeopleSize(newMaster.getPeopleSize());
        }
        if (newMaster.getPoorId() != null){
            master.setPoorId(newMaster.getPoorId());
        }

        try {
            int update = update(sql, master.getName(), master.getIdentId(),master.getGender(),
                    master.getAddress(), master.getPhoneNum(), master.getHouseArea(),
                    master.getPeopleSize(), master.getPoorId(), master.getId());
            return update;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public ArrayList<Master> queryMaster(Long id) {
        String sql = "select hm.id,name,ident_id identId,gender,address,phone_num phoneNum,house_area houseArea,people_size peopleSize,poor_id poorId,type_name poorName" +
                " from home_master hm left join poor_type pt on hm.poor_id = pt.id where hm.id = ?";
        try {
            ArrayList<Master> masters = query(Master.class, sql, id);
            return masters;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public List<Master> queryList() {
        String sql = "select hm.id,name,ident_id identId,gender,address,phone_num phoneNum,house_area houseArea,people_size peopleSize,poor_id poorId,type_name poorName" +
                " from home_master hm left join poor_type pt on hm.poor_id = pt.id";
        try {
            List<Master> masters = query(Master.class, sql);
            return masters;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
