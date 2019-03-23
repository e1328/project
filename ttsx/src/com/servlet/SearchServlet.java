package com.servlet;

import com.factory.DAOFactory;
import com.vo.Product;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet(name = "SearchServlet")
public class SearchServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String key1 = request.getParameter("key");
        String key2 = new String(key1.getBytes("ISO-8859-1"),"utf-8");
        System.out.println(key1);
        System.out.println(key2);
        try {
            List<Product> list = DAOFactory.getIProductDAOInstance().searchAllProduct(key2);
            System.out.println(list);
            request.setAttribute("list",list);
            request.getRequestDispatcher("search.jsp").forward(request,response);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }
}
