package com.dao.impl;

import com.dao.ICarDAO;
import com.vo.Car;
import com.vo.Product;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class CarDAOImpl implements ICarDAO {
    private Connection conn = null;
    private PreparedStatement pstmt = null;
    public CarDAOImpl(Connection conn) {
        this.conn = conn;
    }
    public List<Car> getAllCar(String user) throws Exception {
        List<Car> list = new ArrayList<Car>();
        try {
            String sql = "select * from car where user=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,user);
            ResultSet rs = this.pstmt.executeQuery();
            while(rs.next()) {
                Car car = new Car();
                car.setName(rs.getString("name"));
                car.setPrice(rs.getDouble("price"));
                car.setUnit(rs.getString("unit"));
                car.setAmount(rs.getInt("amount"));
                car.setSubtotal(rs.getDouble("subtotal"));
                car.setImage(rs.getString("image"));
                list.add(car);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(this.pstmt != null) {
                try {
                    this.pstmt.close();
                } catch (Exception e) {
                    throw e;
                }
            }
        }
        return list;
    }
    public void addCar(Car car) throws Exception {
        try {
            String sql = "insert into car(user,name,price,unit,amount,subtotal,image)values(?,?,?,?,?,?,?)";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,car.getUser());
            this.pstmt.setString(2,car.getName());
            this.pstmt.setDouble(3,car.getPrice());
            this.pstmt.setString(4,car.getUnit());
            this.pstmt.setInt(5,car.getAmount());
            this.pstmt.setDouble(6,car.getSubtotal());
            this.pstmt.setString(7,car.getImage());
            int end = this.pstmt.executeUpdate();
            if(end==0) {
                System.out.println("Error");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(this.pstmt != null) {
                try {
                    this.pstmt.close();
                } catch (Exception e) {
                    throw e;
                }
            }
        }
    }
    public void delCar(String name,String user) throws Exception {
        System.out.println(name);
        try {
            String sql = "delete from car where name=? and user=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,name);
            this.pstmt.setString(2,user);
            int end = this.pstmt.executeUpdate();
            if(end==0) {
                System.out.println("Error");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(this.pstmt != null) {
                try {
                    this.pstmt.close();
                } catch (Exception e) {
                    throw e;
                }
            }
        }
    }
    public Car getCar(String name,String user) throws Exception {
        Car car = null;
        try {
            String sql = "select * from car where name=? and user=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,name);
            this.pstmt.setString(2,user);
            ResultSet rs = this.pstmt.executeQuery();
            if(rs.next()) {
                car = new Car();
                car.setUser(rs.getString("user"));
                car.setName(rs.getString("name"));
                car.setPrice(rs.getDouble("price"));
                car.setUnit(rs.getString("unit"));
                car.setAmount(rs.getInt("amount"));
                car.setSubtotal(rs.getDouble("subtotal"));
                car.setImage(rs.getString("image"));
                System.out.println(car);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return car;
    }
    public void addAmount(String name) throws Exception {
        try {
            String sql = "select * from car where name=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,name);
            ResultSet rs = this.pstmt.executeQuery();
            if(rs.next()) {
                int amount = rs.getInt("amount");
                double subtotal = rs.getDouble("subtotal");
                double price = rs.getDouble("price");
                sql = "update car set amount=?,subtotal=? where name=?";
                this.pstmt = conn.prepareStatement(sql);
                this.pstmt.setInt(1,amount+1);
                this.pstmt.setDouble(2,(amount+1)*price);
                this.pstmt.setString(3,rs.getString("name"));
                int end = this.pstmt.executeUpdate();
                if(end == 0) {
                    System.out.println("shibai");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(this.pstmt != null) {
                try {
                    this.pstmt.close();
                } catch (Exception e) {
                    throw e;
                }
            }
        }
    }
    public void cutAmount(String name) throws Exception {
        try {
            String sql = "select * from car where name=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,name);
            ResultSet rs = this.pstmt.executeQuery();
            if(rs.next()) {
                int amount = rs.getInt("amount");
                double subtotal = rs.getDouble("subtotal");
                double price = rs.getDouble("price");
                sql = "update car set amount=?,subtotal=? where name=?";
                this.pstmt = conn.prepareStatement(sql);
                this.pstmt.setInt(1,amount-1);
                this.pstmt.setDouble(2,(amount-1)*price);
                this.pstmt.setString(3,rs.getString("name"));
                int end = this.pstmt.executeUpdate();
                if(end == 0) {
                    System.out.println("shibai");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(this.pstmt != null) {
                try {
                    this.pstmt.close();
                } catch (Exception e) {
                    throw e;
                }
            }
        }
    }
    public double getTotal() throws Exception {
        double total = 0;
        try {
            String sql = "select subtotal from car";
            this.pstmt = conn.prepareStatement(sql);
            ResultSet rs = this.pstmt.executeQuery();
            while(rs.next()) {
                total = total + rs.getDouble("subtotal");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(this.pstmt != null) {
                try {
                    this.pstmt.close();
                } catch (Exception e) {
                    throw e;
                }
            }
        }
        return total;
    }
    public int getNum() throws Exception {
        int num = 0;
        try {
            String sql = "select amount from car";
            this.pstmt = conn.prepareStatement(sql);
            ResultSet rs = this.pstmt.executeQuery();
            while(rs.next()) {
                num = num + rs.getInt("amount");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(this.pstmt != null) {
                try {
                    this.pstmt.close();
                } catch (Exception e) {
                    throw e;
                }
            }
        }
        return num;
    }
}
