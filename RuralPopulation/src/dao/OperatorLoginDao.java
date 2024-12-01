package dao;

import bean.OperatorLogin;

import java.util.ArrayList;
import java.util.List;

/*
@author ColGlaze
@create 2024-11-30 -15:42
*/
public interface OperatorLoginDao {
    /**
     * 添加操作员注册的账号密码
     * @param newOperatorLogin
     * @return
     */
    int addOperatorLogin(OperatorLogin newOperatorLogin);
    /**
     * 删除操作员注册的账号密码
     * @param id
     * @return
     */
    int deleteOperatorLogin(Long id);
    /**
     * 查询所有操作员注册的账号密码
     * @return
     */
    List<OperatorLogin> queryList();
    /**
     * 根据id修改操作员注册的账号密码
     * @param id
     * @return
     */
    int updateOperatorLogin(Long id);
    /**
     * 根据id查询操作员注册的账号密码
     * @param id
     * @return
     */
    ArrayList<OperatorLogin> queryOperatorLogin(Long id);
}
