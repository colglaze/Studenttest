package dao;

import bean.Operator;
import java.util.ArrayList;
import java.util.List;
/*
@author ColGlaze
@create 2024-11-30 -11:09
*/
public interface OperatorDao {
    /**
     * 添加操作员
     * @param newOperator
     * @return
     */
    int addOperator(Operator newOperator);
    /**
     * 删除操作员
     * @param id
     * @return
     */
    int deleteOperator(Long id);
    /**
     * 查询操作员列表
     *
     * @return
     */
    List<Operator> queryList();
    /**
     * 查询操作员
     * @param id
     * @return
     */
    ArrayList<Operator> queryOperator(Long id);
   /**
     * 更新操作员
     * @param newOperator
     * @return
     */
    int updateOperator(Operator newOperator);
}
