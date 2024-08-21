package com.colglaze.jsontest;

import com.colglaze.thing.Dog;
import com.colglaze.thing.Person;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.Test;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
@author ColGlaze
@create 2024-08-21 -10:28
*/
public class JsonTest {
    @Test
    public void test() throws JsonProcessingException {
        Person p1 = new Person("glass",18,new Dog("hhg"));
        ObjectMapper objectMapper = new ObjectMapper();
        String s = objectMapper.writeValueAsString(p1);
        System.out.println(s);

    }
    @Test
    public void test1() throws JsonProcessingException {
        String personstr = "{\"name\":\"glass\",\"age\":18,\"dog\":{\"name\":\"hhg\"}}";
        ObjectMapper objectMapper = new ObjectMapper();
        Person p2 = objectMapper.readValue(personstr,Person.class);
        System.out.println(p2);
    }
    @Test
    public void test2() throws JsonProcessingException {
        //mapTest
        Map data = new HashMap();
        data.put("a","valuea");
        data.put("b","valueb");
        ObjectMapper objectMapper = new ObjectMapper();
        String s = objectMapper.writeValueAsString(data);
        System.out.println(s);

    }
    @Test
    public void test3() throws JsonProcessingException {
        //list Test
        List data = new ArrayList();
        data.add("a");
        data.add("b");
        data.add("c");
        ObjectMapper objectMapper = new ObjectMapper();
        String s = objectMapper.writeValueAsString(data);
        System.out.println(s);
    }
}

















































