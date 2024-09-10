package com.colglaze.schedule.util;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;

/*
@author ColGlaze
@create 2024-09-07 -11:55
*/
public abstract class JDBCUtils {
    private static ThreadLocal<Connection> threadLocal =new ThreadLocal<>();
    private static DataSource dataSource;
    //初始化连接池
    static {
        //可以帮助我们读取.properties配置文件
        Properties properties = new Properties();
        InputStream resourceAsStream = JDBCUtils.class.getClassLoader().getResourceAsStream("jdbc.properties");
        try {
            properties.load(resourceAsStream);
            dataSource = DruidDataSourceFactory.createDataSource(properties);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    //向外提供连接池的方法
    public static DataSource getDataSource()
    {
        return dataSource;
    }
    //向外提供连接的方法 (单例模式)
    public static Connection getConnection()
    {
        Connection connection = threadLocal.get();
        if(null == connection)
        {
            try {
                connection = dataSource.getConnection();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
            threadLocal.set(connection);
        }
        return connection;
    }
    //定义一个归还连接的方法（解除和ThreadLocal之间的联系）
    public static void releaseConnection()
    {
        Connection connection = threadLocal.get();
        if (null == connection)
        {
            threadLocal.remove();
            try {
                connection.setAutoCommit(true);
                connection.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }




}
