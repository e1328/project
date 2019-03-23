package com.factory;

import com.dao.ICarDAO;
import com.dao.IProductDAO;
import com.dao.IUserDAO;
import com.dao.proxy.CarDAOProxy;
import com.dao.proxy.ProductDAOProxy;
import com.dao.proxy.UserDAOProxy;

public class DAOFactory {
    public static IUserDAO getIUserDAOInstance() {
        return new UserDAOProxy();
    }
    public static IProductDAO getIProductDAOInstance() {
        return new ProductDAOProxy();
    }
    public static ICarDAO getCarIDAOInstance() {
        return new CarDAOProxy();
    }
}
