package com.dao.proxy;

import com.dao.IProductDAO;
import com.dao.impl.ProductDAOImpl;
import com.dbc.DatabaseConnection;
import com.vo.Product;

import java.util.List;

public class ProductDAOProxy implements IProductDAO {
    private DatabaseConnection dbc = null;
    private IProductDAO dao = null;
    public ProductDAOProxy() {
        try {
            this.dbc = new DatabaseConnection();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.dao = new ProductDAOImpl(this.dbc.getConnection());
    }
    public List<Product> getAllProduct(String type) throws Exception {
        List<Product> list = null;
        try {
            list = this.dao.getAllProduct(type);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return list;
    }
    public Product getProduct(String name) throws Exception {
        Product product = null;
        try {
            product = this.dao.getProduct(name);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return product;
    }
    public List<Product> searchAllProduct(String key) throws Exception {
        List<Product> list = null;
        try {
            list = this.dao.searchAllProduct(key);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
        return list;
    }
    public void deleteProduct(String name) throws Exception {
        try {
            //this.dao.deleteProduct(name);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
    }
    public void updateProduct(int id,String name,int unit,double price,String info) throws Exception {
        try {
            //this.dao.updateProduct(id,name,unit,price,info);
        } catch (Exception e) {
            throw e;
        } finally {
            this.dbc.close();
        }
    }
}
