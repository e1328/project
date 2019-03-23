package com.dao;

import com.vo.Car;

import java.util.List;

public interface IOrderDAO {
    public List<Car> getAllCar(String user) throws Exception;
    public void addCar(Car car) throws Exception;
    public void delCar(String name, String user) throws Exception;
    public Car getCar(String name, String user) throws Exception;
    //public void addAmount(String name) throws Exception;
    //public void cutAmount(String name) throws Exception;
    //public double getTotal() throws Exception;
    //public int getNum() throws Exception;
}
