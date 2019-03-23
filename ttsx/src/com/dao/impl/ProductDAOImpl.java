package com.dao.impl;

import com.dao.IProductDAO;
import com.vo.Product;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class ProductDAOImpl implements IProductDAO {
    private Connection conn = null;
    private PreparedStatement pstmt = null;
    public ProductDAOImpl(Connection conn) {
        this.conn = conn;
    }
    public List<Product> getAllProduct(String type) throws Exception {
        List<Product> list = new ArrayList<Product>();
        try {
            String sql = "select * from product where type=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,type);
            ResultSet rs = this.pstmt.executeQuery();
            while(rs.next()) {
                Product product = new Product();
                product.setId(rs.getInt("id"));
                product.setType(rs.getString("type"));
                product.setName(rs.getString("name"));
                product.setPrice(rs.getDouble("price"));
                product.setUnit(rs.getString("unit"));
                product.setOther(rs.getString("other"));
                product.setImage(rs.getString("image"));
                product.setInfo01(rs.getString("info01"));
                product.setInfo02(rs.getString("info02"));
                product.setOther(rs.getString("other"));
                product.setComment(rs.getString("comment"));
                list.add(product);
            }
        } catch (Exception e) {
            throw e;
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
    public Product getProduct(String name) throws Exception {
        Product product = null;
        try {
            String sql = "select * from product where name=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,name);
            ResultSet rs = this.pstmt.executeQuery();
            if(rs.next()) {
                product = new Product();
                product.setId(rs.getInt("id"));
                product.setType(rs.getString("type"));
                product.setName(rs.getString("name"));
                product.setPrice(rs.getDouble("price"));
                product.setUnit(rs.getString("unit"));
                product.setOther(rs.getString("other"));
                product.setImage(rs.getString("image"));
                product.setInfo01(rs.getString("info01"));
                product.setInfo02(rs.getString("info02"));
                product.setComment(rs.getString("comment"));
                System.out.println(product);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return product;
    }
    public List<Product> searchAllProduct(String key) throws Exception {
        List<Product> list = new ArrayList<Product>();
        try {
            String sql = "select * from product where name like ?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,"%"+key+"%");
            ResultSet rs = this.pstmt.executeQuery();
            while(rs.next()) {
                Product product = new Product();
                product.setId(rs.getInt("id"));
                product.setType(rs.getString("type"));
                product.setName(rs.getString("name"));
                product.setPrice(rs.getDouble("price"));
                product.setUnit(rs.getString("unit"));
                product.setOther(rs.getString("other"));
                product.setImage(rs.getString("image"));
                product.setInfo01(rs.getString("info01"));
                product.setInfo02(rs.getString("info02"));
                product.setOther(rs.getString("other"));
                product.setComment(rs.getString("comment"));
                list.add(product);
            }
        } catch (Exception e) {
            throw e;
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
    public void deleteProduct(String name) throws Exception {
        try {
            String sql = "delete from product where name=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,name);
            this.pstmt.executeUpdate();
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
    public void updateProduct(int id,String name,int unit,double price,String info) throws Exception {
        try {
            String sql = "update product set name=?,unit=?,price=?,info=? where id=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,name);
            this.pstmt.setInt(2,unit);
            this.pstmt.setDouble(3,price);
            this.pstmt.setString(4,info);
            this.pstmt.setInt(5,id);
            this.pstmt.executeUpdate();
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
}