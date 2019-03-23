package com.dao.proxy;

import com.dao.ICarDAO;
import com.dao.impl.CarDAOImpl;
import com.dbc.DatabaseConnection;
import com.vo.Car;
import com.vo.Product;

import java.util.ArrayList;
import java.util.List;

public class CarDAOProxy implements ICarDAO {
    private DatabaseConnection dbc = null;
    private ICarDAO dao = null;
    public CarDAOProxy() {
        try {
            this.dbc = new DatabaseConnection();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.dao = new CarDAOImpl(this.dbc.getConnection());
    }
    public List<Car> getAllCar(String user) throws Exception {
        List<Car> list = new ArrayList<Car>();
        try {
            list = this.dao.getAllCar(user);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return list;
    }
    public void addCar(Car car) throws Exception {
        try {
            this.dao.addCar(car);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
    }
    public void delCar(String name,String user) throws Exception {
        try {
            this.dao.delCar(name,user);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
    }
    public Car getCar(String name,String user) throws Exception {
        Car car = null;
        try {
            car = this.dao.getCar(name,user);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return car;
    }
    public void addAmount(String name) throws Exception {
        try {
            //this.dao.addAmount(name);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
    }
    public void cutAmount(String name) throws Exception {
        try {
            //this.dao.cutAmount(name);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
    }
    public double getTotal() throws Exception {
        double total = 0;
        try {
            //total = this.dao.getTotal();
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return total;
    }
    public int getNum() throws Exception {
        int num = 0;
        try {
            //num = this.dao.getNum();
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return num;
    }
}
