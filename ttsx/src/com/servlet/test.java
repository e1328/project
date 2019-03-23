package com.servlet;

import com.factory.DAOFactory;
import com.vo.Product;

import java.util.List;

public class test {
    public static void main(String[] args) throws Exception{
        List<Product> list = DAOFactory.getIProductDAOInstance().searchAllProduct("苹");
        System.out.println(list);
    }
}
