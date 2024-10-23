package com.colglaze.spring.restfulcrud.common;

import lombok.Data;

/*
@author ColGlaze
@create 2024-10-23 -11:06
*/
@Data
public class R {
    private String msg;
    private Integer code;
    private Object data;

    public static R ok(Object data){
        R r = new R();
        r.setCode(200);
        r.setMsg("success");
        r.setData(data);
        return r;
    }

    public static R ok(){
        return ok(null);
    }

    public static R error(String msg){
        R r = new R();
        r.setCode(500);
        r.setMsg(msg);
        return r;
    }

    public static R error(Integer code,String msg){
        R r = new R();
        r.setCode(code);
        r.setMsg(msg);
        return r;
    }


}
