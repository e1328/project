package com.servlet;

import com.factory.DAOFactory;
import com.vo.Product;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "DetailServlet")
public class DetailServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String name = request.getParameter("name");
        System.out.println(name);
        try {
            Product product = DAOFactory.getIProductDAOInstance().getProduct(name);
            System.out.println(product);
            request.setAttribute("product",product);
            request.getRequestDispatcher("detail.jsp").forward(request, response);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
