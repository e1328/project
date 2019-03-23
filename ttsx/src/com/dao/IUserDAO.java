package com.dao;

import com.vo.User;

public interface IUserDAO {
    public boolean login(User user) throws Exception;
    public boolean register(User user) throws Exception;
}
