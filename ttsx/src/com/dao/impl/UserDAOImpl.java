package com.dao.impl;

import com.dao.IUserDAO;
import com.vo.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class UserDAOImpl implements IUserDAO {
    private Connection conn = null;
    private PreparedStatement pstmt = null;
    public UserDAOImpl(Connection conn) {
        this.conn = conn;
    }
    public boolean login(User user) throws Exception {
        try {
            String sql = "select * from user where name=? and pass=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,user.getName());
            this.pstmt.setString(2,user.getPass());
            ResultSet rs = this.pstmt.executeQuery();
            if(rs.next()) {
                return true;
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
        return false;
    }
    public boolean register(User user) throws Exception {
        boolean flag = true;
        System.out.println(user.getName()+" "+user.getPass());
        try {
            String sql = "select id from user where name=?";
            this.pstmt = conn.prepareStatement(sql);
            this.pstmt.setString(1,user.getName());
            ResultSet rs = pstmt.executeQuery();
            if(rs.next()) {
                flag = false;
            } else {
                sql = "insert into user(name,pass,email)values(?,?,?)";
                this.pstmt = conn.prepareStatement(sql);
                this.pstmt.setString(1,user.getName());
                this.pstmt.setString(2,user.getPass());
                this.pstmt.setString(3,user.getEmail());
                this.pstmt.executeUpdate();
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
        return flag;
    }
}
