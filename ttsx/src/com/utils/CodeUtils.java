package com.utils;

public class CodeUtils {
    public static String getCode() {
        String str = "qwertyuiopasdfghjklzxcvbnm0123456789";
        String code = "";
        for(int i=0;i<4;i++) {
            code = code + str.charAt((int)(Math.random()*36));
        }
        return code;
    }
}
