package dao;

import bean.Master;


import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-29 -22:55
*/
public interface MasterDao {
    /**
     * 插入户主
     * @param master
     * @return
     */
    int insertMaster(Master master);

    /**
     * 删除户主
     * @param id
     * @return
     */
    int deleteMaster(Long id);

    /**
     * 更新户主信息
     * @param master
     * @return
     */
    int updateMaster(Master master);

    /**
     * 查询户主信息
     *
     * @param id
     * @return
     */
    ArrayList<Master> queryMaster(Long id);

    /**
     * 查询所有户主信息
     * @return
     */
    List<Master> queryList();
}
