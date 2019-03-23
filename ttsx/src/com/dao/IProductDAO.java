package com.dao;

import com.vo.Product;
import java.util.List;

public interface IProductDAO {
    public List<Product> getAllProduct(String type) throws Exception;
    public Product getProduct(String name) throws Exception;
    public List<Product> searchAllProduct(String key) throws Exception;
    //public void deleteProduct(String name) throws Exception;
    //public void updateProduct(int id, String name, int unit, double price, String info) throws Exception;
}
