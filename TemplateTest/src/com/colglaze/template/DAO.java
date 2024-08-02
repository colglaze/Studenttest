package com.colglaze.template;

import java.util.*;

/*
@author ColGlaze
@create 2024-08-02 -23:19
*/
public class DAO <T> {
    private Map<String,T> map = new HashMap<>();

    public Map<String, T> getMap() {
        return map;
    }

    public void save(String id, T entity)
    {
        map.put(id,entity);
    }
    public T get(String id)
    {
        if(map.containsKey(id))
        {
            return map.get(id);
        }
        throw new RuntimeException("未找到该内容");
    }
    public void update(String id, T entity)
    {
        if(map.containsKey(id))
        {
            map.put(id,entity);
        }
        else throw new RuntimeException("未找到该内容");
    }
    public List<T> list()
    {
        List<T> tList = new ArrayList<>();
        Set<Map.Entry<String, T>> entries = map.entrySet();
        Iterator<Map.Entry<String, T>> iterator = entries.iterator();
        while(iterator.hasNext())
        {
            Map.Entry<String, T> next = iterator.next();
            T value = next.getValue();
            tList.add(value);
        }
        return tList;
    }
    public void delete(String id)
    {
        if(map.containsKey(id))
        {
            map.remove(id);
        }
        else throw new RuntimeException("未找到该内容");
    }
}
