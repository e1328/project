package com.dao.proxy;

import com.dao.IUserDAO;
import com.dao.impl.UserDAOImpl;
import com.dbc.DatabaseConnection;
import com.vo.User;

public class UserDAOProxy implements IUserDAO {
    private DatabaseConnection dbc = null;
    private IUserDAO dao = null;
    public UserDAOProxy() {
        try {
            this.dbc = new DatabaseConnection();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.dao = new UserDAOImpl(this.dbc.getConnection());
    }
    public boolean login(User user) throws Exception {
        boolean flag = false;
        try {
            flag = this.dao.login(user);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return flag;
    }
    public boolean register(User user) throws Exception {
        boolean flag = true;
        try {
            flag = this.dao.register(user);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return flag;
    }
}
